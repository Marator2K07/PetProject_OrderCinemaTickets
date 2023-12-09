#ifndef WEBCONTEXT_H
#define WEBCONTEXT_H

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
    explicit WebContext(QObject *parent = nullptr);
    ///
    /// \brief ignoreSslVerify
    /// дабы избежать множество проблем
    /// можно отключить Ssl верификацию
    void ignoreSslVerify();
    void changeRequestMethod(MethodType type);
    WebRequestWidget *getRequestWidget() const;
    void setRequestWidget(WebRequestWidget *newRequestWidget);

private:
    QNetworkAccessManager *webManager;
    // виджет для удобной отправки запросов
    WebRequestWidget *requestWidget;
    // ссылка на метод: sendGetRequest или sendPostRequest
    void(WebContext::*requestMethod)(WebRequestInfo) = &sendGetRequest;

    ///
    /// \brief sendGetRequest
    /// послать на адрес url GET запрос с данными requestInfo
    void sendGetRequest(WebRequestInfo requestInfo);
    ///
    /// \brief sendPostRequest
    /// послать на адрес url POST запрос с данными requestInfo
    void sendPostRequest(WebRequestInfo requestInfo);

private slots:
    ///
    /// \brief sendRequest
    /// послать запрос с установленными значениями
    void sendRequest(QHash<QString, QVariant> request);
    ///
    /// \brief getResponce
    /// получить и обработать возможный ответ
    void getResponce(QNetworkReply *responce);
};

#endif // WEBCONTEXT_H
