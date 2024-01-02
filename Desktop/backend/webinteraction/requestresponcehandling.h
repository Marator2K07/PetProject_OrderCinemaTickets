#ifndef REQUESTRESPONCEHANDLING_H
#define REQUESTRESPONCEHANDLING_H

#include <QObject>

///
/// \brief The RequestResponceHandling class
/// класс посредник для обработки ответа на запрос
/// и отправки его конкретному обьекту ответа
class RequestResponceHandling : public QObject
{
    Q_OBJECT
public:
    explicit RequestResponceHandling(QObject *parent = nullptr);

signals:

};

#endif // REQUESTRESPONCEHANDLING_H
