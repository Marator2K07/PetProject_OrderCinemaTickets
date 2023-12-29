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
/// данных какого либо веб запроса
class IWebRequestInfo
{
public:
    // каждый запрос должен иметь тип запроса
    virtual void setRequestType(const RequestType::State &type);
    virtual RequestType::State requestType() const;
    // каждый запрос должен иметь тип тела запроса
    virtual void setRequestBodyType(const RequestBodyType::State &type);
    virtual RequestBodyType::State requestBodyType() const;
    // каждый запрос должен иметь адрес
    virtual void setUrl(const QString &url);
    virtual QString url() const;
    // каждый запрос может иметь данные запроса
    virtual void setData(const QVariant &data);
    virtual QVariant data() const;

    virtual ~IWebRequestInfo() {}
};

#endif // IWEBREQUESTINFO_H
