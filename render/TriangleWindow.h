#ifndef QTSCRCPY_TRIANGLEWINDOW_H
#define QTSCRCPY_TRIANGLEWINDOW_H

#include <QOpenGLBuffer>

#include "OpenGLWindow.h"
#include "QOpenGLShaderProgram"

#include "../core/include/QtScrcpyCore.h"

class TriangleWindow : public OpenGLWindow, public qsc::DeviceObserver
{
public:
    TriangleWindow();
    virtual ~TriangleWindow() override;

    void setFrameSize(const QSize &frameSize);
    const QSize &frameSize();

    void updateTextures(quint8 *dataY, quint8 *dataU, quint8 *dataV, quint32 linesizeY, quint32 linesizeU, quint32 linesizeV);

    void initialize() override;
    void render() override;

private:
    void onFrame(int width, int height, uint8_t* dataY, uint8_t* dataU, uint8_t* dataV, int linesizeY, int linesizeU, int linesizeV) override;
    void initShader();
    void initTextures();
    void deInitTextures();
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

    // YUV textures for generating texture maps
    GLuint m_texture[3] = { 0 };
};


#endif //QTSCRCPY_TRIANGLEWINDOW_H
