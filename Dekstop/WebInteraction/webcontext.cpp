#include "webcontext.h"

WebContext::WebContext(QObject *parent)
    : QObject{parent}
{
    webManager = new QNetworkAccessManager(this);
    connect(webManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getResponce(QNetworkReply*)));
}

void WebContext::sendRequest(QString url, QList<QString> params)
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

void WebContext::getResponce(QNetworkReply *responce)
{
    // пока просто тестовый вывод в консоль
    qDebug() << responce->readAll();
}
