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

void WebContext::sendRequest(QHash<QString, QVariant> request)
{
    // готовим данные
    QString url = qvariant_cast<QString>(request.value("Url"));
    QString contentType = qvariant_cast<QString>(request.value("Content type"));
    QVariant data = request.value("Data");
    // составляем обьект с информацией и отправляем уже куда надо
    WebRequestInfo requestInfo;
    requestInfo.setUrl(url);
    requestInfo.setContentType(contentType);
    requestInfo.setData(data);
    ((this)->*requestMethod)(requestInfo);
}

void WebContext::changeRequestMethod(MethodType type)
WebRequestWidget *WebContext::getRequestWidget() const
{
    if (type == MethodType::GET) {
        requestMethod = &sendGetRequest;
    } else if (type == MethodType::POST) {
        requestMethod = &sendPostRequest;
    }
    return requestWidget;
}

void WebContext::setRequestWidget(WebRequestWidget *newRequestWidget)
{
    requestWidget = newRequestWidget;
}

void WebContext::sendGetRequest(WebRequestInfo requestInfo)
{
    QNetworkRequest request(requestInfo.getUrl());
    webManager->get(request);
}

void WebContext::sendPostRequest(WebRequestInfo requestInfo)
{
    // ставим заголовок типа содержимого запроса
    QNetworkRequest request(requestInfo.getUrl());
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      requestInfo.getContentType());
    // пишем данные из тела запроса и отправляем их
    QByteArray data;
    QDataStream ds(&data, QIODevice::ReadWrite);
    ds << requestInfo.getData();
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
