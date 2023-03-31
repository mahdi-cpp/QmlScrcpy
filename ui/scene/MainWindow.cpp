
#include <QQuickView>
#include <QQmlContext>
#include <QFileInfo>

#include "ui/sceneprovider/SceneProvider.h"
#include "ui/service/ServiceManager.h"
#include "Scene.h"

#include "MainWindow.h"
#include "config.h"

MainWindow::MainWindow(QQuickView *parent) : QQuickView(parent = nullptr) {

    qDebug() << "QCoreApplication::applicationDirPath():" << QCoreApplication::applicationDirPath();
    QString str = QCoreApplication::applicationDirPath();
    int index = str.indexOf("/.output");
    QString leftSide = str.left(index);

    Config::getInstance().setProjectPath(leftSide);
    qDebug() << "getProjectPath():" << Config::getInstance().getProjectPath();

    qsc::AdbProcess::setAdbPath(Config::getInstance().getAdbPath());

    m_resourceService = new ResourceService(this);
    ServiceManager::getInstance().setResourceService(m_resourceService); // Register service to our C++ singleton

    m_resourceService->setSerial("192.168.1.171:5555");

    m_webSocket = new WebSocket(8097, true);

    m_broadcast = new Broadcast(); // UDP broadcast to clients can find server data
    m_broadcast->start();

    connect(m_resourceService, &ResourceService::qmlGenerateEvents, this, &MainWindow::qmlGenerateEventsProcess); //Interacting Qml to C++
    connect(m_resourceService, &ResourceService::webSocket, this, &MainWindow::webSocketProcess); //process receive json string

    // Declare/Register all used custom QML elements
    SceneProvider::declareQml();
    Scene::declareQml();
    ResourceService::declareQml();

    QQmlContext *rootContext;
    rootContext = this->rootContext();
    rootContext->setContextProperty("resourceService", m_resourceService); // Also set it to QML root context

    setKeyboardGrabEnabled(true);
    setSource(QUrl("/home/mahdi/CLionProjects/QtScrcpy/res/qml/main.qml"));
    setResizeMode(QQuickView::SizeRootObjectToView);

    connect(&m_adb, &qsc::AdbProcess::adbProcessResult, this, [this](qsc::AdbProcess::ADB_EXEC_RESULT processResult) {
        QString log = "";
        bool newLine = true;
        QStringList args = m_adb.arguments();

        switch (processResult) {
            case qsc::AdbProcess::AER_ERROR_START:
                break;
            case qsc::AdbProcess::AER_SUCCESS_START:
                log = "adb run";
                newLine = false;
                break;
            case qsc::AdbProcess::AER_ERROR_EXEC:
                //log = m_adb.getErrorOut();
                if (args.contains("ifconfig") && args.contains("wlan0")) {
                    getIPbyIp();
                }
                break;
            case qsc::AdbProcess::AER_ERROR_MISSING_BINARY:
                log = "adb not found";
                break;
            case qsc::AdbProcess::AER_SUCCESS_EXEC:
                //log = m_adb.getStdOut();
                if (args.contains("devices")) {
                    QStringList devices = m_adb.getDevicesSerialFromStdOut();
                    //ui->serialBox->clear();
                    //ui->connectedPhoneList->clear();
//                    for (auto &item: devices) {
//                        //ui->serialBox->addItem(item);
//                        //ui->connectedPhoneList->addItem(Config::getInstance().getNickName(item) + "-" + item);
//                    }
                } else if (args.contains("show") && args.contains("wlan0")) {
                    QString ip = m_adb.getDeviceIPFromStdOut();
                    if (ip.isEmpty()) {
                        log = "ip not find, connect to wifi?";
                        break;
                    }
                    //ui->deviceIpEdt->setText(ip);
                } else if (args.contains("ifconfig") && args.contains("wlan0")) {
                    QString ip = m_adb.getDeviceIPFromStdOut();
                    if (ip.isEmpty()) {
                        log = "ip not find, connect to wifi?";
                        break;
                    }
                    //ui->deviceIpEdt->setText(ip);
                } else if (args.contains("ip -o a")) {
                    QString ip = m_adb.getDeviceIPByIpFromStdOut();
                    if (ip.isEmpty()) {
                        log = "ip not find, connect to wifi?";
                        break;
                    }
                    //ui->deviceIpEdt->setText(ip);
                }
                break;
        }
        if (!log.isEmpty()) {
            outLog(log, newLine);
        }
    });

    emit m_resourceService->cppGenerateEvents("Hello of MainWindow to qml");
}

MainWindow::~MainWindow() {
    qsc::IDeviceManage::getInstance().disconnectAllDevice();
    this->destroy();
}

void MainWindow::webSocketProcess(QString json) {
    //qDebug() << json;

    QByteArray byteArray;
    byteArray.append(json);

    //2. Format the content of the byteArray as QJsonDocument
    //and check on parse Errors
    QJsonParseError parseError;
    QJsonDocument jsonDoc;
    jsonDoc = QJsonDocument::fromJson(byteArray, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Parse error at " << parseError.offset << ":" << parseError.errorString();
        return;
    }

    //3. Create a jsonObject and fill it with the byteArray content, formatted
    //and holding by the jsonDocument Class
    QJsonObject jsonObj;
    jsonObj = jsonDoc.object();

    qDebug() << "nothing:" << jsonObj.value("nothing").toString();
    qDebug() << "id:" << jsonObj.value("id").toString();
    qDebug() << "name:" << jsonObj.value("name").toString();
    qDebug() << "phone:" << jsonObj.value("phone").toString();
    qDebug() << "age:" << jsonObj.value("age").toInt(0);

    m_resourceService->state->Mirror.username = jsonObj.value("name").toString();

    m_webSocket->send(json);
}

