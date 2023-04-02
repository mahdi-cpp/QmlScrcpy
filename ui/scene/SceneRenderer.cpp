#include "SceneRenderer.h"

#include <QDebug>
#include <QOpenGLFramebufferObjectFormat>
#include <QVector2D>

struct VertexData2D {
    QVector2D vertex;
    QVector2D texCoord;
};
Q_DECLARE_TYPEINFO(VertexData2D, Q_PRIMITIVE_TYPE);


SceneRenderer::SceneRenderer() {

    m_resourceService = ServiceManager::getInstance().resourceService();

    initializeOpenGLFunctions();
    setupRendering();
}

void SceneRenderer::render() {

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (m_sceneProviderRenderer) {
        QOpenGLVertexArrayObject::Binder binder(m_vao);
        m_program->bind();

        if(!m_resourceService->getMirror()) {
            glActiveTexture(GL_TEXTURE0);
        }
        //glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_sceneProviderRenderer->scene()->texture());
//        m_program->release();
//
//        //glActiveTexture(GL_TEXTURE0);
//        glClearColor(0, 0, 0, 0);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //glDrawElements(GL_TRIANGLE_STRIP, m_elementBuffer->size(), GL_UNSIGNED_INT, nullptr);

    }
}

QOpenGLFramebufferObject* SceneRenderer::createFramebufferObject(const QSize& size) {
    QOpenGLFramebufferObjectFormat format;
    return new QOpenGLFramebufferObject(size, format);
}

void SceneRenderer::synchronize(QQuickFramebufferObject* object) {
    m_window = object->window();
    m_window->setClearBeforeRendering(false);
    m_window->setTextRenderType(QQuickWindow::NativeTextRendering);

    if (!m_sceneProviderRenderer) {
        m_sceneProviderRenderer = ServiceManager::getInstance().renderer();
    }
}

void SceneRenderer::setupRendering() {

    m_vao           = new QOpenGLVertexArrayObject();
    m_elementBuffer = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    m_vertexBuffer  = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);

    if (!m_vao->create()) {
        qFatal("Couldn't create VAO");
    }

    if (!m_vertexBuffer->create()) {
        qFatal("Couldn't create Vertex Buffer");
    }

    const QVector<VertexData2D> quadVertices = {{{-1.0f, -1.0f}, {0.0f, 1.0f}},
                                                {{-1.0f, 1.0f}, {0.0f, 0.0f}},
                                                {{1.0f, -1.0f}, {1.0f, 1.0f}},
                                                {{1.0f, 1.0f}, {1.0f, 0.0f}}};

    m_vertexBuffer->bind();
    m_vertexBuffer->setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_vertexBuffer->allocate(quadVertices.constData(), quadVertices.size() * static_cast<int>(sizeof(VertexData2D)));

    if (!m_elementBuffer->create()) {
        qFatal("Couldn't create Element Buffer");
    }
    const QVector<unsigned int> quadIndices = {0, 1, 2, 3};
    m_elementBuffer->bind();
    m_elementBuffer->setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_elementBuffer->allocate(quadIndices.constData(), quadIndices.size() * static_cast<int>(sizeof(unsigned int)));

    m_program = new QOpenGLShaderProgram();

    if (!m_program->create()) {
        qFatal("Couldn't create Shader Program");
    }
    if (!m_program->addCacheableShaderFromSourceFile(QOpenGLShader::Vertex, "/home/mahdi/CLionProjects/QmlScrcpy/res/opengl/quad.vsh")) {
        qFatal("Vertex shader compilation failed");
    }
    if (!m_program->addCacheableShaderFromSourceFile(QOpenGLShader::Fragment, "/home/mahdi/CLionProjects/QmlScrcpy/res/opengl/quad.fsh")) {
        qFatal("Fragment shader compilation failed");
    }

    if (!m_program->link()) {
        qFatal("Couldn't link shader program");
    }

    m_program->bind();

    QOpenGLVertexArrayObject::Binder binder(m_vao);
    m_vertexBuffer->bind();
    m_program->enableAttributeArray("verCoord");
    m_program->setAttributeBuffer("verCoord", GL_FLOAT, 0, 2, sizeof(VertexData2D));

    m_program->enableAttributeArray("texCoord");
    m_program->setAttributeBuffer("texCoord", GL_FLOAT, sizeof(QVector2D), 2, sizeof(VertexData2D));

    m_elementBuffer->bind();

    m_program->release();
}
