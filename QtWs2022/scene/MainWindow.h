#ifndef QTSCRCPY_MAINWINDOW_H
#define QTSCRCPY_MAINWINDOW_H

#include "QQuickView"
#include <QPointer>

class MainWindow : public QQuickView{

public:
    MainWindow(QQuickView *parent = nullptr);

private:
    QString m_serial;
    QSize frameSize;
    QSize showSize;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

};


#endif //QTSCRCPY_MAINWINDOW_H
