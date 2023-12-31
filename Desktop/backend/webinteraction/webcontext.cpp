#include "webcontext.h"

WebContext::WebContext(QObject *parent)
    : QObject{parent}
{

}

void WebContext::ignoreSslVerify()
{
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    QSslConfiguration::setDefaultConfiguration(config);
}

void WebContext::sendGetRequest(IWebRequestInfo *info)
{

}

void WebContext::sendPostRequest(IWebRequestInfo *info)
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

void WebContext::sendRequest(IWebRequestInfo *info)
{
    determineSuitableMethods(info->type(), info->bodyType());
    ((this)->*requestMethod)(info);
}
