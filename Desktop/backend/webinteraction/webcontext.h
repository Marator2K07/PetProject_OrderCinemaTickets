#ifndef WEBCONTEXT_H
#define WEBCONTEXT_H

#include "RequestType.h"
#include "RequestBodyType.h"
#include "IWebRequestInfo.h"

#include <QDebug>
#include <QObject>
#include <QByteArray>
#include <QDataStream>
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
    void(WebContext::*requestMethod)(IWebRequestInfo *);
    void sendGetRequest(IWebRequestInfo *info);
    void sendPostRequest(IWebRequestInfo *info);

    // указатель на метод обработки данных в определенном формате
    // (методы: handleRequestDataAsString и handleRequestDataAsJson)
    QByteArray(WebContext::*handleRequestDataMethod)(QVariant);
    QByteArray handleRequestDataAsString(QVariant data);
    QByteArray handleRequestDataAsJson(QVariant data);

signals:

};

#endif // WEBCONTEXT_H
