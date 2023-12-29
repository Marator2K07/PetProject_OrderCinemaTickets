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
    virtual void setRequestType(const RequestType::State &type);
    virtual RequestType::State requestType() const;
    // каждый запрос может иметь тип тела запроса
    virtual void setRequestBodyType(const RequestBodyType::State &type);
    virtual RequestBodyType::State requestBodyType() const;
    // каждый запрос должен иметь адрес
    virtual void setUrl(const QString &url);
    virtual QString url() const;
    // каждый запрос может иметь данные запроса
    virtual void setData(const QVariant &data);
    virtual QVariant data() const;

    // самый главный метод - метод отправки данных запроса
    virtual void send(const IWebRequestInfo *);

    virtual ~IWebRequestInfo() {}

private:
    // должна существовать возможность проверить запрос
    virtual bool isValid();
};

#endif // IWEBREQUESTINFO_H
