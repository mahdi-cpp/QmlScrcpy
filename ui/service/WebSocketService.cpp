#include "WebSocketService.h"

WebSocketService::WebSocketService(quint16 port, bool debug, QObject *parent) :QObject(parent),
        m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Echo Server"), QWebSocketServer::NonSecureMode, this)),
        m_debug(debug) {

    m_resourceService = ServiceManager::getInstance().resourceService();

    if (m_pWebSocketServer->listen(QHostAddress::Any, port)) {
        if (m_debug)
            qDebug() << "WebSocket listening on port" << port;

        connect(m_pWebSocketServer, &QWebSocketServer::newConnection, this, &WebSocketService::onNewConnection);
        connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &WebSocketService::closed);
    }
}

WebSocketService::~WebSocketService() {
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

void WebSocketService::onNewConnection() {

    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::disconnected, this, &WebSocketService::socketDisconnected);
    connect(pSocket, &QWebSocket::textMessageReceived, this, &WebSocketService::textMessageReceived);
    qDebug() << "WebSocket: onNewConnection:" << pSocket->peerAddress();

    m_clients << pSocket;

    //m_resourceService->mirror->Mirror.;
    // Send Current Status
    pSocket->sendTextMessage(m_resourceService->getStateJson());

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

void WebSocketService::textMessageReceived(QString jsonString) {
    //QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
//    if (m_debug)
//        qDebug() << "Message received:" << pClient->peerAddress();

    if (m_debug)
        qDebug() << "Message received:";

//    if (pClient) {
//        pClient->sendTextMessage(jsonString);
//    }

//    for (QWebSocket *pClient : qAsConst(m_clients)) {
//        pClient->sendTextMessage(m_resourceService->getStateJson());
//    }

    //emit m_resourceService->webSocketMessageReceived(jsonString);

    m_resourceService->webSocketMessageReceived(jsonString);
}

void WebSocketService::setClients(QString( jsonString)) {

//    QWebSocket *pSender = qobject_cast<QWebSocket *>(sender());
//    Q_UNUSED(pSender);

    for (QWebSocket *pClient : qAsConst(m_clients)) {
        pClient->sendTextMessage(jsonString);
    }
}


