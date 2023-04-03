#include "WebSocketService.h"
#include "service/include/server.h"
#include "config.h"

WebSocketService::WebSocketService(quint16 port, bool debug, QObject *parent) : QObject(parent),
                                                                                m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Echo Server"),
                                                                                                                        QWebSocketServer::NonSecureMode, this)),
                                                                                m_debug(debug) {

    resourceService = ServiceManager::getInstance().resourceService();

    if (m_pWebSocketServer->listen(QHostAddress::Any, port)) {
        if (m_debug)
            qDebug() << "WebSocket listening on port" << port;

        connect(m_pWebSocketServer, &QWebSocketServer::newConnection, this, &WebSocketService::onNewConnection);
        connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &WebSocketService::closed);
    }

    connect(resourceService, &ResourceService::qmlEvents, this, &WebSocketService::qmlEvents); //Interacting Qml to C++

    connect(&qsc::IDeviceManage::getInstance(), &qsc::IDeviceManage::deviceConnected, this, &WebSocketService::onDeviceConnected);
    connect(&qsc::IDeviceManage::getInstance(), &qsc::IDeviceManage::deviceDisconnected, this, &WebSocketService::onDeviceDisconnected);

    connect(&m_adb, &qsc::AdbProcess::adbProcessResult, this, [this](qsc::AdbProcess::ADB_EXEC_RESULT processResult) {

        QStringList args = m_adb.arguments();

        switch (processResult) {
            case qsc::AdbProcess::AER_ERROR_START:
                response(Server::SERVER_RESPONSE::MIRROR_ERROR_START);
                break;
            case qsc::AdbProcess::AER_SUCCESS_START:
                //log = "adb run";
                break;
            case qsc::AdbProcess::AER_ERROR_EXEC:
                qDebug() << "AdbProcess::AER_ERROR_EXEC";
                response(Server::SERVER_RESPONSE::MIRROR_ERROR_START);
                break;
            case qsc::AdbProcess::AER_ERROR_MISSING_BINARY:
                //log = "adb not found";
                break;
            case qsc::AdbProcess::AER_SUCCESS_EXEC:
                //log = m_adb.getStdOut();
                if (args.contains("devices")) {
                    QStringList devices = m_adb.getDevicesSerialFromStdOut();

                    for (auto &item: devices) {
                        if (item.contains(":") || item.contains(".")) { //Ignore if device is Wi-Fi
                            continue;
                        }
                        emit resourceService->usbDeviceName(item);
                        return;
                    }
                    emit resourceService->usbDeviceName("");
                }
                break;
        }
    });
}

WebSocketService::~WebSocketService() {
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

void WebSocketService::onNewConnection() {

    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::disconnected, this, &WebSocketService::socketDisconnected);
    connect(pSocket, &QWebSocket::textMessageReceived, this, &WebSocketService::clientRequest);
    qDebug() << "WebSocket: onNewConnection:" << pSocket->peerAddress();

    m_clients << pSocket;

    // Send Current Status
    //pSocket->sendTextMessage(resourceService->getStateJson());

}

//void WebSocketService::textMessageReceived(QString jsonString) {

//    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
//    if (m_debug)
//        qDebug() << "Message received:" << pClient->peerAddress();

///    clientRequest(jsonString);

//    if (pClient) {
//        pClient->sendTextMessage(jsonString);
//    }

//    for (QWebSocket *pClient : qAsConst(m_clients)) {
//        pClient->sendTextMessage(resourceService->getStateJson());
//    }

//emit resourceService->clientRequest(jsonString);

//resourceService->clientRequest(jsonString);
//}

//void WebSocketService::setClients(QString( jsonString)) {
//
////    QWebSocket *pSender = qobject_cast<QWebSocket *>(sender());
////    Q_UNUSED(pSender);
//
//    for (QWebSocket *pClient: qAsConst(m_clients)) {
//        pClient->sendTextMessage(jsonString);
//    }
//}

void WebSocketService::clientRequest(QString jsonString) { //receive requests of android clients

    QJsonObject jsonObject = createJsonObject(jsonString);

    int clientRequest = jsonObject.value("clientRequest").toInt();

    if (clientRequest == Server::CLIENT_REQUEST::CLIENT_REQUEST_ADB_CONNECT) {

        QString wifiIp = jsonObject.value("wifiIp").toString();
        QStringList adbArgs;
        adbArgs << "connect";
        adbArgs << wifiIp;
        execute("", adbArgs);

    } else if (clientRequest == Server::CLIENT_REQUEST::CLIENT_REQUEST_UPDATE) {

        response(Server::SERVER_RESPONSE::UPDATE_MIRROR_DATA);

    } else if (clientRequest == Server::CLIENT_REQUEST::CLIENT_REQUEST_MIRROR) {

        resourceService->mirror->wifiIp = jsonObject.value("wifiIp").toString();
        resourceService->mirror->username = jsonObject.value("username").toString();
        resourceService->mirror->title = jsonObject.value("title").toString();
        resourceService->mirror->bitrate = jsonObject.value("bitrate").toString();
        resourceService->mirror->resolution = jsonObject.value("resolution").toString();
        resourceService->mirror->connectionType = jsonObject.value("connectionType").toString();

        resourceService->setSerial(resourceService->mirror->wifiIp);
        requestMirrorStart();

        qDebug() << "";
        qDebug() << "wifIp:" << resourceService->mirror->wifiIp;
        qDebug() << "username:" << resourceService->mirror->username;
        qDebug() << "title:" << resourceService->mirror->title;
        qDebug() << "bitrate:" << resourceService->mirror->bitrate;
        qDebug() << "resolution:" << resourceService->mirror->resolution;
        qDebug() << "connectionType:" << resourceService->mirror->connectionType;
        qDebug() << "";
    }
}

