#pragma once

#include "SceneProviderRenderer.h"

#include <QQuickItem>
#include <QQuickWindow>

//!
//! \brief The SceneProvider class
//! SceneProvider will act as a BackgroundRenderer on the MainThread, its child SceneProviderRenderer will do the actual
//! rendering on RenderThread


class SceneProvider : public QQuickItem {
    Q_OBJECT
public:
    explicit SceneProvider(QQuickItem* parent = nullptr);

    static void declareQml();

protected:
    virtual void releaseResources() override;

private slots:
    void onWindowChanged(QQuickWindow* window);

private:
    SceneProviderRenderer* m_sceneProviderRenderer = nullptr;

    QMetaObject::Connection m_connectionInitialized;
};
