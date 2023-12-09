#include "webrequestbody.h"

QJsonObject WebRequestBody::getJsonData() const
{
    return qvariant_cast<QJsonObject>(data);
}

QVariant WebRequestBody::getData() const
{
    return data;
}

QString WebRequestBody::getContentType() const
{
    return contentType;
}

void WebRequestBody::setContentType(const QString &newContentType)
{
    contentType = newContentType;
}

void WebRequestBody::setData(const QVariant &newData)
{
    data = newData;
}

QString WebRequestBody::getUrl() const
{
    return url;
}

void WebRequestBody::setUrl(const QString &newUrl)
{
    url = newUrl;
}

WebRequestBody::WebRequestBody(QObject *parent)
    : QObject{parent}
{
}

WebRequestBody::WebRequestBody(const WebRequestBody &other)
    : data(other.getData())
    , contentType(other.getContentType())
    , url(other.getUrl())
{
}
