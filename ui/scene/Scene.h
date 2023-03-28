#pragma once

#include <QQuickFramebufferObject>
#include <QTimer>

#include <QPointer>
#include "ui/service/ResourceService.h"
#include "ui/service/ServiceManager.h"

//!
//! \brief The Scene class
//! A simple Framebuffer object which will render the saved framebuffer from SceneProvider
//! Scene will live on MainThread
//!

class Scene : public QQuickFramebufferObject {

Q_OBJECT

public:
    explicit Scene(QQuickItem *parent = nullptr);

    static void declareQml();

    virtual Renderer *createRenderer() const override;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;


private slots:
    void onDeviceConnected(bool success, const QString& serial, const QString& deviceName, const QSize& size);
    void onDeviceDisconnected(QString serial);

private:
    QTimer m_timer;

    void mouseProcess(QMouseEvent *event);

    ResourceService* m_resourceService = nullptr;

};
