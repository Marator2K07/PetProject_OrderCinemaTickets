#ifndef TYPESFORREQUESTMETHOD_H
#define TYPESFORREQUESTMETHOD_H

#include <QObject>

class TypesForRequestMethod : public QObject
{
    Q_OBJECT
public:
    enum MethodType {
        GET = 0, POST = 1
    };
    Q_ENUM(MethodType)
    enum MethodBodyType {
        TEXT = 0, JSON = 1
    };
    Q_ENUM(MethodBodyType)
};

#endif // TYPESFORREQUESTMETHOD_H
