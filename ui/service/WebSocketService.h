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

class WebSocketService : public QObject
{
Q_OBJECT

public:
    explicit WebSocketService(quint16 port, bool debug = true, QObject *parent = Q_NULLPTR);
    ~WebSocketService();

    void setClients(QString jsonString);

signals:
    void closed();

private slots:
    void onNewConnection();
    void socketDisconnected();
    void textMessageReceived(QString jsonString);

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;

    ResourceService* m_resourceService = nullptr;

private:
    bool m_debug;
};

#endif //ECHOSERVER_H