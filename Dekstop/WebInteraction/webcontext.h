#ifndef WEBCONTEXT_H
#define WEBCONTEXT_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>

///
/// \brief The WebContext class
/// основной класс для интернет взаимодействия приложения
class WebContext : public QObject
{
    Q_OBJECT

private:
    QNetworkAccessManager *webManager;

public:
    explicit WebContext(QObject *parent = nullptr);

public slots:
    ///
    /// \brief sendRequest
    /// послать на адрес url запрос с параметрами params
    void sendRequest(QString url, QList<QString> params);
    void getResponce(QNetworkReply *responce);

};

#endif // WEBCONTEXT_H
