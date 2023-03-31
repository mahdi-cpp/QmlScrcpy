#include <QCoreApplication>

#include "qyuvopenglwidget.h"

// store vertex coordinates and texture coordinates
// cached together in the vbo
// Use glVertexAttribPointer to specify the access method
static const GLfloat coordinate[] = {
        // Vertex coordinates, store 4 xyz coordinates
        // The coordinate range is [-1,1], and the center point is 0,0
        // 2D image z is always 0
        // How GL_TRIANGLE_STRIP is drawn：
        // Draw a triangle using the first 3 coordinates and a triangle using the last 3 coordinates, exactly a rectangle
        // x     y     z
        -1.0f,
        -1.0f,
        0.0f,
        1.0f,
        -1.0f,
        0.0f,
        -1.0f,
        1.0f,
        0.0f,
        1.0f,
        1.0f,
        0.0f,

        // Texture coordinates, store 4 xy coordinates
        // The coordinate range is [0,1], and the lower left corner is 0,0
        0.0f,
        1.0f,
        1.0f,
        1.0f,
        0.0f,
        0.0f,
        1.0f,
        0.0f
};

// vertex shader
static const QString s_vertShader = R"(
    attribute vec3 vertexIn;    // xyz vertex coordinates
    attribute vec2 textureIn;   // xy texture coordinates
    varying vec2 textureOut;    // Texture coordinates passed to the fragment shader
    void main(void)
    {
        gl_Position = vec4(vertexIn, 1.0);  // 1.0 means vertexIn is a vertex position
        textureOut = textureIn; // Texture coordinates are passed directly to the fragment shader
    }
)";

// fragment shader
static QString s_fragShader = R"(
    varying vec2 textureOut;        // Texture coordinates passed by the vertex shader
    uniform sampler2D textureY;     // uniform Texture unit, using texture unit can use multiple textures
    uniform sampler2D textureU;     // sampler2D is a 2D sampler
    uniform sampler2D textureV;     // Declare yuv three texture units
    void main(void)
    {
        vec3 yuv;
        vec3 rgb;

        // SDL2 BT709_SHADER_CONSTANTS
        // https://github.com/spurious/SDL-Mirror/blob/4ddd4c445aa059bb127e101b74a8c5b59257fbe2/src/render/opengl/SDL_shaders_gl.c#L102
        const vec3 Rcoeff = vec3(1.1644,  0.000,  1.7927);
        const vec3 Gcoeff = vec3(1.1644, -0.2132, -0.5329);
        const vec3 Bcoeff = vec3(1.1644,  2.1124,  0.000);

        // Sampling according to the specified texture textureY and coordinate textureOut
        yuv.x = texture2D(textureY, textureOut).r;
        yuv.y = texture2D(textureU, textureOut).r - 0.5;
        yuv.z = texture2D(textureV, textureOut).r - 0.5;

        // Convert to rgb after sampling
        // reduce some brightness
        yuv.x = yuv.x - 0.0625;
        rgb.r = dot(yuv, Rcoeff);
        rgb.g = dot(yuv, Gcoeff);
        rgb.b = dot(yuv, Bcoeff);
        // output color value
        gl_FragColor = vec4(rgb, 1.0);
    }
)";

QYUVOpenGLWidget::QYUVOpenGLWidget(QWidget *parent) : QOpenGLWidget(parent) {

}

QYUVOpenGLWidget::~QYUVOpenGLWidget() {
    makeCurrent();
    m_vbo.destroy();
    deInitTextures();
    doneCurrent();
}

QSize QYUVOpenGLWidget::minimumSizeHint() const {
    return QSize(50, 50);
}

QSize QYUVOpenGLWidget::sizeHint() const {
    return size();
}

void QYUVOpenGLWidget::setFrameSize(const QSize &frameSize) {
    if (m_frameSize != frameSize) {
        m_frameSize = frameSize;
        m_needUpdate = true;
        // init texture immediately
        repaint();
    }
}

const QSize &QYUVOpenGLWidget::frameSize() {
    return m_frameSize;
}
void QYUVOpenGLWidget::initializeGL() {

    initializeOpenGLFunctions();
    glDisable(GL_DEPTH_TEST);

    // Vertex buffer object initialization
    m_vbo.create();
    m_vbo.bind();
    m_vbo.allocate(coordinate, sizeof(coordinate));

    initShader();
    // Set background cleanup color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // clean up color background
    glClear(GL_COLOR_BUFFER_BIT);
}

