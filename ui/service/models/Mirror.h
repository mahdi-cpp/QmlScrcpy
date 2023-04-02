
#ifndef QTSCRCPY_MIRROR_H
#define QTSCRCPY_MIRROR_H

#include <QString>

class Mirror {

public:
    Mirror() {};

    QString androidId = "";
    QString wifIp = "";
    QString connectionType = "";
    QString username = "";
    QString title = "";
    QString bitrate = "";
    QString resolution = "";
};

#endif //QTSCRCPY_MIRROR_H
