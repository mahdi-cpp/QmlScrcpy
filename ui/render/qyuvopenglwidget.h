#ifndef QYUVOPENGLWIDGET_H
#define QYUVOPENGLWIDGET_H

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>

class QYUVOpenGLWidget: public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit QYUVOpenGLWidget(QWidget *parent = nullptr);
    virtual ~QYUVOpenGLWidget() override;

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    void setFrameSize(const QSize &frameSize);
    const QSize &frameSize();
    void updateTextures(quint8 *dataY, quint8 *dataU, quint8 *dataV, quint32 linesizeY, quint32 linesizeU, quint32 linesizeV);

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

private:
    void updateTexture(GLuint texture, quint32 textureType, quint8 *pixels, quint32 stride);
    void initShader();
    void initTextures();
    void deInitTextures();

private:
    // Video frame size
    QSize m_frameSize = { -1, -1 };
    bool m_needUpdate = false;
    bool m_textureInited = false;

    // Vertex Buffer Objects (VBO): the default is VertexBuffer (GL_ARRAY_BUFFER) type
    QOpenGLBuffer m_vbo;

    // Shader program: compile linked shaders
    QOpenGLShaderProgram m_program;

    // YUV textures for generating texture maps
    GLuint m_texture[3] = { 0 };
};

#endif // QYUVOPENGLWIDGET_H
