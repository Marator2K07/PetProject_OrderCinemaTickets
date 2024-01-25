#ifndef IWEBRESPONCEMODEL_H
#define IWEBRESPONCEMODEL_H

#include "RequestEnums.h"
#include "requestresponcehandling.h"
#include <QByteArray>

class RequestResponceHandling;

///
/// \brief The IWebResponceModel interface
/// организация структуры данных и
/// функциональности модели веб-ответа
class IWebResponceModel
{
public:
    // каждый ответ может иметь тип возможной ошибки
    virtual void setError(const QString &error) = 0;
    virtual QString error() const = 0;
    // каждый ответ может иметь полученные данные в виде массива байтов
    virtual void setData(const QByteArray &data) = 0;
    virtual QByteArray data() const = 0;
    // модель ответа может находится в двух состояниях - загружается или загружена
    virtual void setIsLoading(const bool &isLoading) = 0;
    virtual bool isLoading() const = 0;
    // модель ответа сама подает знак, что готова принимать информацию
    virtual void subscribe(RequestResponceHandling *responceHandler,
                           RequestEnums::Identifier identifier) = 0;

    virtual ~IWebResponceModel() {}
};

#endif // IWEBRESPONCEMODEL_H
