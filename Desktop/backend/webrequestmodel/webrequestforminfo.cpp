#include "webrequestforminfo.h"

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
    if (m_type == RequestEnums::Type::POST) {
        // парсим в соотвествии с типом
        switch (m_bodyType) {
        case RequestEnums::DataType::TEXT:
            correctData = correctDataAsText();
            break;
        case RequestEnums::DataType::JSON:
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

void WebRequestFormInfo::setContentType(const QString &contentType)
{
    if (contentType != m_contentType) {
        m_contentType = contentType;
        emit contentTypeChanged(contentType);
    }
}

QString WebRequestFormInfo::contentType() const
{
    return m_contentType;
}

void WebRequestFormInfo::setData(const QVariant &data)
{
    if (data != m_data) {
        m_data = data;
        emit dataChanged(data);
    }
}

QVariant WebRequestFormInfo::data() const
{
    return m_data;
}

WebRequestFormInfo::~WebRequestFormInfo()
{
}

void WebRequestFormInfo::send(const IWebRequestModel *)
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
        emit urlChanged(url);
    }
}

WebRequestFormInfo::WebRequestFormInfo(QObject *parent)
    : QObject{parent}
{
}

WebRequestFormInfo::WebRequestFormInfo(const WebRequestFormInfo &other)
    : m_data(other.data())
    , m_contentType(other.contentType())
    , m_url(other.url())
{
}

void WebRequestFormInfo::setType(const RequestEnums::Type &type)
{
    if (type != m_type) {
        m_type = type;
        emit typeChanged(type);
    }
}

RequestEnums::Type WebRequestFormInfo::type() const
{
    return m_type;
}

void WebRequestFormInfo::setBodyType(const RequestEnums::DataType &type)
{
    if (type != m_bodyType) {
        m_bodyType = type;
        emit bodyTypeChanged(type);
    }
}

RequestEnums::DataType WebRequestFormInfo::bodyType() const
{
    return m_bodyType;
}

void WebRequestFormInfo::setIdentifier(const RequestEnums::Identifier &identifier)
{
    if (identifier != m_identifier) {
        m_identifier = identifier;
        emit identifierChanged(identifier);
    }
}

RequestEnums::Identifier WebRequestFormInfo::identifier() const
{
    return m_identifier;
}
