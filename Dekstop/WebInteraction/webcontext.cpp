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

void WebContext::sendGetRequest(QString url, QList<QString> params)
{
    // конфигурируем строку запроса
    QString fullUrl = url;
    if (params.size() != 0) {
        fullUrl += "?";
        for (const QString &param : params) {
            fullUrl += param + "&";
        }
        fullUrl.chop(1);
    }
    // посылаем запрос
    QNetworkRequest request(fullUrl);
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
