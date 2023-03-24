#pragma once

#include <QQuickFramebufferObject>
#include <QTimer>

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
};
