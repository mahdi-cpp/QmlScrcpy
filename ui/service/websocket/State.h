
#ifndef QTSCRCPY_STATE_H
#define QTSCRCPY_STATE_H

#include <QString>

class State {

public:
    State();

    struct {
        QString phoneId;
        QString username;
    } Mirror;

    struct {
        QString artistName;
        QString title;
        QString urlPath;
        QString coverPath;
    } Music;

    struct {
        QString movieName;
        QString title;
        QString urlPath;
        QString coverPath;
    } Video;

};

#endif //QTSCRCPY_STATE_H
