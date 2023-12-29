#include "webrequestforminfo.h"

QJsonObject WebRequestFormInfo::getJsonData() const
{
    return qvariant_cast<QJsonObject>(m_data);
}

QString WebRequestFormInfo::getTextData() const
{
    return qvariant_cast<QString>(m_data);
}

QString WebRequestFormInfo::getContentType() const
{
    return contentType;
}

void WebRequestFormInfo::setContentType(const QString &newContentType)
{
    contentType = newContentType;
}

void WebRequestFormInfo::setData(const QVariant &data)
{
    if (data != m_data) {
        m_data = data;
        emit dataChanged();
    }
}

QVariant WebRequestFormInfo::data() const
{
    return m_data;
}

QString WebRequestFormInfo::url() const
{
    return m_url;
}

void WebRequestFormInfo::setUrl(const QString &url)
{
    if (url != m_url) {
        m_url = url;
        emit urlChanged();
    }
}

WebRequestFormInfo::WebRequestFormInfo(QObject *parent)
    : QObject{parent}
{
}

WebRequestFormInfo::WebRequestFormInfo(const WebRequestFormInfo &other)
    : m_data(other.data())
    , contentType(other.getContentType())
    , m_url(other.url())
{
}

void WebRequestFormInfo::setRequestType(const RequestType::State &type)
{
    if (type != m_requestType) {
        m_requestType = type;
        emit requestTypeChanged();
    }
}

RequestType::State WebRequestFormInfo::requestType() const
{
    return m_requestType;
}

void WebRequestFormInfo::setRequestBodyType(const RequestBodyType::State &type)
{
    if (type != m_requestBodyType) {
        m_requestBodyType = type;
        emit requestTypeChanged();
    }
}

RequestBodyType::State WebRequestFormInfo::requestBodyType() const
{
    return m_requestBodyType;
}
