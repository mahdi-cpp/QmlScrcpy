
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

    //m_resourceService->setSerial("192.168.1.171:5555");
    //m_resourceService->setSerial("4793be90");

    m_broadcast = new Broadcast(); // UDP broadcast to clients can find server data
    m_broadcast->start();

    m_webSocketService = new WebSocketService(8097, true, this);

    connect(m_resourceService, &ResourceService::qmlEvents, this, &MainWindow::qmlEvents); //Interacting Qml to C++
    connect(m_resourceService, &ResourceService::androidEvents, this, &MainWindow::androidEvents); //Reacive command of Android

    //connect(m_resourceService, &ResourceService::webSocketMessageReceived, this, &MainWindow::webSocketMessageReceived); //process receive json string

    // Declare/Register all used custom QML elements
    SceneProvider::declareQml();
    Scene::declareQml();
    ResourceService::declareQml();

    QQmlContext *rootContext;
    rootContext = this->rootContext();
    rootContext->setContextProperty("resourceService", m_resourceService); // Also set it to QML root context

    setKeyboardGrabEnabled(true);
    setSource(QUrl("/home/mahdi/CLionProjects/QmlScrcpy/res/qml/main.qml"));
    setResizeMode(QQuickView::SizeRootObjectToView);

    connect(&m_adb, &qsc::AdbProcess::adbProcessResult, this, [this](qsc::AdbProcess::ADB_EXEC_RESULT processResult) {

        QString log = "";
        //bool newLine = true;
        QStringList args = m_adb.arguments();

        switch (processResult) {
            case qsc::AdbProcess::AER_ERROR_START:
                break;
            case qsc::AdbProcess::AER_SUCCESS_START:
                log = "adb run";
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

                    for (auto &item: devices) {
                        if (item.contains(":") || item.contains(".")) { //Ignore if device is Wi-Fi
                            continue;
                        }
                        emit m_resourceService->usbDeviceName(item);
                        return;
                    }
                    emit m_resourceService->usbDeviceName("");
                }
                break;
        }
    });

    emit m_resourceService->cppGenerateEvents("Hello of MainWindow to qml");
}

MainWindow::~MainWindow() {
    qsc::IDeviceManage::getInstance().disconnectAllDevice();
    this->destroy();
}

void MainWindow::androidEvents(QString command, QString data) {
    Q_UNUSED(data);

    if (command == "REQUEST_MIRROR_START") {
        m_resourceService->setSerial(m_resourceService->mirror->wifIp);
        requestMirrorStart();
    }
}

void MainWindow::qmlEvents(QString command, QString data) {

    if (command == "REQUEST_MIRROR_START") {
        m_resourceService->setSerial(data);
        m_resourceService->setUsbMirrorParametre(data);
        requestMirrorStart();
    } else if (command == "REQUEST_MIRROR_FINISH") {
        qsc::IDeviceManage::getInstance().disconnectDevice(m_resourceService->serial());
        m_resourceService->stopMirror();
    } else if (command == "REQUEST_DEVICES_LIST") {
        if (checkAdbRun()) {
            return;
        }
        qDebug() << "command:adb devices";
        m_adb.execute("", QStringList() << "devices");
    }
}

void MainWindow::requestMirrorStart() {

    qDebug() << "MainWindow::requestMirrorStart()";

    qsc::IDeviceManage::getInstance().disconnectAllDevice();

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

        //notification to users for start mirroring
        m_webSocketService->setClients(m_resourceService->getStateJson());

        emit m_resourceService->cppGenerateEvents("MIRROR_START");
    }
}

void MainWindow::onDeviceDisconnected(QString serial) {

    m_resourceService->stopMirror();
    m_webSocketService->setClients(m_resourceService->getStateJson());
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
    Q_UNUSED(newLine);
    qDebug() << "MainWindow:" << log;

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

