#pragma once

#include "QtWs2022/service/ResourceService.h"
#include "QtScrcpyCore.h"

#include <QMatrix4x4>
#include <QObject>
#include <QOpenGLBuffer>
#include <QOpenGLFramebufferObject>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLVertexArrayObject>
#include <QQuickWindow>

//!
//! \brief The BackgroundRenderRenderer class
//! This class does the actual rendering directed by SceneProvider on the render thread
//!

class SceneProviderRenderer : public QObject, public QOpenGLFunctions , public qsc::DeviceObserver{
    Q_OBJECT
public:
    explicit SceneProviderRenderer(QObject* parent = nullptr);
    ~SceneProviderRenderer();

    QOpenGLFramebufferObject* scene() const;

public slots:
    void init(QQuickWindow* window, const QSize& resolution);
    //void setupRendering();
    void synchronize();
    void render();
    void cleanup();

private slots:
    void onFrame(int width, int height, uint8_t* dataY, uint8_t* dataU, uint8_t* dataV, int linesizeY, int linesizeU, int linesizeV);

private:

    void initialize();
    void initShader();
    void initTextures();
    void deInitTextures();

    void setFrameSize(const QSize &frameSize);
    const QSize &frameSize();

    void updateTextures(quint8 *dataY, quint8 *dataU, quint8 *dataV, quint32 linesizeY, quint32 linesizeU, quint32 linesizeV);
    void updateTexture(GLuint texture, quint32 textureType, quint8 *pixels, quint32 stride);

private:
    // Here we will store all the rendered framebuffers, for this demo, we will just store one
    // But BackgroundRenderRender can be easily extended to render many scenes
    QOpenGLFramebufferObject* m_scene = nullptr;

    QOpenGLTexture* m_texture_photo       = nullptr;

    // Video frame size
    QSize m_frameSize = { -1, -1 };
    bool m_needUpdate = false;
    bool m_textureInited = false;

    QOpenGLVertexArrayObject* m_vao = nullptr;
    // Vertex Buffer Objects (VBO): the default is VertexBuffer (GL_ARRAY_BUFFER) type
    QOpenGLBuffer* m_vertexBuffer;
//
//    // Shader program: compile linked shaders
    QOpenGLShaderProgram* m_program;

    // YUV textures for generating texture maps
    GLuint m_texture[3] = { 0 };

    QQuickWindow* m_window = nullptr;

    ResourceService* m_resourceService = nullptr;
};


