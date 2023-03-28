#include <QApplication>
#include <QSurfaceFormat>

#include "config.h"
#include "ui/scene/MainWindow.h"

static QPointer<MainWindow> m_MainWindow;

int main(int argc, char *argv[]) {

    // set on QApplication before
    // bug: config path is error on mac
    int opengl = Config::getInstance().getDesktopOpenGL();
    if (0 == opengl) {
        QApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    } else if (1 == opengl) {
        QApplication::setAttribute(Qt::AA_UseOpenGLES);
    } else if (2 == opengl) {
        QApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
    }

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#endif

    QSurfaceFormat varFormat = QSurfaceFormat::defaultFormat();
    varFormat.setVersion(2, 0);
    varFormat.setProfile(QSurfaceFormat::NoProfile);
    QSurfaceFormat::setDefaultFormat(varFormat);

    QApplication app(argc, argv);

    m_MainWindow = new MainWindow();
    m_MainWindow->setGeometry(700,100, 1450, 850);
    m_MainWindow->show();

    return app.exec();
}