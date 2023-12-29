#ifndef IWEBREQUESTINFO_H
#define IWEBREQUESTINFO_H

#include "RequestType.h"
#include "RequestBodyType.h"

#include <QVariant>
#include <QJsonObject>
#include <QtQml>

///
/// \brief The IWebRequestInfo class
/// интерфейс для организации структуры
/// данных и функциональности какого-либо веб запроса
class IWebRequestInfo
{
public:
    // каждый запрос должен иметь тип запроса
    virtual void setRequestType(const RequestType::State &type) = 0;
    virtual RequestType::State requestType() const = 0;
    // каждый запрос может иметь тип тела запроса
    virtual void setRequestBodyType(const RequestBodyType::State &type) = 0;
    virtual RequestBodyType::State requestBodyType() const = 0;
    // каждый запрос должен иметь адрес
    virtual void setUrl(const QString &url) = 0;
    virtual QString url() const = 0;
    // каждый запрос может иметь данные запроса
    virtual void setData(const QVariant &data) = 0;
    virtual QVariant data() const = 0;

    // самый главный метод - метод отправки данных запроса
    virtual void send(const IWebRequestInfo *) = 0;

    virtual ~IWebRequestInfo() {}

private:
    // должна существовать возможность проверить запрос
    virtual bool isValid() = 0;
};

#endif // IWEBREQUESTINFO_H
