#include "SceneProviderRenderer.h"

#include "ui/service/ServiceManager.h"
#include "config.h"

#include <QDebug>
#include <QCoreApplication>

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

SceneProviderRenderer::SceneProviderRenderer(QObject *parent) : QObject{parent} {
    initializeOpenGLFunctions();
    initialize();
    connect(&qsc::IDeviceManage::getInstance(), &qsc::IDeviceManage::onNewFrame, this, &SceneProviderRenderer::onFrame);
}

SceneProviderRenderer::~SceneProviderRenderer() {
    cleanup();
    m_vertexBuffer->destroy();
    deInitTextures();
}

QOpenGLFramebufferObject *SceneProviderRenderer::scene() const {
    return m_scene;
}

void SceneProviderRenderer::initialize() {
    glDisable(GL_DEPTH_TEST);

    m_vao = new QOpenGLVertexArrayObject();

    // Vertex buffer object initialization
    m_vertexBuffer = new QOpenGLBuffer(QOpenGLBuffer::Type::VertexBuffer);
    if (!m_vertexBuffer->create()) {
        qFatal("Couldn't create Vertex Buffer");
    }

    m_vertexBuffer->bind();
    m_vertexBuffer->allocate(coordinate, sizeof(coordinate));

    initShader();

    // Set background cleanup color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // clean up color background
    glClear(GL_COLOR_BUFFER_BIT);
}

void SceneProviderRenderer::init(QQuickWindow *window, const QSize &resolution) {
    m_window = window;

    m_resourceService = ServiceManager::getInstance().resourceService();

    //setupRendering();
    m_texture_photo = new QOpenGLTexture(QImage("/home/mahdi/CLionProjects/res/opengl/watermelon.jpg"));

    if (m_scene) {
        if (m_scene->isBound()) {
            m_scene->release();
        }
        delete m_scene;
        m_scene = nullptr;
    }

    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::Attachment::CombinedDepthStencil);
    format.setMipmap(true);
    m_scene = new QOpenGLFramebufferObject(resolution, format);

    ServiceManager::getInstance().addRenderer(this);
}

void SceneProviderRenderer::synchronize() {

//    m_program->bind();
//
//    m_program->release();

}

void SceneProviderRenderer::render() {

    if (m_resourceService->mirror() == false) {
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        return;
    }

    if (!m_scene || !m_program) {
        return;
    }

    m_scene->bind();
    {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        glViewport(0, 0, 400, 900);

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

        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        m_program->bind();
        //m_texture_photo->bind();
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 512, 512, GL_LUMINANCE, GL_UNSIGNED_BYTE, m_texture_photo);
        m_program->release();
    }
    m_scene->release();
}

void SceneProviderRenderer::cleanup() {
    if (m_program) {
        m_program->release();
        m_program->deleteLater();
        m_program = nullptr;
    }
}

void SceneProviderRenderer::setFrameSize(const QSize &frameSize) {
    if (m_frameSize != frameSize) {
        m_frameSize = frameSize;
        m_needUpdate = true;
        // init texture immediately
//        render();
    }
}

void SceneProviderRenderer::onFrame(int width, int height, uint8_t *dataY, uint8_t *dataU, uint8_t *dataV, int linesizeY, int linesizeU, int linesizeV) {
    if (m_resourceService->mirror() == false) {
        return;
    }
    //qDebug() << width;
    setFrameSize(QSize(width, height));

    if (m_resourceService->frameSize().width() != width) {
        m_resourceService->setFrameSize(QSize(width, height));
    }


    updateTextures(dataY, dataU, dataV, linesizeY, linesizeU, linesizeV);
}

void SceneProviderRenderer::updateTextures(quint8 *dataY, quint8 *dataU, quint8 *dataV, quint32 linesizeY, quint32 linesizeU, quint32 linesizeV) {
    if (m_textureInited) {
        updateTexture(m_texture[0], 0, dataY, linesizeY);
        updateTexture(m_texture[1], 1, dataU, linesizeU);
        updateTexture(m_texture[2], 2, dataV, linesizeV);
    }
}

