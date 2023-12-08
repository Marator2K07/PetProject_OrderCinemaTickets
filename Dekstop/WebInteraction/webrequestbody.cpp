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

void WebRequestBody::setJsonData(const QJsonObject &newJsonData)
{
    data = QVariant::fromValue(newJsonData);
}

WebRequestBody::WebRequestBody(QObject *parent)
    : QObject{parent}
{
}

WebRequestBody::WebRequestBody(const WebRequestBody &other) :
    data(other.getData()),
    contentType(other.getContentType())
{
}
