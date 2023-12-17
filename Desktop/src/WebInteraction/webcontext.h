#ifndef WEBCONTEXT_H
#define WEBCONTEXT_H

#include "typesforrequestmethod.h"
#include "webrequestinfo.h"
#include "webrequestwidget.h"

#include <QDebug>
#include <QByteArray>
#include <QDataStream>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QSslConfiguration>

///
/// \brief The WebContext class
/// основной класс для интернет взаимодействия приложения
class WebContext : public QObject
{
    Q_OBJECT

public:
    explicit WebContext(WebRequestWidget *requestWidget, QObject *parent = nullptr);
    ///
    /// \brief ignoreSslVerify
    /// дабы избежать множество проблем
    /// можно отключить/игнорировать Ssl верификацию
    void ignoreSslVerify();
    WebRequestWidget *getRequestWidget() const;
    void setRequestWidget(WebRequestWidget *newRequestWidget);

private:
    QNetworkAccessManager *webManager;
    // виджет для удобной отправки запросов
    WebRequestWidget *requestWidget;

    // указатель на посылаемый метод с типом: sendGetRequest или sendPostRequest
    void(WebContext::*requestMethod)(WebRequestInfo) = &sendGetRequest;
    void sendGetRequest(WebRequestInfo requestInfo);
    void sendPostRequest(WebRequestInfo requestInfo);

    // указатель на метод обработки данных в определенном формате
    // (методы: handleRequestDataAsString и handleRequestDataAsJson)
    QByteArray(WebContext::*handleRequestDataMethod)(QVariant) = &handleRequestDataAsString;
    QByteArray handleRequestDataAsString(QVariant data);
    QByteArray handleRequestDataAsJson(QVariant data);

private slots:
    void changeRequestType(int index);
    void changeRequestDataType(int index);
    ///
    /// \brief sendRequest
    /// этот метод напрямую не вызывает посылку запроса,а служит промежуточным
    /// звеном, где с помощью переменной requestMethod уже вызывается нужный метод
    void sendRequest(QHash<QString, QVariant> request);
    void getResponce(QNetworkReply *responce);

signals:
    void webResponceReady(QNetworkReply *responce);
};

#endif // WEBCONTEXT_H
