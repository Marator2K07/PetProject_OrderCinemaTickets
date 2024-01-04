#include "webcontext.h"

WebContext::WebContext(QObject *parent)
    : QObject{parent}
{
    webManager = new QNetworkAccessManager(this);
}

void WebContext::ignoreSslVerify()
{
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    QSslConfiguration::setDefaultConfiguration(config);
}

void WebContext::sendGetRequest(IWebRequestModel *info)
{
    QNetworkRequest request(info->url());
    webManager->get(request);
}

void WebContext::sendPostRequest(IWebRequestModel *info)
{
    QNetworkRequest request(info->url());
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      info->contentType());
    QByteArray data = ((this)->*handleRequestDataMethod)(info->data());
    webManager->post(request, data);
}

QByteArray WebContext::handleRequestDataAsString(QVariant data)
{
    QString str = data.toString();
    return str.toUtf8();
}

QByteArray WebContext::handleRequestDataAsJson(QVariant data)
{
    QJsonObject json = data.toJsonObject();
    QJsonDocument doc(json);
    return doc.toJson();
}

void WebContext::determineSuitableMethods(RequestEnums::Type type,
                                          RequestEnums::DataType bodyType)
{
    // выбор типа метода отправки
    switch (type) {
    case RequestEnums::Type::GET:
    {
        requestMethod = &sendGetRequest;
        break;
    }
    case RequestEnums::Type::POST:
    {
        requestMethod = &sendPostRequest;
        break;
    }
    default:
        break;
    }
    // выбор метода типа управления данными запроса
    switch (bodyType) {
    case RequestEnums::DataType::TEXT:
    {
        handleRequestDataMethod = &handleRequestDataAsString;
        break;
    }
    case RequestEnums::DataType::JSON:
    {
        handleRequestDataMethod = &handleRequestDataAsJson;
        break;
    }
    default:
        break;
    }
}

void WebContext::sendRequest(IWebRequestModel *info)
{
    determineSuitableMethods(info->type(), info->bodyType());
    // вместе с отправкой запроса посылаем сигнал
    // с веб менеджером для дальнейшей обработки
    ((this)->*requestMethod)(info);
    emit startProcessingReply(webManager);
}
