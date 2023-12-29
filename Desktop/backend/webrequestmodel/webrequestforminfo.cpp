#include "webrequestforminfo.h"

QJsonObject WebRequestFormInfo::getJsonData() const
{
    return qvariant_cast<QJsonObject>(m_data);
}

QString WebRequestFormInfo::getTextData() const
{
    return qvariant_cast<QString>(m_data);
}

bool WebRequestFormInfo::correctDataAsText()
{
    QString data = qvariant_cast<QString>(m_data);
    // проверка на корректность текста пока довольно условна
    if (data.length() >= 1) {
        emit updateStatus("Data as text is correct.");
        return true;
    } else {
        emit updateStatus("Data as text is too short.");
        return false;
    }
}

bool WebRequestFormInfo::correctDataAsJson()
{
    // пытаемся запарсить
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::
        fromJson(QString(qvariant_cast<QString>(m_data)).toUtf8(), &error);
    // возвращаем успешность парсинга
    if (error.error == error.NoError) {
        emit updateStatus("Data as json is correct.");
        return true;
    } else {
        emit updateStatus(error.errorString());
        return false;
    }
}

bool WebRequestFormInfo::isValid()
{
    // не помешает и такая банальная проверка
    if (m_url.length() <= 1) {
        emit updateStatus("To short request url adress.");
        return false;
    }

    bool correctData = true;
    // если POST запрос, то нужна дополнительная обработка
    if (m_requestType == RequestType::State::POST) {
        // парсим в соотвествии с типом
        switch (m_requestBodyType) {
        case RequestBodyType::State::TEXT:
            correctData = correctDataAsText();
            break;
        case RequestBodyType::State::JSON:
            correctData = correctDataAsJson();
            break;
        default:
            break;
        }
    }
    // если была ошибка на предыдущем этапе, то запрос отправлять нет смысла
    if (!correctData) {
        return false;
    }
    // если дошли до сюда, то все прошло хорошо
    emit updateStatus("Request is valid.");
    return true;
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

void WebRequestFormInfo::send(const IWebRequestInfo *)
{
    if (isValid()) {
        emit requestIsReady(this);
    }
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