void MainWindow::qmlGenerateEventsProcess(QString name) {

    if (name == "REQUEST_MIRROR_START") {
        requestStartMirrir();
    } else if (name == "REQUEST_MIRROR_FINISH") {
        qsc::IDeviceManage::getInstance().disconnectDevice(m_resourceService->serial());
    }
}

void MainWindow::requestStartMirrir() {
    outLog("start server...", false);

    // this is ok that "original" toUshort is 0
    quint16 videoSize = 1080;
    qsc::DeviceParams params;
    params.serial = m_resourceService->serial();
    params.maxSize = videoSize;
    params.bitRate = 2000000;

    // on devices with Android >= 10, the capture frame rate can be limited
    params.maxFps = static_cast<quint32>(Config::getInstance().getMaxFps());
    params.closeScreen = false;
    params.useReverse = true;
    params.display = true;
    params.renderExpiredFrames = false;
    params.lockVideoOrientation = -1;
    params.stayAwake = false;
    params.recordFile = false;
    params.recordPath = "";
    params.recordFileFormat = "mp4";
    params.serverLocalPath = Config::getInstance().getProjectPath() + "/res/scrcpy-server";
    params.serverRemotePath = Config::getInstance().getServerPath();
    params.pushFilePath = Config::getInstance().getPushFilePath();
    params.gameScript = "";
    params.serverVersion = Config::getInstance().getServerVersion();
    params.logLevel = Config::getInstance().getLogLevel();
    params.codecOptions = Config::getInstance().getCodecOptions();
    params.codecName = Config::getInstance().getCodecName();

    connect(&qsc::IDeviceManage::getInstance(), &qsc::IDeviceManage::deviceConnected, this, &MainWindow::onDeviceConnected);
    connect(&qsc::IDeviceManage::getInstance(), &qsc::IDeviceManage::deviceDisconnected, this, &MainWindow::onDeviceDisconnected);

    qsc::IDeviceManage::getInstance().connectDevice(params);

}

void MainWindow::onDeviceConnected(bool success, const QString &serial, const QString &deviceName, const QSize &size) {

    qDebug() << serial << deviceName << size.width();

    if (success) {
        emit m_resourceService->cppGenerateEvents("MIRROR_START");
    }
}

void MainWindow::onDeviceDisconnected(QString serial) {
    emit m_resourceService->cppGenerateEvents("MIRROR_FINISHED");
    qDebug() << "MainWindow::onDeviceDisconnected:" << serial;
}

void MainWindow::getIPbyIp() {
    if (checkAdbRun()) {
        return;
    }

    QStringList adbArgs;
    adbArgs << "shell";
    adbArgs << "ip -o a";

    m_adb.execute(m_resourceService->serial(), adbArgs);
}

bool MainWindow::checkAdbRun() {
    if (m_adb.isRuning()) {
        qDebug() << "wait for the end of the current command to run";
    }
    return m_adb.isRuning();
}

void MainWindow::wifiConnect() {

//    on_stopAllServerBtn_clicked();
//    delayMs(200);
//
//    on_updateDevice_clicked();
//    delayMs(200);
//
//    int firstUsbDevice = findDeviceFromeSerialBox(false);
//    if (-1 == firstUsbDevice) {
//        qWarning() << "No use device is found!";
//        return;
//    }
//    ui->serialBox->setCurrentIndex(firstUsbDevice);
//
//    on_getIPBtn_clicked();
//    delayMs(200);
//
//    on_startAdbdBtn_clicked();
//    delayMs(1000);
//
//    on_wirelessConnectBtn_clicked();
//    delayMs(2000);
//
//    on_updateDevice_clicked();
//    delayMs(200);
//
//    int firstWifiDevice = findDeviceFromeSerialBox(true);
//    if (-1 == firstWifiDevice) {
//        qWarning() << "No wifi device is found!";
//        return;
//    }
//    ui->serialBox->setCurrentIndex(firstWifiDevice);

    //on_startServerBtn_clicked();
}

void MainWindow::test(QString name) {
    qDebug() << "MainWindow:" << name;
}

void MainWindow::outLog(const QString &log, bool newLine) {
    qDebug() << "MainWindow:" << log << newLine;

    // avoid sub thread update ui
//    QString backLog = log;
//    QTimer::singleShot(0, this, [this, backLog, newLine]() {
//        //ui->outEdit->append(backLog);
//        if (newLine) {
//            //ui->outEdit->append("<br/>");
//        }
//    });
}

void MainWindow::delayMs(int ms) {
    QTime dieTime = QTime::currentTime().addMSecs(ms);

    while (QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    qDebug() << "keyPressEvent";

    auto device = qsc::IDeviceManage::getInstance().getDevice(m_resourceService->serial());
    if (!device) {
        return;
    }

    if (m_resourceService->orientation() == 0)
            emit device->keyEvent(event, m_resourceService->frameSize(), m_resourceService->portraitSize());
    else
            emit device->keyEvent(event, m_resourceService->frameSize(), m_resourceService->landscapeSize());
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {

    auto device = qsc::IDeviceManage::getInstance().getDevice(m_resourceService->serial());
    if (!device) {
        return;
    }

    if (m_resourceService->orientation() == 0)
            emit device->keyEvent(event, m_resourceService->frameSize(), m_resourceService->portraitSize());
    else
            emit device->keyEvent(event, m_resourceService->frameSize(), m_resourceService->landscapeSize());
}

