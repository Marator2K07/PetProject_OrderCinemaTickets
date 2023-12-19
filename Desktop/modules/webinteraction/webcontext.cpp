#include "webcontext.h"

WebContext::WebContext(WebRequestWidget *requestWidget, QObject *parent)
    : QObject{parent}
    , requestWidget{requestWidget}
{
    webManager = new QNetworkAccessManager(this);
    connect(webManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getResponce(QNetworkReply*)));
    connect(webManager, SIGNAL(finished(QNetworkReply*)),
            requestWidget, SLOT(catchWebResponseError(QNetworkReply*)));
    connect(requestWidget, SIGNAL(requestReady(QHash<QString, QVariant>)),
            this, SLOT(sendRequest(QHash<QString, QVariant>)));
    connect(requestWidget->getRequestMethodType(), SIGNAL(currentIndexChanged(int)),
            this, SLOT(changeRequestType(int)));
    connect(requestWidget->getMethodDataTypeComboBox(), SIGNAL(currentIndexChanged(int)),
            this, SLOT(changeRequestDataType(int)));
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
    QNetworkRequest request(requestInfo.url());
    webManager->get(request);
}

void WebContext::sendPostRequest(WebRequestInfo requestInfo)
{
    // ставим заголовок типа содержимого запроса
    QNetworkRequest request(requestInfo.url());
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      requestInfo.getContentType());
    // обрабатываем данные из тела запроса в определенном формате и отправляем их
    QByteArray data = ((this)->*handleRequestDataMethod)(requestInfo.data());
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

void WebContext::changeRequestType(int index)
{
    Types::Request type = (Types::Request)index;
    if (type == Types::Request::GET) {
        requestMethod = &sendGetRequest;
    } else if (type == Types::Request::POST) {
        requestMethod = &sendPostRequest;
    }
}

void WebContext::changeRequestDataType(int index)
{
    Types::RequestBody type = (Types::RequestBody)index;
    if (type == Types::RequestBody::TEXT) {
        handleRequestDataMethod = &handleRequestDataAsString;
    } else if (type == Types::RequestBody::JSON) {
        handleRequestDataMethod = &handleRequestDataAsJson;
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
