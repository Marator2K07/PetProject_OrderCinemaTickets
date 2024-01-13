#include "webcontext.h"

WebContext::WebContext(QObject *parent)
    : QObject{parent}
{
    webManager = new QNetworkAccessManager(this);
    // В случае будущей надобности обработки ssl ошибок
    /*
    #ifndef QT_NO_SSL
        connect(webManager, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)),
                SLOT(slotSslErrors(QNetworkReply*,QList<QSslError>)));
    #endif
    */
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
    // вместе с отправкой запроса посылаем сигнал
    emit startProcessingReply(webManager->get(request), info->identifier());
}

void WebContext::sendPostRequest(IWebRequestModel *info)
{
    QNetworkRequest request(info->url());
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      info->contentType());
    QByteArray data = ((this)->*handleRequestDataMethod)(info->data());
    // вместе с отправкой запроса посылаем сигнал
    emit startProcessingReply(webManager->post(request, data), info->identifier());
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
    ((this)->*requestMethod)(info);    
}
