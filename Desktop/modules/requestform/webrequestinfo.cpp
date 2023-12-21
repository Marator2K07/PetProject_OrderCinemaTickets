#include "webrequestinfo.h"

QJsonObject WebRequestInfo::getJsonData() const
{
    return qvariant_cast<QJsonObject>(m_data);
}

QString WebRequestInfo::getTextData() const
{
    return qvariant_cast<QString>(m_data);
}

QString WebRequestInfo::getContentType() const
{
    return contentType;
}

void WebRequestInfo::setContentType(const QString &newContentType)
{
    contentType = newContentType;
}

void WebRequestInfo::setData(const QVariant &data)
{
    if (data != m_data) {
        m_data = data;
        emit dataChanged();
    }
}

QVariant WebRequestInfo::data() const
{
    return m_data;
}

QString WebRequestInfo::url() const
{
    return m_url;
}

void WebRequestInfo::setUrl(const QString &url)
{
    if (url != m_url) {
        m_url = url;
        emit urlChanged();
    }
}

WebRequestInfo::WebRequestInfo(QObject *parent)
    : QObject{parent}
{
}

WebRequestInfo::WebRequestInfo(const WebRequestInfo &other)
    : m_data(other.data())
    , contentType(other.getContentType())
    , m_url(other.url())
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

void WebRequestInfo::setRequestBodyType(const Types::RequestBody &type)
{
    if (type != m_requestBodyType) {
        m_requestBodyType = type;
        emit requestTypeChanged();
    }
}

Types::RequestBody WebRequestInfo::requestBodyType() const
{
    return m_requestBodyType;
}
