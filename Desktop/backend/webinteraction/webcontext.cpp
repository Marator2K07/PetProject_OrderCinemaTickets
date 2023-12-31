#include "webcontext.h"

WebContext::WebContext(QObject *parent)
    : QObject{parent}
{
    webManager = new QNetworkAccessManager(this);
    connect(webManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getResponce(QNetworkReply*)));
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

void WebContext::determineSuitableMethods(RequestType::State type,
                                          RequestBodyType::State bodyType)
{
    // выбор типа метода отправки
    switch (type) {
    case RequestType::State::GET:
    {
        requestMethod = &sendGetRequest;
        break;
    }
    case RequestType::State::POST:
    {
        requestMethod = &sendPostRequest;
        break;
    }
    default:
        break;
    }
    // выбор метода типа управления данными запроса
    switch (bodyType) {
    case RequestBodyType::State::TEXT:
    {
        handleRequestDataMethod = &handleRequestDataAsString;
        break;
    }
    case RequestBodyType::State::JSON:
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

void WebContext::getResponce(QNetworkReply *responce)
{
    // пока просто тестовый вывод в консоль
    if(responce->error() == QNetworkReply::NoError){
        QString contents = QString::fromUtf8(responce->readAll());
        qDebug() << contents;
    }
    else{
        QString err = responce->errorString();
        qDebug() << err;
    }
}
