#ifndef REQUESTRESPONCEHANDLING_H
#define REQUESTRESPONCEHANDLING_H

#include "IWebRequestModel.h"
#include <QNetworkReply>
#include <QObject>
#include <QDebug>
#include <QHash>

///
/// \brief The RequestResponceHandling class
/// класс посредник для обработки ответа на запрос
/// и отправки его конкретному обьекту ответа
class RequestResponceHandling : public QObject
{
    Q_OBJECT
public:
    explicit RequestResponceHandling(QObject *parent = nullptr);

private slots:
    // начало обработки ответа пришедшего от веб контекста
    void processingResponce(QNetworkReply *reply);
};

#endif // REQUESTRESPONCEHANDLING_H
