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

    //void setClients(QString jsonString);

signals:
    void closed();

private slots:
    void onNewConnection();
    void socketDisconnected();
    //void textMessageReceived(QString jsonString);
    void clientRequest(QString jsonString);

    void qmlEvents(QString command, QString data);

    void onDeviceConnected(bool success, const QString& serial, const QString& deviceName, const QSize& size);
    void onDeviceDisconnected(QString serial);

private:
    void response(int result);
    void requestMirrorStart();

private:
    bool checkAdbRun();
    void execute(const QString &serial, const QStringList &args);
    QJsonObject createJsonObject(QString jsonString);

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;
    ResourceService* resourceService = nullptr;
    bool m_debug;
    qsc::AdbProcess m_adb;
};

#endif //ECHOSERVER_H