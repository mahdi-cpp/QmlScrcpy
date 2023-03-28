#ifndef ECHOSERVER_H
#define ECHOSERVER_H

#include <QObject>
#include <QList>
#include <QDebug>
#include <QByteArray>

#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QtWebSockets>

#include "service/ResourceService.h"
#include "service/ServiceManager.h"

class WebSocket : public QObject
{
Q_OBJECT

public:
    explicit WebSocket(quint16 port, bool debug = true, QObject *parent = Q_NULLPTR);
    ~WebSocket();

signals:
    void closed();

private slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void processBinaryMessage(QByteArray message);
    void socketDisconnected();

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;
    ResourceService* m_resourceService = nullptr;

private:
    bool m_debug;
};

#endif //ECHOSERVER_H