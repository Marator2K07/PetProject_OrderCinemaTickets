#include "webcontext.h"

WebContext::WebContext(WebRequestWidget *requestWidget, QObject *parent)
    : QObject{parent}
    , requestWidget{requestWidget}
{
    webManager = new QNetworkAccessManager(this);
    connect(webManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getResponce(QNetworkReply*)));
    connect(requestWidget, SIGNAL(requestReady(QHash<QString, QVariant>)),
            this, SLOT(sendRequest(QHash<QString, QVariant>)));
    connect(requestWidget->getRequestMethodType(), SIGNAL(currentIndexChanged(int)),
            this, SLOT(changeRequestType(int)));
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

WebRequestWidget *WebContext::getRequestWidget() const
{
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

    // Тестовый участок, который в дальнейшем будет вынесен
    // в отдельный метод
    QByteArray data;
    QJsonObject json = requestInfo.getJsonData();
    QJsonDocument doc(json);
    data = doc.toJson();

    webManager->post(request, data);
}

void WebContext::changeRequestType(int index)
{
    MethodType type = (MethodType)index;
    if (type == MethodType::GET) {
        requestMethod = &sendGetRequest;
    } else if (type == MethodType::POST) {
        requestMethod = &sendPostRequest;
    }
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
