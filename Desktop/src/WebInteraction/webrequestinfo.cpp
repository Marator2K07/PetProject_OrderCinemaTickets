#include "webrequestinfo.h"

QJsonObject WebRequestInfo::getJsonData() const
{
    return qvariant_cast<QJsonObject>(data);
}

QString WebRequestInfo::getTextData() const
{
    return qvariant_cast<QString>(data);
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

void WebRequestInfo::setRequestType(const Types::Request &type)
{
    if (type != m_requestType) {
        m_requestType = type;
        emit requestTypeChanged();
    }
}

Types::Request WebRequestInfo::requestType() const
{
    return m_requestType;
}
