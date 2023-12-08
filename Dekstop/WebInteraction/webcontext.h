#ifndef WEBCONTEXT_H
#define WEBCONTEXT_H

#include "webrequestbody.h"
#include "MethodType.h"

#include <QDebug>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonParseError>
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

public:
    ///
    /// \brief sendRequest
    /// послать запрос с установленными значениями
    void sendRequest(QString url,
                     WebRequestBody data);
    void changeRequestMethod(MethodType type);

private:
    QNetworkAccessManager *webManager;
    // ссылка на метод: sendGetRequest или sendPostRequest
    void(WebContext::*requestMethod)
        (QString, WebRequestBody) = &sendGetRequest;

    ///
    /// \brief sendRequest
    /// послать на адрес url GET запрос с
    /// параметрами params и телом запроса requestBody
    void sendGetRequest(QString url, WebRequestBody requestBody);
    ///
    /// \brief sendPostRequest
    /// послать на адрес url POST запрос с
    /// параметрами params и телом запроса requestBody
    void sendPostRequest(QString url, WebRequestBody requestBody);

private slots:
    ///
    /// \brief getResponce
    /// получить и обработать возможный ответ
    void getResponce(QNetworkReply *responce);
};

#endif // WEBCONTEXT_H