void SceneProviderRenderer::updateTexture(GLuint texture, quint32 textureType, quint8 *pixels, quint32 stride) {
    if (!pixels)
        return;

    //qDebug() << "textureType:" << textureType ;

    QSize size = (textureType == 0 ? m_frameSize : m_frameSize);

    glBindTexture(GL_TEXTURE_2D, texture);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, static_cast<GLint>(stride));
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, size.width(), size.height(), GL_LUMINANCE, GL_UNSIGNED_BYTE, pixels);
}

void SceneProviderRenderer::initShader() {
    m_program = new QOpenGLShaderProgram(this);

    if (!m_program->addCacheableShaderFromSourceFile(QOpenGLShader::Vertex, Config::getInstance().getProjectPath() + "/res/opengl/squircle.vsh")) {
        qDebug() << "Error: " << typeid(this).name() << "Vertex shader compilation failed";
        return;
    }
    if (!m_program->addCacheableShaderFromSourceFile(QOpenGLShader::Fragment, Config::getInstance().getProjectPath() + "/res/opengl/squircle.fsh")) {
        qDebug() << "Error: " << typeid(this).name() << "Fragment shader compilation failed";
        return;
    }

    m_program->link();
    m_program->bind();

    // Specify the access method of vertex coordinates in vba

    // Parameter explanation: the parameter name of the vertex coordinates in the shader, the vertex coordinates are float, the starting offset is 0,
    // the vertex coordinate type is vec3, and the stride is 3 floats
    m_program->setAttributeBuffer("vertexIn", GL_FLOAT, 0, 3, 3 * sizeof(float));
    // Enable vertex attributes
    m_program->enableAttributeArray("vertexIn");

    QOpenGLVertexArrayObject::Binder binder(m_vao);
    m_vertexBuffer->bind();

    // Specify how texture coordinates are accessed in vbo
    // Parameter explanation: the parameter name of the texture coordinate in the shader, the texture coordinate is float,
    // the starting offset is 12 float (skip the 12 vertex coordinates stored earlier),
    // the texture coordinate type is vec2, and the stride is 2 float
    m_program->setAttributeBuffer("textureIn", GL_FLOAT, 12 * sizeof(float), 2, 2 * sizeof(float));
    m_program->enableAttributeArray("textureIn");

    //Associate the texture unit in the fragment shader with the texture unit in opengl (opengl generally provides 16 texture units)
    m_program->setUniformValue("textureY", 0);
    m_program->setUniformValue("textureU", 1);
    m_program->setUniformValue("textureV", 2);
}

void SceneProviderRenderer::initTextures() {

    // create texture
    glGenTextures(1, &m_texture[0]);
    glBindTexture(GL_TEXTURE_2D, m_texture[0]);

    // Strategy when setting texture scaling
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Set the display strategy when the texture exceeds the coordinates in the st direction
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, m_frameSize.width(), m_frameSize.height(), 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, nullptr);

    glGenTextures(1, &m_texture[1]);
    glBindTexture(GL_TEXTURE_2D, m_texture[1]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, m_frameSize.width() / 2, m_frameSize.height() / 2, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, nullptr);

    glGenTextures(1, &m_texture[2]);
    glBindTexture(GL_TEXTURE_2D, m_texture[2]);

    // Strategy when setting texture scaling
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Set the display strategy when the texture exceeds the coordinates in the st direction
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, m_frameSize.width() / 2, m_frameSize.height() / 2, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, nullptr);

    m_textureInited = true;
}

void SceneProviderRenderer::deInitTextures() {

    if (QOpenGLFunctions::isInitialized(QOpenGLFunctions::d_ptr)) {
        glDeleteTextures(3, m_texture);
    }

    memset(m_texture, 0, sizeof(m_texture));
    m_textureInited = false;
}