#include <QQmlEngine>
#include <QJsonObject>
#include <QJsonDocument>

#include "QtScrcpyCore.h"

#include "ResourceService.h"

ResourceService::ResourceService(QObject *parent) : QObject{parent} {
    m_portraitSize.setWidth(375);
    m_portraitSize.setHeight(830);
    state = new State();
    stateInit();
}

void ResourceService::declareQml() {
    qmlRegisterType<ResourceService>("App", 1, 0, "ResourceService");
}

bool ResourceService::mirror() const {
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

void ResourceService::qmlCommands(QString name) {
    emit qmlGenerateEvents(name);
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

void ResourceService::stateInit() {

    state->Mirror.username = "mahdi.cpp";
    state->Mirror.phoneId = "0935";

    state->Music.artistName = "Mohsen chavoshi";
    state->Music.title = "music title";
    state->Music.urlPath = "http://arvancloude/music.mp3";
    state->Music.coverPath = "http://arvancloude/cover/14562.jpg";
}

//webSocket
QString ResourceService::getStateJsonString() {

    QJsonObject rootObj;

    QJsonObject mirrorObj;
    mirrorObj["username"] = state->Mirror.username;
    mirrorObj["phoneId"] = state->Mirror.phoneId;

    QJsonObject musicObj;
    musicObj["artistName"] = state->Music.artistName;
    musicObj["coverPath"] = state->Music.coverPath;
    musicObj["title"] = state->Music.title;
    musicObj["urlPath"] = state->Music.urlPath;

    rootObj["Type"] = "state";
    rootObj["mirror"] = mirrorObj;
    rootObj["music"] = musicObj;

    QJsonDocument doc(rootObj);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    return strJson;

}