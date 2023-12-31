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
