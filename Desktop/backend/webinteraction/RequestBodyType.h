#ifndef REQUESTBODYTYPE_H
#define REQUESTBODYTYPE_H

#include <QObject>

class RequestBodyType : public QObject {
    Q_OBJECT
public:
    enum State {
        TEXT = 0,
        JSON,
        NONE
    };
    Q_ENUM(State)
};

#endif // REQUESTBODYTYPE_H
