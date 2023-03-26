
#pragma once

#include "QtWs2022/sceneprovider/SceneProviderRenderer.h"

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QQuickFramebufferObject>
#include <QQuickWindow>

//!
//! \brief The SceneRenderer class
//! SceneRenderer will live on RenderThread
//!
class SceneRenderer : public QQuickFramebufferObject::Renderer, public QOpenGLFunctions {
    Q_DISABLE_COPY(SceneRenderer)
public:
    SceneRenderer();

    virtual void render() override;
    virtual QOpenGLFramebufferObject* createFramebufferObject(const QSize& size) override;
    virtual void synchronize(QQuickFramebufferObject*) override;

private:
    void setupRendering();

private:
    QQuickWindow* m_window = nullptr;

    SceneProviderRenderer* m_sceneProviderRenderer = nullptr;

    QOpenGLBuffer* m_vertexBuffer   = nullptr;
    QOpenGLBuffer* m_elementBuffer  = nullptr;
    QOpenGLShaderProgram* m_program = nullptr;
    QOpenGLVertexArrayObject* m_vao = nullptr;

    ResourceService* m_resourceService = nullptr;
};
