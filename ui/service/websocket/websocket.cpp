#include "websocket.h"

WebSocket::WebSocket(quint16 port, bool debug, QObject *parent) :QObject(parent),
        m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Echo Server"), QWebSocketServer::NonSecureMode, this)),
        m_debug(debug) {

    m_resourceService = ServiceManager::getInstance().resourceService();

    if (m_pWebSocketServer->listen(QHostAddress::Any, port)) {
        if (m_debug)
            qDebug() << "WebSocket listening on port" << port;

        connect(m_pWebSocketServer, &QWebSocketServer::newConnection, this, &WebSocket::onNewConnection);
        connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &WebSocket::closed);
    }
}

WebSocket::~WebSocket() {
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

void WebSocket::onNewConnection() {

    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::disconnected, this, &WebSocket::socketDisconnected);
    connect(pSocket, &QWebSocket::textMessageReceived, this, &WebSocket::processTextMessage);
    qDebug() << "WebSocket: onNewConnection:" << pSocket->peerAddress();

    m_clients << pSocket;

    //m_resourceService->state->Mirror.;
    // Send Current Status
    pSocket->sendTextMessage(m_resourceService->getStateJsonString());

}

void WebSocket::socketDisconnected() {
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());

    if (m_debug)
        qDebug() << "WebSocket: Socket Disconnected:" << pClient->peerAddress();

    if (pClient) {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}

void WebSocket::processTextMessage(QString message) {
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "Message received:" << pClient->peerAddress();

    if (pClient) {
        pClient->sendTextMessage("ok : " + message);
    }

    emit m_resourceService->webSocket(message);
}

void WebSocket::send(QString message) {

//    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
//
//    qDebug() << message;
//
//    if (pClient) {
//        pClient->sendTextMessage(message);
//    }

    QWebSocket *pSender = qobject_cast<QWebSocket *>(sender());
    Q_UNUSED(pSender);

    for (QWebSocket *pClient : qAsConst(m_clients)) {
        //if (pClient != pSender) //don't echo message back to sender
            pClient->sendTextMessage(message);
    }
}


