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

void WebContext::sendRequest(QString url, WebRequestBody requestBody)
{
    ((this)->*requestMethod)(url, requestBody);
}

void WebContext::changeRequestMethod(MethodType type)
{
    if (type == MethodType::GET) {
        requestMethod = &sendGetRequest;
    } else if (type == MethodType::POST) {
        requestMethod = &sendPostRequest;
    }
    webManager->get(request);
}

void WebContext::sendPostRequest(QString url, QJsonObject jsonObject)
{
    // ставим заголовок типа файла
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    // составляем джейсон документ и отправляем его
    QJsonDocument doc(jsonObject);
    QByteArray data = doc.toJson();
    webManager->post(request, data);
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
