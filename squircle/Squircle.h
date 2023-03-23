#ifndef QTSCRCPY_SQUIRCLE_H
#define QTSCRCPY_SQUIRCLE_H

#include <QtQuick/QQuickItem>

#include "SquircleRenderer.h"


class Squircle : public QQuickItem
{
Q_OBJECT
    Q_PROPERTY(qreal t READ t WRITE setT NOTIFY tChanged)

public:
    Squircle();

    qreal t() const { return m_t; }
    void setT(qreal t);

    qreal m_t;
    SquircleRenderer *m_renderer;

signals:
    void tChanged();

public slots:
    void sync();
    void cleanup();

private slots:
    void handleWindowChanged(QQuickWindow *win);

};

#endif //QTSCRCPY_SQUIRCLE_H
