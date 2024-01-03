#ifndef IWEBRESPONCEMODEL_H
#define IWEBRESPONCEMODEL_H

#include <QNetworkReply>
#include <QByteArray>

///
/// \brief The IWebResponceModel class
/// интерфейс для организации структуры
/// данных и функциональности какого-либо веб ответа
class IWebResponceModel
{
public:
    // каждый ответ может иметь тип возможной ошибки
    virtual void setError(const QString &error) = 0;
    virtual QString error() const = 0;
    // каждый ответ может иметь полученные данные в виде массива байтов
    virtual void setData(const QByteArray &data) = 0;
    virtual QByteArray data() const = 0;

    virtual ~IWebResponceModel() {}
};

#endif // IWEBRESPONCEMODEL_H
