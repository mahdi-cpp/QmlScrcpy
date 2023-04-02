#include <QQmlEngine>
#include <QJsonObject>
#include <QJsonDocument>

#include "QtScrcpyCore.h"

#include "ResourceService.h"

ResourceService::ResourceService(QObject *parent) : QObject{parent} {
    m_portraitSize.setWidth(375);
    m_portraitSize.setHeight(830);
    mirror = new Mirror();

    connect(&m_adb, &qsc::AdbProcess::adbProcessResult, this, [this](qsc::AdbProcess::ADB_EXEC_RESULT processResult) {

        QStringList args = m_adb.arguments();

        switch (processResult) {
            case qsc::AdbProcess::AER_ERROR_START:
                break;
            case qsc::AdbProcess::AER_SUCCESS_START:
                break;
            case qsc::AdbProcess::AER_ERROR_EXEC:
                break;
            case qsc::AdbProcess::AER_SUCCESS_EXEC:
                break;
            case qsc::AdbProcess::AER_ERROR_MISSING_BINARY:
                break;
        }

    });
}

void ResourceService::declareQml() {
    qmlRegisterType<ResourceService>("App", 1, 0, "ResourceService");
}

bool ResourceService::getMirror() const {
    return m_mirror;
}

QSize ResourceService::frameSize() const {
    return m_frameSize;
}

QSize ResourceService::portraitSize() const {
    return m_portraitSize;
}

QSize ResourceService::landscapeSize() const {
    return m_landscapeSize;
}

int ResourceService::orientation() const {
    return m_orientation;
}

void ResourceService::setSerial(const QString &serial) {
    m_serial = serial;
}

QString ResourceService::serial() {
    return m_serial;
}

void ResourceService::qmlCommands(QString command, QString data) {
    emit qmlEvents(command, data);
}

void ResourceService::processClick(QString type) {
    qDebug() << "Type:" << type;

    auto device = qsc::IDeviceManage::getInstance().getDevice(m_serial);
    if (!device) {
        return;
    }

    if (type == "home") {
        device->postGoBack();
    } else if (type == "volume-up") {
        device->postVolumeUp();
    } else if (type == "volume-down") {
        device->postVolumeDown();
    } else if (type == "arrow-back") {
        device->postGoBack();
    } else if (type == "screen-on") {
        //m_screen = !m_screen;
        device->setScreenPowerMode(true);
    } else if (type == "screen-off") {
        //m_screen = !m_screen;
        device->setScreenPowerMode(false);
    } else if (type == "power") {
        device->postPower();
    } else if (type == "expand-menu") {
        device->expandNotificationPanel();
    } else if (type == "app-switch") {
        device->postAppSwitch();
    } else if (type == "touch-show") {
        m_showTouch = !m_showTouch;
        device->showTouch(m_showTouch);
    } else if (type == "app-switch") {
        device->postAppSwitch();
    }
}

void ResourceService::setMirror(bool value) {
    m_mirror = value;
    emit mirrorChanged(m_mirror);
}

void ResourceService::setFrameSize(QSize size) {

    qDebug() << "ResourceService::setFrameSize";

    m_frameSize = size;

    if (size.height() > size.width()) {
        m_portraitSize.setWidth(375);
        m_portraitSize.setHeight(830);
        m_orientation = DisplayOrientation::portrait;
    } else {
        float scale = 1.35;
        m_landscapeSize.setWidth(1080 * scale);
        m_landscapeSize.setHeight(488 * scale);
        m_orientation = DisplayOrientation::landscape;
    }

    emit frameSizeChanged(m_frameSize);
    emit orientationChanged(m_orientation);

    emit cppGenerateEvents("DISPLAY_ORIENTATION_CHANGED");
    emit cppGenerateEvents("FRAME_SIZE_CHANGED");
}

void ResourceService::setOrientation(int orientation) {
    m_orientation = orientation;
    emit orientationChanged(m_orientation);
    emit cppGenerateEvents("DISPLAY_ORIENTATION_CHANGED");
}

