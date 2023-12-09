#include "webrequestinfo.h"

QJsonObject WebRequestInfo::getJsonData() const
{
    return qvariant_cast<QJsonObject>(data);
}

QVariant WebRequestInfo::getData() const
{
    return data;
}

QString WebRequestInfo::getContentType() const
{
    return contentType;
}

void WebRequestInfo::setContentType(const QString &newContentType)
{
    contentType = newContentType;
}

void WebRequestInfo::setData(const QVariant &newData)
{
    data = newData;
}

void WebRequestInfo::setJsonData(const QJsonObject &newJsonData)
{
    data = QVariant::fromValue(newJsonData);
}

QString WebRequestInfo::getUrl() const
{
    return url;
}

void WebRequestInfo::setUrl(const QString &newUrl)
{
    url = newUrl;
}

WebRequestInfo::WebRequestInfo(QObject *parent)
    : QObject{parent}
{
}

WebRequestInfo::WebRequestInfo(const WebRequestInfo &other)
    : data(other.getData())
    , contentType(other.getContentType())
    , url(other.getUrl())
{
}
