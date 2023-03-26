#pragma once

#include <QQuickFramebufferObject>
#include <QTimer>

#include <QPointer>

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

private:
    QTimer m_timer;

    QString m_serial;
    QSize frameSize;
    QSize showSize;

    void mouseProcess(QMouseEvent *event);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;


private slots:
    void onDeviceConnected(bool success, const QString& serial, const QString& deviceName, const QSize& size);
    void onDeviceDisconnected(QString serial);
};
