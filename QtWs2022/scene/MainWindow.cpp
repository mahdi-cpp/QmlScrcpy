
#include <QQuickView>
#include <QQmlContext>

#include "QtScrcpyCore.h"

#include "MainWindow.h"

#include "QtWs2022/sceneprovider/SceneProvider.h"
#include "QtWs2022/service/ServiceManager.h"
#include "Scene.h"
#include "PieChart.h"

MainWindow::MainWindow(QQuickView *parent) : QQuickView(parent = nullptr) {

    ResourceService* resourceService = new ResourceService(this);
    ServiceManager::getInstance().setResourceService(resourceService);            // Register service to our C++ singleton

    // Declare/Register all used custom QML elements
    SceneProvider::declareQml();
    Scene::declareQml();
    ResourceService::declareQml();
    PieChart::declareQml();

    QQmlContext *rootContext;
    rootContext = this->rootContext();
    rootContext->setContextProperty("resourceService", resourceService); // Also set it to QML root context

    setKeyboardGrabEnabled(true);
    setSource(QUrl("/home/mahdi/CLionProjects/QtScrcpy/QtWs2022/qml/main.qml"));
    setResizeMode(QQuickView::SizeRootObjectToView);

    frameSize.setWidth(488);
    frameSize.setHeight(1080);

    showSize.setWidth(400);
    showSize.setHeight(900);

    m_serial = "192.168.1.171:5555";
}


void MainWindow::keyPressEvent(QKeyEvent *event) {

    qDebug() << "keyPressEvent";

    auto device = qsc::IDeviceManage::getInstance().getDevice(m_serial);
    if (!device) {
        return;
    }
    emit device->keyEvent(event, frameSize, showSize);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {

    auto device = qsc::IDeviceManage::getInstance().getDevice(m_serial);
    if (!device) {
        return;
    }
    emit device->keyEvent(event, frameSize, showSize);
}
