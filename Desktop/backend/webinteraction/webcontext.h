#ifndef WEBCONTEXT_H
#define WEBCONTEXT_H

#include "RequestType.h"
#include "RequestBodyType.h"
#include "IWebRequestModel.h"

#include <QDebug>
#include <QObject>
#include <QByteArray>
#include <QDataStream>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QSslConfiguration>
#include <QNetworkAccessManager>

///
/// \brief The WebContext class
/// Основной класс-посредник для интернет взаимодействия
class WebContext : public QObject
{
    Q_OBJECT
public:
    explicit WebContext(QObject *parent = nullptr);
    ///
    /// \brief ignoreSslVerify
    /// дабы избежать множество проблем
    /// можно отключить/игнорировать Ssl верификацию
    void ignoreSslVerify();

private:
    QNetworkAccessManager *webManager;
    // указатель на метод отправки запроса:
    // (методы: sendGetRequest или sendPostRequest)
    void(WebContext::*requestMethod)(IWebRequestModel *);
    // указатель на метод обработки данных в определенном формате
    // (методы: handleRequestDataAsString и handleRequestDataAsJson)
    QByteArray(WebContext::*handleRequestDataMethod)(QVariant);

private:
    void sendGetRequest(IWebRequestModel *info);
    void sendPostRequest(IWebRequestModel *info);
    QByteArray handleRequestDataAsString(QVariant data);
    QByteArray handleRequestDataAsJson(QVariant data);
    ///
    /// \brief determineSuitableMethods
    /// определяем подходящие данные данные для
    /// requestMethod и handleRequestDataMethod
    void determineSuitableMethods(RequestType::State type,
                                  RequestBodyType::State bodyType);

private slots:
    void sendRequest(IWebRequestModel *info);
    void getResponce(QNetworkReply *responce);

signals:

};

#endif // WEBCONTEXT_H
