#ifndef WEBCONTEXT_H
#define WEBCONTEXT_H

#include "RequestEnums.h"
#include "IWebRequestModel.h"

#include <QObject>
#include <QByteArray>
#include <QDataStream>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QSslConfiguration>
#include <QNetworkAccessManager>

/// Важное примечание:
/// для корректной работы данного класса, особенно
/// при связи с https ресурсами, необходимо установить
/// OpenSSL библиотеки новым или старым способом

///
/// \brief The WebContext class
/// основной класс для интернет взаимодействия
class WebContext : public QObject
{
    Q_OBJECT
public:
    explicit WebContext(QObject *parent = nullptr);
    // дабы избежать проблемы на стадии
    // разработки можно игнорировать Ssl ошибки
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
    // определяем подходящие данные данные для
    // requestMethod и handleRequestDataMethod
    void determineSuitableMethods(RequestEnums::Type type,
                                  RequestEnums::DataType bodyType);

public slots:
    void sendRequest(IWebRequestModel *info);

signals:
    // т.к. ответ обрабатывается не мгновенно, есть
    // возможность послать его для дальнейшего управления
    void startProcessingReply(QNetworkReply *);
};

#endif // WEBCONTEXT_H
