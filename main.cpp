#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QSurfaceFormat>
#include <QTranslator>

#include "config.h"
#include "mousetap/mousetap.h"

#include "QQmlContext"


#include "QtWs2022/service/ServiceManager.h"
#include "QtWs2022/sceneprovider/SceneProvider.h"
#include "QtWs2022/scene/MainWindow.h"

//static Dialog *g_mainDlg = Q_NULLPTR;
static QPointer<MainWindow> m_MainWindow;

//static QtMessageHandler g_oldMessageHandler = Q_NULLPTR;

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);

void installTranslator();

static QtMsgType g_msgType = QtInfoMsg;

QtMsgType covertLogLevel(const QString &logLevel);



int main(int argc, char *argv[]) {

//    qputenv("QTSCRCPY_ADB_PATH", "../../../QtScrcpy/core/src/third_party/adb/linux/adb");
//    qputenv("QTSCRCPY_SERVER_PATH", "../../../QtScrcpy/core/src/third_party/scrcpy-serve");
//    qputenv("QTSCRCPY_KEYMAP_PATH", "../../../keymap");
//    qputenv("QTSCRCPY_CONFIG_PATH", "../../../config");

    g_msgType = covertLogLevel(Config::getInstance().getLogLevel());

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
    /*
    varFormat.setSamples(4);
    varFormat.setAlphaBufferSize(8);
    varFormat.setBlueBufferSize(8);
    varFormat.setRedBufferSize(8);
    varFormat.setGreenBufferSize(8);
    varFormat.setDepthBufferSize(24);
    */
    QSurfaceFormat::setDefaultFormat(varFormat);

    //g_oldMessageHandler = qInstallMessageHandler(myMessageOutput);
    QApplication app(argc, argv);

    // After setting the version number and application name through the qmake VERSION variable or rc under windows, you can directly get it here
    // The value obtained under mac is the value of CFBundleVersion
    qDebug() << app.applicationVersion();
    qDebug() << app.applicationName();

    qDebug() << "QCoreApplication::applicationDirPath():" << QCoreApplication::applicationDirPath();


    QString str = QCoreApplication::applicationDirPath();
    int index = str.indexOf("/.output");
    QString leftSide = str.left(index);

    Config::getInstance().setProjectPath(leftSide);
    qDebug() << "getProjectPath():" << Config::getInstance().getProjectPath();


    //update version
    QStringList versionList = QCoreApplication::applicationVersion().split(".");
    if (versionList.size() >= 3) {
        QString version = versionList[0] + "." + versionList[1] + "." + versionList[2];
        app.setApplicationVersion(version);
    }

    installTranslator();

    // load style sheet
//    QFile file(":/qss/psblack.css");
//    if (file.open(QFile::ReadOnly)) {
//        QString qss = QLatin1String(file.readAll());
//        QString paletteColor = qss.mid(20, 7);
//        qApp->setPalette(QPalette(QColor(paletteColor)));
//        qApp->setStyleSheet(qss);
//        file.close();
//    }

    qsc::AdbProcess::setAdbPath(Config::getInstance().getAdbPath());

//    g_mainDlg = new Dialog{};
//    g_mainDlg->show();

    m_MainWindow = new MainWindow();
    m_MainWindow->setGeometry(700,100, 1450, 850);
    m_MainWindow->show();

//    qInfo() << QObject::tr(
//            "This software is completely open source and free. Use it at your own risk. You can download it at the "
//            "following address:");
//    qInfo() << QString("QtScrcpy %1 <https://github.com/barry-ran/QtScrcpy>").arg(
//            QCoreApplication::applicationVersion());

    int ret = app.exec();
    //delete g_mainDlg;

    return ret;
}

void installTranslator() {
    static QTranslator translator;
    QLocale locale;
    QLocale::Language language = locale.language();
    //language = QLocale::English;
    QString languagePath = ":/i18n/";
    switch (language) {
        case QLocale::Chinese:
            languagePath += "zh_CN.qm";
            break;
        case QLocale::English:
        default:
            languagePath += "en_US.qm";
            break;
    }

    translator.load(languagePath);
    qApp->installTranslator(&translator);
}

QtMsgType covertLogLevel(const QString &logLevel) {
    if ("debug" == logLevel) {
        return QtDebugMsg;
    }

    if ("info" == logLevel) {
        return QtInfoMsg;
    }

    if ("warn" == logLevel) {
        return QtWarningMsg;
    }

    if ("error" == logLevel) {
        return QtCriticalMsg;
    }

#ifdef QT_NO_DEBUG
    return QtInfoMsg;
#else
    return QtDebugMsg;
#endif
}

//void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
//    if (g_oldMessageHandler) {
//        g_oldMessageHandler(type, context, msg);
//    }
//
//    // Is Qt log level higher than warning?
//    float fLogLevel = g_msgType;
//    if (QtInfoMsg == g_msgType) {
//        fLogLevel = QtDebugMsg + 0.5f;
//    }
//    float fLogLevel2 = type;
//    if (QtInfoMsg == type) {
//        fLogLevel2 = QtDebugMsg + 0.5f;
//    }
//
////    if (fLogLevel <= fLogLevel2) {
////        if (g_mainDlg && g_mainDlg->isVisible() && !g_mainDlg->filterLog(msg)) {
////            g_mainDlg->outLog(msg);
////        }
////    }
//
//    if (QtFatalMsg == type) {
//        //abort();
//    }
//}
