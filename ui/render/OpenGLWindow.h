#ifndef QTSCRCPY_OPENGLWINDOW_H
#define QTSCRCPY_OPENGLWINDOW_H

#include <QWindow>
#include <QOpenGLFunctions>
#include <QQuickView>

class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;

class OpenGLWindow : public QQuickView, protected QOpenGLFunctions
{
Q_OBJECT
public:
    explicit OpenGLWindow(QWindow *parent = 0);
    ~OpenGLWindow();

    virtual void render(QPainter *painter);
    virtual void render();
    virtual void initialize();

    void setAnimating(bool animating);

public slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;

private:
    bool m_animating;

    QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_device;
};


#endif //QTSCRCPY_OPENGLWINDOW_H
