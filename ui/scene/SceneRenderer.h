
#pragma once

#include "ui/sceneprovider/SceneProviderRenderer.h"

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QQuickFramebufferObject>
#include <QQuickWindow>

#include "ui/service/ResourceService.h"
#include "ui/service/ServiceManager.h"

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
    ResourceService* m_resourceService = nullptr;

    QOpenGLBuffer* m_vertexBuffer   = nullptr;
    QOpenGLBuffer* m_elementBuffer  = nullptr;
    QOpenGLShaderProgram* m_program = nullptr;
    QOpenGLVertexArrayObject* m_vao = nullptr;


};
