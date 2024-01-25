#ifndef REQUESTENUMS_H
#define REQUESTENUMS_H

#include <QObject>

class RequestEnums {
    Q_GADGET
public:
    // для типа запроса
    enum Type {
        GET = 0,
        POST,
        TYPENONE
    };
    Q_ENUM(Type)
    // для типа данных в запросе
    enum DataType {
        TEXT = 0,
        JSON,
        DATANONE
    };
    Q_ENUM(DataType)
    // для идентфикации данного запроса
    // во время дальнейшей обработки
    enum Identifier {
        REQUESTFORM = 0,
        IDENTIFIERNONE
    };
    Q_ENUM(Identifier)
};

#endif // REQUESTENUMS_H
