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

    connect(pSocket, &QWebSocket::textMessageReceived, this, &WebSocket::processTextMessage);
    connect(pSocket, &QWebSocket::binaryMessageReceived, this, &WebSocket::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &WebSocket::socketDisconnected);

    m_clients << pSocket;
}

void WebSocket::processTextMessage(QString message) {
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "Message received:" << message;
    if (pClient) {
        pClient->sendTextMessage("ok : " + message);
        emit m_resourceService->webSocket("MUSIC", message);
    }
}

void WebSocket::processBinaryMessage(QByteArray message) {
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "Binary Message received:" << message;
    if (pClient) {
        pClient->sendBinaryMessage(message);
    }
}

void WebSocket::socketDisconnected() {
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "WebSocket: Socket Disconnected:" << pClient;
    if (pClient) {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}