#pragma once

#include <QObject>

//!
//! \brief The ResourceService class
//! This class will act as a MainThread data cullmination point
//! here we should gather all the changes from controls, events e.t.c.
//! that should enter the simulation and prepare either states, or update object
//! for SceneProvider to gather
//!
class ResourceService : public QObject {
    Q_OBJECT

    Q_PROPERTY(double pitch READ pitch WRITE setPitch NOTIFY pitchChanged)
    Q_PROPERTY(double roll READ roll WRITE setRoll NOTIFY rollChanged)
    Q_PROPERTY(double yaw READ yaw WRITE setYaw NOTIFY yawChanged)
public:
    explicit ResourceService(QObject* parent = nullptr);

    static void declareQml();

    double pitch() const;
    double roll() const;
    double yaw() const;

public slots:
    void setPitch(double pitch);
    void setRoll(double roll);
    void setYaw(double yaw);

signals:
    void pitchChanged(double pitch);
    void rollChanged(double roll);
    void yawChanged(double yaw);

private:
    double m_pitch = 0;
    double m_roll  = 0;
    double m_yaw   = 0;
};
