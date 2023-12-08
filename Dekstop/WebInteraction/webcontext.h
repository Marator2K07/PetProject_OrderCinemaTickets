#ifndef WEBCONTEXT_H
#define WEBCONTEXT_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QByteArray>
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

private:
    QNetworkAccessManager *webManager;

public slots:
    ///
    /// \brief sendRequest
    /// послать на адрес url GET запрос с параметрами params
    void sendGetRequest(QString url, QList<QString> params);
    ///
    /// \brief sendPostRequest
    /// послать на адрес url POST запрос с телом jsonObject
    void sendPostRequest(QString url, QJsonObject jsonObject);
    void getResponce(QNetworkReply *responce);

};

#endif // WEBCONTEXT_H
