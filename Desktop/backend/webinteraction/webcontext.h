#ifndef WEBCONTEXT_H
#define WEBCONTEXT_H

#include <QObject>

///
/// \brief The WebContext class
/// Основной класс-посредник для интернет взаимодействия
class WebContext : public QObject
{
    Q_OBJECT
public:
    explicit WebContext(QObject *parent = nullptr);

signals:

};

#endif // WEBCONTEXT_H
