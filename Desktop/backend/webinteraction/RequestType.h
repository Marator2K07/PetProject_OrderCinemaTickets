#ifndef REQUESTTYPE_H
#define REQUESTTYPE_H

#include <QObject>

class RequestType : public QObject {
    Q_OBJECT
public:
    enum State {
        GET = 0,
        POST,
        NONE
    };
    Q_ENUM(State)
};

#endif // REQUESTTYPE_H
