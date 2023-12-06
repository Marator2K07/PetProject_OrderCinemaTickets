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

signals:

};

#endif // WEBCONTEXT_H
