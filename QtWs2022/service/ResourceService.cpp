#include "ResourceService.h"

#include <QQmlEngine>

ResourceService::ResourceService(QObject* parent) : QObject{parent} {}

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
