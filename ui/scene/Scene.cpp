#include "Scene.h"

#include "SceneRenderer.h"

#include <QQmlEngine>

Scene::Scene(QQuickItem *parent) : QQuickFramebufferObject(parent) {

    m_timer.setInterval(16);
    connect(&m_timer, &QTimer::timeout, this, &Scene::update);
    m_timer.start();

    m_resourceService = ServiceManager::getInstance().resourceService();

    setAcceptedMouseButtons(Qt::AllButtons);

    connect(&qsc::IDeviceManage::getInstance(), &qsc::IDeviceManage::deviceConnected, this, &Scene::onDeviceConnected);
    connect(&qsc::IDeviceManage::getInstance(), &qsc::IDeviceManage::deviceDisconnected, this, &Scene::onDeviceDisconnected);

}

void Scene::declareQml() {
    qmlRegisterType<Scene>("App", 1, 0, "Scene");
}

QQuickFramebufferObject::Renderer *Scene::createRenderer() const {
    return new SceneRenderer;
}

void Scene::onDeviceConnected(bool success, const QString &serial, const QString &deviceName, const QSize &size) {

    Q_UNUSED(serial);
    Q_UNUSED(size);
    Q_UNUSED(deviceName);

    qDebug() << "onDeviceConnected 1";

    if (!success) {
        return;
    }

    qDebug() << "onDeviceConnected success";
}

void Scene::onDeviceDisconnected(QString serial) {
    Q_UNUSED(serial);

}

void Scene::mouseProcess(QMouseEvent *event) {
    auto device = qsc::IDeviceManage::getInstance().getDevice(m_resourceService->serial());
    if (!device) {
        return;
    }
    if (m_resourceService->orientation() == 0)
            emit device->mouseEvent(event, m_resourceService->frameSize(), m_resourceService->portraitSize());
    else
            emit device->mouseEvent(event, m_resourceService->frameSize(), m_resourceService->landscapeSize());
}

void Scene::mousePressEvent(QMouseEvent *event) {
    mouseProcess(event);
}

void Scene::mouseReleaseEvent(QMouseEvent *event) {
    mouseProcess(event);
}

void Scene::mouseMoveEvent(QMouseEvent *event) {
    mouseProcess(event);
}

void Scene::mouseDoubleClickEvent(QMouseEvent *event) {
    mouseProcess(event);
}

void Scene::wheelEvent(QWheelEvent *event) {

    QWheelEvent wheelEvent(
            event->pos(), event->globalPosF(), event->pixelDelta(), event->angleDelta(), event->delta(),
            event->orientation(),
            event->buttons(), event->modifiers(), event->phase(), event->source(), event->inverted());

    auto device = qsc::IDeviceManage::getInstance().getDevice(m_resourceService->serial());
    if (!device) {
        return;
    }
    if (m_resourceService->orientation() == 0)
            emit device->wheelEvent(&wheelEvent, m_resourceService->frameSize(), m_resourceService->portraitSize());
    else
            emit device->wheelEvent(&wheelEvent, m_resourceService->frameSize(), m_resourceService->landscapeSize());
}
