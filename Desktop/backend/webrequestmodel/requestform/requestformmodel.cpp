#include "requestformmodel.h"

bool RequestFormModel::correctDataAsText()
{
    QString data = qvariant_cast<QString>(m_data);
    // проверка на корректность текста пока довольно условна
    if (data.length() >= 1) {
        emit updateInfo("Request data as text is correct.");
        return true;
    } else {
        emit updateInfo("Request data as text is too short.");
        return false;
    }
}

bool RequestFormModel::correctDataAsJson()
{
    // пытаемся запарсить
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::
        fromJson(QString(qvariant_cast<QString>(m_data)).toUtf8(), &error);
    // возвращаем успешность парсинга
    if (error.error == error.NoError) {
        emit updateInfo("Request data as json is correct.");
        return true;
    } else {
        emit updateInfo(error.errorString());
        return false;
    }
}

bool RequestFormModel::isValid()
{
    // не помешает и такая банальная проверка
    if (!m_url.contains("https://") && !m_url.contains("http://")) {
        emit updateInfo("Incorrect request url adress.");
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
    emit updateInfo("Request has been sended.");
    return true;
}

void RequestFormModel::setContentType(const QString &contentType)
{
    if (contentType != m_contentType) {
        m_contentType = contentType;
        emit contentTypeChanged(contentType);
    }
}

QString RequestFormModel::contentType() const
{
    return m_contentType;
}

void RequestFormModel::setData(const QVariant &data)
{
    if (data != m_data) {
        m_data = data;
        emit dataChanged(data);
    }
}

QVariant RequestFormModel::data() const
{
    return m_data;
}

RequestFormModel::~RequestFormModel()
{
}

void RequestFormModel::send(const IWebRequestModel *)
{
    if (isValid()) {
        emit requestIsReady(this);
    }
}

QString RequestFormModel::url() const
{
    return m_url;
}

void RequestFormModel::setUrl(const QString &url)
{
    if (url != m_url) {
        m_url = url;
        emit urlChanged(url);
    }
}

RequestFormModel::RequestFormModel(QObject *parent)
    : QObject{parent}
{
}

RequestFormModel::RequestFormModel(const RequestFormModel &other)
    : m_data(other.data())
    , m_contentType(other.contentType())
    , m_url(other.url())
{
}

void RequestFormModel::setType(const RequestEnums::Type &type)
{
    if (type != m_type) {
        m_type = type;
        emit typeChanged(type);
    }
}

RequestEnums::Type RequestFormModel::type() const
{
    return m_type;
}

void RequestFormModel::setBodyType(const RequestEnums::DataType &type)
{
    if (type != m_bodyType) {
        m_bodyType = type;
        emit bodyTypeChanged(type);
    }
}

RequestEnums::DataType RequestFormModel::bodyType() const
{
    return m_bodyType;
}

void RequestFormModel::setIdentifier(const RequestEnums::Identifier &identifier)
{
    if (identifier != m_identifier) {
        m_identifier = identifier;
        emit identifierChanged(identifier);
    }
}

RequestEnums::Identifier RequestFormModel::identifier() const
{
    return m_identifier;
}
