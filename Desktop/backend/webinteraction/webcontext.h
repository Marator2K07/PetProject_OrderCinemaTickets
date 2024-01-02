#ifndef WEBCONTEXT_H
#define WEBCONTEXT_H

#include "RequestEnums.h"
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
    void determineSuitableMethods(RequestEnums::Type type,
                                  RequestEnums::DataType bodyType);

private slots:
    void sendRequest(IWebRequestModel *info);
    void getResponce(QNetworkReply *responce);

signals:
    // т.к. ответ обрабатывается не мгновенно, есть
    // возможность послать его для дальнейшего управления
    void startProcessingReply(QNetworkReply *);
};

#endif // WEBCONTEXT_H
