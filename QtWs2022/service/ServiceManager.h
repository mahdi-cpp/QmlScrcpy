#pragma once

#include "ResourceService.h"
#include "QtWs2022/sceneprovider/SceneProviderRenderer.h"

//!
//! \brief The ServiceManager class
//! This class acts only as a object holder accessible from the whole application
//! For our demo use case it holds one global instance of ResourceService
//! and BackgrondRenderRenderer instance for each of our QML Window
//!
class ServiceManager {
public:
    static ServiceManager& getInstance() {
        static ServiceManager instance;
        return instance;
    }

    static ServiceManager* getInstancePtr() { return &ServiceManager::getInstance(); }

    ResourceService* resourceService() const;
    SceneProviderRenderer* renderer() const;

    void setResourceService(ResourceService* resourceService);
    void addRenderer(SceneProviderRenderer* renderer);

private:
    ServiceManager()                                  = default;
    ~ServiceManager()                                 = default;
    ServiceManager(const ServiceManager&)             = delete;
    ServiceManager& operator=(const ServiceManager&)  = delete;
    ServiceManager(const ServiceManager&&)            = delete;
    ServiceManager& operator=(const ServiceManager&&) = delete;

    void generateObjects(QThread* thread);

private:
    ResourceService* m_resourceService = nullptr;
    QMap<QThread*, SceneProviderRenderer*> m_renderers;
};
