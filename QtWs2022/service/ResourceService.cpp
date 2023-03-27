#include "ResourceService.h"
#include "QtScrcpyCore.h"

#include <QQmlEngine>

ResourceService::ResourceService(QObject *parent) : QObject{parent} {}

void ResourceService::declareQml() {
    qmlRegisterType<ResourceService>("App", 1, 0, "ResourceService");
}

double ResourceService::pitch() const {
    return m_pitch;
}

double ResourceService::roll() const {
    return m_roll;
}

double ResourceService::yaw() const {
    return m_yaw;
}

bool ResourceService::mirror() const {
    return m_mirror;
}

void ResourceService::setSerial(const QString &serial) {
    m_serial = serial;
}

QString ResourceService::serial() {
    return m_serial;
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
    }else if (type == "screen-off") {
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

void ResourceService::setPitch(double pitch) {
    if (!qFuzzyCompare(m_pitch, pitch)) {
        m_pitch = pitch;
        emit pitchChanged(m_pitch);
    }
}

void ResourceService::setRoll(double roll) {
    if (!qFuzzyCompare(m_roll, roll)) {
        m_roll = roll;
        emit rollChanged(m_roll);
    }
}

void ResourceService::setYaw(double yaw) {
    if (!qFuzzyCompare(m_yaw, yaw)) {
        m_yaw = yaw;
        emit yawChanged(m_yaw);
    }
}

void ResourceService::setMirror(bool value) {
    m_mirror = value;
    emit mirrorChanged(m_mirror);
}
