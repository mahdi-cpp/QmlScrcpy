#include "Scene.h"

#include "SceneRenderer.h"

#include <QQmlEngine>

Scene::Scene(QQuickItem *parent) : QQuickFramebufferObject(parent) {
    m_timer.setInterval(16);
    connect(&m_timer, &QTimer::timeout, this, &Scene::update);
    m_timer.start();
}

void Scene::declareQml() {
    qmlRegisterType<Scene>("App", 1, 0, "Scene");
}

QQuickFramebufferObject::Renderer *Scene::createRenderer() const {
    return new SceneRenderer;
}
