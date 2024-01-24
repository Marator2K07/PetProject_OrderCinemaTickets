#ifndef IWEBRESPONCEMODEL_H
#define IWEBRESPONCEMODEL_H

#include "RequestEnums.h"
#include <QByteArray>

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
    // модель ответа сама подает знак, что готова принимать информацию
    virtual subscribe(IWebResponceModel *curModel,
                      RequestEnums::Identifier) = 0;

    virtual ~IWebResponceModel() {}
};

#endif // IWEBRESPONCEMODEL_H
