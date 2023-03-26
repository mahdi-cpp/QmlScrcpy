#ifndef FBOINSGRENDERER_H
#define FBOINSGRENDERER_H

#include <QtQuick/QQuickFramebufferObject>

class LogoRenderer;

class FboInSGRenderer : public QQuickFramebufferObject
{
    Q_OBJECT

public:

    static void declareQml();

    Renderer *createRenderer() const;


};

#endif
