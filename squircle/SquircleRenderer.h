
#ifndef QTSCRCPY_SQUIRCLERENDERER_H
#define QTSCRCPY_SQUIRCLERENDERER_H

#include <QtQuick/QQuickItem>

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

#include "../core/include/QtScrcpyCore.h"

class SquircleRenderer : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    SquircleRenderer();
    ~SquircleRenderer();

//    void setT(qreal t) { m_t = t; }
//    void setViewportSize(const QSize &size) { m_viewportSize = size; }
    void setWindow(QQuickWindow *window) { m_window = window; }

    void setFrameSize(const QSize &frameSize);
    const QSize &frameSize();
    void updateTextures(quint8 *dataY, quint8 *dataU, quint8 *dataV, quint32 linesizeY, quint32 linesizeU, quint32 linesizeV);

public slots:
    void paint();
private slots:
    void onFrame(int width, int height, uint8_t* dataY, uint8_t* dataU, uint8_t* dataV, int linesizeY, int linesizeU, int linesizeV);


private:
    void initialize();
    void initShader();
    void initTextures();
    void deInitTextures();
    void updateTexture(GLuint texture, quint32 textureType, quint8 *pixels, quint32 stride);

private:
//    QSize m_viewportSize;
//    qreal m_t;
//    QOpenGLShaderProgram *m_program;
    QQuickWindow *m_window;

    // Video frame size
    QSize m_frameSize = { -1, -1 };
    bool m_needUpdate = false;
    bool m_textureInited = false;

    // Vertex Buffer Objects (VBO): the default is VertexBuffer (GL_ARRAY_BUFFER) type
    QOpenGLBuffer m_vbo;

    // Shader program: compile linked shaders
    QOpenGLShaderProgram m_shaderProgram;

    // YUV textures for generating texture maps
    GLuint m_texture[3] = { 0 };
};


#endif //QTSCRCPY_SQUIRCLERENDERER_H