void QYUVOpenGLWidget::updateTextures(quint8 *dataY, quint8 *dataU, quint8 *dataV, quint32 linesizeY, quint32 linesizeU, quint32 linesizeV) {
    if (m_textureInited) {
        updateTexture(m_texture[0], 0, dataY, linesizeY);
        updateTexture(m_texture[1], 1, dataU, linesizeU);
        updateTexture(m_texture[2], 2, dataV, linesizeV);
        update();
    }
}

void QYUVOpenGLWidget::paintGL() {

    if (m_needUpdate) {
        deInitTextures();
        initTextures();
        m_needUpdate = false;
    }

    if (m_textureInited) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_texture[0]);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, m_texture[1]);

        glActiveTexture(GL_TEXTURE2);
        glBindTexture(GL_TEXTURE_2D, m_texture[2]);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
}


void QYUVOpenGLWidget::updateTexture(GLuint texture, quint32 textureType, quint8 *pixels, quint32 stride) {
    if (!pixels)
        return;

    QSize size = 0 == textureType ? m_frameSize : m_frameSize / 2;

    makeCurrent();

    glBindTexture(GL_TEXTURE_2D, texture);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, static_cast<GLint>(stride));
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, size.width(), size.height(), GL_LUMINANCE, GL_UNSIGNED_BYTE, pixels);

    doneCurrent();

}
void QYUVOpenGLWidget::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);
    repaint();
}

void QYUVOpenGLWidget::initShader() {

    // The float, int, etc. of opengles need to manually specify the precision
    if (QCoreApplication::testAttribute(Qt::AA_UseOpenGLES)) {
        s_fragShader.prepend(R"(
                             precision mediump int;
                             precision mediump float;
                             )");
    }
    m_program.addShaderFromSourceCode(QOpenGLShader::Vertex, s_vertShader);
    m_program.addShaderFromSourceCode(QOpenGLShader::Fragment, s_fragShader);
    m_program.link();
    m_program.bind();

    // Specify the access method of vertex coordinates in vba

    // Parameter explanation: the parameter name of the vertex coordinates in the shader, the vertex coordinates are float, the starting offset is 0,
    // the vertex coordinate type is vec3, and the stride is 3 floats
    m_program.setAttributeBuffer("vertexIn", GL_FLOAT, 0, 3, 3 * sizeof(float));
    // Enable vertex attributes
    m_program.enableAttributeArray("vertexIn");

    // Specify how texture coordinates are accessed in vbo
    // Parameter explanation: the parameter name of the texture coordinate in the shader, the texture coordinate is float,
    // the starting offset is 12 float (skip the 12 vertex coordinates stored earlier),
    // the texture coordinate type is vec2, and the stride is 2 float
    m_program.setAttributeBuffer("textureIn", GL_FLOAT, 12 * sizeof(float), 2, 2 * sizeof(float));
    m_program.enableAttributeArray("textureIn");

    //Associate the texture unit in the fragment shader with the texture unit in opengl (opengl generally provides 16 texture units)
    m_program.setUniformValue("textureY", 0);
    m_program.setUniformValue("textureU", 1);
    m_program.setUniformValue("textureV", 2);
}

void QYUVOpenGLWidget::initTextures() {

    // create texture
    glGenTextures(1, &m_texture[0]);
    glBindTexture(GL_TEXTURE_2D, m_texture[0]);
    // Strategy when setting texture scaling
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Set the display strategy when the texture exceeds the coordinates in the st direction
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, m_frameSize.width(), m_frameSize.height(), 0, GL_LUMINANCE,GL_UNSIGNED_BYTE, nullptr);

    glGenTextures(1, &m_texture[1]);
    glBindTexture(GL_TEXTURE_2D, m_texture[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, m_frameSize.width() / 2, m_frameSize.height() / 2, 0, GL_LUMINANCE,GL_UNSIGNED_BYTE, nullptr);

    glGenTextures(1, &m_texture[2]);
    glBindTexture(GL_TEXTURE_2D, m_texture[2]);
    // Strategy when setting texture scaling
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Set the display strategy when the texture exceeds the coordinates in the st direction
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, m_frameSize.width() / 2, m_frameSize.height() / 2, 0, GL_LUMINANCE,GL_UNSIGNED_BYTE, nullptr);

    m_textureInited = true;
}

void QYUVOpenGLWidget::deInitTextures() {

    if (QOpenGLFunctions::isInitialized(QOpenGLFunctions::d_ptr)) {
        glDeleteTextures(3, m_texture);
    }

    memset(m_texture, 0, sizeof(m_texture));
    m_textureInited = false;
}


