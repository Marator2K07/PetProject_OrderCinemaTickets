#ifndef REQUESTTYPE_H
#define REQUESTTYPE_H

#include <QObject>

class RequestType {
    Q_GADGET
public:
    enum State {
        GET = 0,
        POST,
        NONE
    };
    Q_ENUM(State)
};

#endif // REQUESTTYPE_H
