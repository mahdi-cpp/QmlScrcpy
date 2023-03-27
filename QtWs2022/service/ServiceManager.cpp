#include "ServiceManager.h"

#include <QThread>

ResourceService* ServiceManager::resourceService() const {
    return m_resourceService;
}

SceneProviderRenderer* ServiceManager::renderer() const {
    return m_renderers.value(QThread::currentThread(), nullptr);
}

void ServiceManager::setResourceService(ResourceService* resourceService) {
    m_resourceService = resourceService;
    m_resourceService->setSerial("192.168.1.171:5555");
}

void ServiceManager::addRenderer(SceneProviderRenderer* renderer) {
    m_renderers.insert(QThread::currentThread(), renderer);
}
