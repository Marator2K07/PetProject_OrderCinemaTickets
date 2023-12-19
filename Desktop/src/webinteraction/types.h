#ifndef TYPES_H
#define TYPES_H

#include <QObject>

class Types : public QObject {
    Q_OBJECT
public:
    enum class Request {
        GET = 0,
        POST,
        NONE
    };
    Q_ENUM(Request)
    enum class RequestBody {
        TEXT = 0,
        JSON,
        NONE
    };
    Q_ENUM(RequestBody)

    Types() = delete; // запрет на создание любого экземпляра
};

#endif // TYPES_H
