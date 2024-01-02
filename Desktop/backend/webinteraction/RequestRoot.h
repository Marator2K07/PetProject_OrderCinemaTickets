#ifndef REQUESTROOT_H
#define REQUESTROOT_H

#include <QObject>

class RequestRoot {
    Q_GADGET
public:
    enum State {
        REQUESTFORM = 0
    };
    Q_ENUM(State)
};

#endif // REQUESTROOT_H