void ResourceService::setPortraitSize(QSize size) {
    m_portraitSize = size;
    emit portraitSizeChanged(m_portraitSize);
}

void ResourceService::setLandscapeSize(QSize size) {
    m_landscapeSize = size;
    emit landscapeSizeChanged(m_landscapeSize);
}


void ResourceService::webSocketMessageReceived(QString jsonString) {

    QByteArray byteArray;
    byteArray.append(jsonString);

    //2. Format the content of the byteArray as QJsonDocument
    //and check on parse Errors
    QJsonParseError parseError;
    QJsonDocument jsonDoc;
    jsonDoc = QJsonDocument::fromJson(byteArray, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Parse error at " << parseError.offset << ":" << parseError.errorString();
        return;
    }

    //3. Create a jsonObject and fill it with the byteArray content, formatted
    //and holding by the jsonDocument Class
    QJsonObject jsonObj;
    jsonObj = jsonDoc.object();

    QString command = jsonObj.value("command").toString();

    if (command == "WIFI_IP") {//open connection
        QString data = jsonObj.value("data").toString();
        qDebug() << "command data:" << data;

        QStringList adbArgs;
        adbArgs << "connect";
        adbArgs << data;
        m_adb.execute("", adbArgs);
        return;

    } else if (command == "REQUEST_MIRROR_START") {

        mirror->wifIp = jsonObj.value("wifIp").toString();
        mirror->androidId = jsonObj.value("androidId").toString();
        mirror->connectionType = jsonObj.value("connectionType").toString();
        mirror->username = jsonObj.value("username").toString();
        mirror->title = jsonObj.value("title").toString();
        mirror->bitrate = jsonObj.value("bitrate").toString();
        mirror->resolution = jsonObj.value("resolution").toString();

        setSerial(mirror->wifIp);

        qDebug() << "";
        qDebug() << "androidId:" << mirror->androidId;
        qDebug() << "wifIp:" << mirror->wifIp;
        qDebug() << "connectionType:" << mirror->connectionType;
        qDebug() << "username:" << mirror->username;
        qDebug() << "title:" << mirror->title;
        qDebug() << "bitrate:" << mirror->bitrate;
        qDebug() << "resolution:" << mirror->resolution;
        qDebug() << "";

        emit androidEvents("REQUEST_MIRROR_START", "");
    }
}

void ResourceService::setUsbMirrorParametre(QString device) {
    mirror->androidId = device;
    mirror->connectionType = "USB";
    mirror->username = "USB Mirror";
    mirror->title = "screen mirror by usb connection";
    mirror->bitrate = "2 Mbit/s";
    mirror->resolution = "480 x 1080";
}


void ResourceService::stopMirror() {

    mirror->androidId = "";
    mirror->username = "";
    mirror->title = "";
    mirror->bitrate = "";
    mirror->resolution = "";
}

//webSocketMessageReceived
QString ResourceService::getStateJson() {

    QJsonObject rootObj;

    QJsonObject mirrorObj;
    mirrorObj["androidId"] = mirror->androidId;
    mirrorObj["wifiIp"] = mirror->wifIp;
    mirrorObj["connectionType"] = mirror->connectionType;
    mirrorObj["username"] = mirror->username;
    mirrorObj["title"] = mirror->title;
    mirrorObj["bitrate"] = mirror->bitrate;
    mirrorObj["resolution"] = mirror->resolution;

//    QJsonObject musicObj;
//    musicObj["artistName"] = mirror->Music.artistName;
//    musicObj["coverPath"] = mirror->Music.coverPath;
//    musicObj["title"] = mirror->Music.title;
//    musicObj["urlPath"] = mirror->Music.urlPath;

    //rootObj["Type"] = "mirror";
    //rootObj["Mirror"] = mirrorObj;
    //rootObj["music"] = musicObj;

    QJsonDocument doc(mirrorObj);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    return strJson;

}