#ifndef IWEBREQUESTMODEL_H
#define IWEBREQUESTMODEL_H

#include "RequestEnums.h"
#include <QJsonObject>
#include <QVariant>

///
/// \brief The IWebRequestInfo class
/// организация структуры данных и
/// функциональности модели веб-запроса
class IWebRequestModel
{
public:
    // каждый запрос должен иметь тип запроса
    virtual void setType(const RequestEnums::Type &type) = 0;
    virtual RequestEnums::Type type() const = 0;
    // каждый запрос может иметь тип тела запроса
    virtual void setBodyType(const RequestEnums::DataType &type) = 0;
    virtual RequestEnums::DataType bodyType() const = 0;
    // каждый запрос должен иметь идентификатор для связи с моделью ответа
    virtual void setIdentifier(const RequestEnums::Identifier &identifier) = 0;
    virtual RequestEnums::Identifier identifier() const = 0;
    // каждый запрос может иметь тип контента запроса
    virtual void setContentType(const QString &contentType) = 0;
    virtual QString contentType() const = 0;
    // каждый запрос должен иметь адрес
    virtual void setUrl(const QString &url) = 0;
    virtual QString url() const = 0;
    // каждый запрос может иметь данные запроса
    virtual void setData(const QVariant &data) = 0;
    virtual QVariant data() const = 0;

    // самый главный метод(слот) - метод отправки данных запроса
    virtual void send(const IWebRequestModel *) = 0;

    virtual ~IWebRequestModel() {}

private:
    // должна существовать возможность проверить запрос
    virtual bool isValid() = 0;
};

#endif // IWEBREQUESTMODEL_H
