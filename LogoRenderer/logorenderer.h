#ifndef LOGORENDERER_H
#define LOGORENDERER_H

#include <QtGui/qvector3d.h>
#include <QtGui/qmatrix4x4.h>
#include <QtGui/qopenglshaderprogram.h>
#include <QtGui/qopenglfunctions.h>

#include <QTime>
#include <QVector>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

class LogoRenderer : public QObject, protected QOpenGLFunctions
{
public:
    LogoRenderer();
    ~LogoRenderer();

    void onFrame(int width, int height, uint8_t* dataY, uint8_t* dataU, uint8_t* dataV, int linesizeY, int linesizeU, int linesizeV);
    void render();
    void initialize();

private:
    void initShader();
    void initTextures();
    void deInitTextures();

    void setFrameSize(const QSize &frameSize);
    const QSize &frameSize();

    void updateTextures(quint8 *dataY, quint8 *dataU, quint8 *dataV, quint32 linesizeY, quint32 linesizeU, quint32 linesizeV);
    void updateTexture(GLuint texture, quint32 textureType, quint8 *pixels, quint32 stride);

private:
    // Video frame size
    QSize m_frameSize = { -1, -1 };
    bool m_needUpdate = false;
    bool m_textureInited = false;

    // Vertex Buffer Objects (VBO): the default is VertexBuffer (GL_ARRAY_BUFFER) type
    QOpenGLBuffer m_vertexBuffer;

    // Shader program: compile linked shaders
    QOpenGLShaderProgram m_program;

    QOpenGLVertexArrayObject* m_vao = nullptr;

    // YUV textures for generating texture maps
    GLuint m_texture[3] = { 0 };
};
#endif
