#ifndef QTSCRCPY_MAINWINDOW_H
#define QTSCRCPY_MAINWINDOW_H

#include <QPointer>
#include <QPointer>
#include <QTimer>
#include <QTime>
#include <QQuickView>

#include "QtScrcpyCore.h"
#include "adbprocess.h"

#include "ui/service/ResourceService.h"
#include "ui/service/ServiceManager.h"
#include "service/websocket/websocket.h"

class MainWindow : public QQuickView{

public:
    MainWindow(QQuickView *parent = nullptr);
    ~MainWindow();

    Q_INVOKABLE void test(QString name);


protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    void getIPbyIp();
    bool checkAdbRun();
    void delayMs(int ms);
    void outLog(const QString &log, bool newLine = true);
    const QString &getServerPath();

    void requestStartMirrir();
    void wifiConnect();

    QPointer<WebSocket> m_echo_server;

private slots:
    void onDeviceConnected(bool success, const QString& serial, const QString& deviceName, const QSize& size);
    void onDeviceDisconnected(QString serial);
    void qmlGenerateEventsProcess(QString name);

private:
    ResourceService* m_resourceService = nullptr;

    qsc::AdbProcess m_adb;
    QTimer m_autoUpdatetimer;

};


#endif //QTSCRCPY_MAINWINDOW_H
