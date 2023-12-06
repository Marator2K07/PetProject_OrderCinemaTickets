#ifndef WEBCONTEXT_H
#define WEBCONTEXT_H

#include <QObject>
#include <QNetworkRequest>
#include <QNetworkReply>

///
/// \brief The WebContext class
/// основной класс для интернет взаимодействия приложения
class WebContext : public QObject
{
    Q_OBJECT
public:
    explicit WebContext(QObject *parent = nullptr);

signals:

};

#endif // WEBCONTEXT_H
