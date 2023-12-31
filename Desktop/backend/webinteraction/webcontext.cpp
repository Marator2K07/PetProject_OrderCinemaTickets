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

}

void WebContext::sendPostRequest(IWebRequestModel *info)
{

}

QByteArray WebContext::handleRequestDataAsString(QVariant data)
{

}

QByteArray WebContext::handleRequestDataAsJson(QVariant data)
{

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