void WebSocketService::response(int result) {

    QJsonObject rootObject;

    rootObject["SERVER_RESPONSE"] = result;

    if (result == Server::SERVER_RESPONSE::MIRROR_SUCCESS_START) {
        //response to clients to update ui
        rootObject["username"] = resourceService->mirror->username;
        rootObject["title"] = resourceService->mirror->title;
        rootObject["bitrate"] = resourceService->mirror->bitrate;
        rootObject["resolution"] = resourceService->mirror->resolution;
        rootObject["connectionType"] = resourceService->mirror->connectionType;

    } else if (result == Server::SERVER_RESPONSE::MIRROR_ERROR_START) {
        // error ocure in adb to start scrcpy-server
        resourceService->clearMirrorCash();
    } else if (result == Server::SERVER_RESPONSE::UPDATE_MIRROR_DATA) {
        if (resourceService->mirror->username.length() > 3) {
            rootObject["username"] = resourceService->mirror->username;
            rootObject["title"] = resourceService->mirror->title;
            rootObject["bitrate"] = resourceService->mirror->bitrate;
            rootObject["resolution"] = resourceService->mirror->resolution;
            rootObject["connectionType"] = resourceService->mirror->connectionType;
        } else{
            rootObject["username"] = "nothing";
        }
    }

    QJsonDocument doc(rootObject);
    QString jsonString(doc.toJson(QJsonDocument::Compact));

    for (QWebSocket *pClient: qAsConst(m_clients)) { // send server response to all androi clients
        pClient->sendTextMessage(jsonString);
    }
}

void WebSocketService::qmlEvents(QString command, QString data) {

    if (command == "REQUEST_MIRROR_START") {
        resourceService->setSerial(data);
        resourceService->setUsbMirrorParametre();
        requestMirrorStart();
    } else if (command == "REQUEST_MIRROR_FINISH") {
        qsc::IDeviceManage::getInstance().disconnectDevice(resourceService->serial());
        response(Server::SERVER_RESPONSE::MIRROR_FINISHED);
    } else if (command == "REQUEST_DEVICES_LIST") {
        if (checkAdbRun()) {
            return;
        }
        qDebug() << "command:adb devices";
        m_adb.execute("", QStringList() << "devices");
    }
}

void WebSocketService::onDeviceConnected(bool success, const QString &serial, const QString &deviceName, const QSize &size) {

    qDebug() << "onDeviceConnected" << serial << deviceName << size.width();

    if (success) {
        response(Server::SERVER_RESPONSE::MIRROR_SUCCESS_START);      // notification to users for start mirroring
        emit resourceService->cppGenerateEvents("MIRROR_START");        // update qml ui
        qDebug() << "onDeviceConnected:" << serial;
    }
}

void WebSocketService::onDeviceDisconnected(QString serial) {

    resourceService->clearMirrorCash();
    emit resourceService->cppGenerateEvents("MIRROR_FINISHED");
    //m_webSocketService->setClients(resourceService->sendCommandToClients(ResourceService::SERVER_RESPONSE::MIRROR_FINISHED));

    qDebug() << "onDeviceDisconnected:" << serial;
}

void WebSocketService::requestMirrorStart() {

    qDebug() << "requestMirrorStart()";

    //qsc::IDeviceManage::getInstance().disconnectAllDevice();

    // this is ok that "original" toUshort is 0
    quint16 videoSize = 1080;
    qsc::DeviceParams params;
    params.serial = resourceService->serial();
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

    qsc::IDeviceManage::getInstance().connectDevice(params);
}

void WebSocketService::socketDisconnected() {

    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

    if (m_debug)
        qDebug() << "WebSocket: Socket Disconnected:" << pClient->peerAddress();

    if (pClient) {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}

//----------------------------------

bool WebSocketService::checkAdbRun() {
    if (m_adb.isRuning()) {
        qDebug() << "wait for the end of the current command to run";
    }
    return m_adb.isRuning();
}

void WebSocketService::execute(const QString &serial, const QStringList &args) {
    m_adb.execute(serial, args);
}

QJsonObject WebSocketService::createJsonObject(QString jsonString) {
    QByteArray byteArray;
    byteArray.append(jsonString);

    //2. Format the content of the byteArray as QJsonDocument
    //and check on parse Errors
    QJsonParseError parseError;
    QJsonDocument jsonDoc;
    jsonDoc = QJsonDocument::fromJson(byteArray, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Parse error at " << parseError.offset << ":" << parseError.errorString();
        //return nullptr_t ;
    }

    //3. Create a jsonObject and fill it with the byteArray content, formatted
    //and holding by the jsonDocument Class
    QJsonObject jsonObj;
    jsonObj = jsonDoc.object();

    return jsonObj;
}
