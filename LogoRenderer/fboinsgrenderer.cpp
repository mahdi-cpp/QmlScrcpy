
#include "fboinsgrenderer.h"
#include "logorenderer.h"
#include "QtScrcpyCore.h"

#include <QtGui/QOpenGLFramebufferObject>

#include <QtQuick/QQuickWindow>
#include <qsgsimpletexturenode.h>

class LogoInFboRenderer : public QObject, public QQuickFramebufferObject::Renderer, public qsc::DeviceObserver {
public:
    explicit LogoInFboRenderer() {
        logo.initialize();
        connect(&qsc::IDeviceManage::getInstance(), &qsc::IDeviceManage::onNewFrame, this, &LogoInFboRenderer::onFrame);
    }

    void render() {
        logo.render();
        update();
    }

    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) {
        QOpenGLFramebufferObjectFormat format;
        format.setAttachment(QOpenGLFramebufferObject::Depth);
        format.setSamples(4);
        return new QOpenGLFramebufferObject(size, format);
    }

    LogoRenderer logo;

private slots:
    void onFrame(int width, int height, uint8_t *dataY, uint8_t *dataU, uint8_t *dataV, int linesizeY, int linesizeU, int linesizeV) {
        logo.onFrame(width, height, dataY, dataU, dataV, linesizeY, linesizeU, linesizeV);
        render();
    };
};

void FboInSGRenderer::declareQml() {
    qmlRegisterType<FboInSGRenderer>("SceneGraphRendering", 1, 0, "Render");
}

QQuickFramebufferObject::Renderer *FboInSGRenderer::createRenderer() const {
    return new LogoInFboRenderer();
}
