
#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include <QTimer>

#include <QtNetwork>
#include <QUdpSocket>

class Broadcast : public QObject
{
    Q_OBJECT

public:
    explicit Broadcast(QObject *parent = nullptr);

    void start();
    void stop();

private slots:
    void broadcastDatagram();

private:
    QUdpSocket *udpSocket = nullptr;
    QTimer timer;
    int messageNo = 1;
};

#endif
