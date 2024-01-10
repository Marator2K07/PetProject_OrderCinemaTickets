#ifndef REQUESTRESPONCEHANDLING_H
#define REQUESTRESPONCEHANDLING_H

#include "IWebResponceModel.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QDebug>
#include <QQueue>
#include <QHash>

///
/// \brief The RequestResponceHandling class
/// класс посредник для обработки ответа на запрос
/// и отправки его конкретному обьекту модели ответа
class RequestResponceHandling : public QObject
{
    Q_OBJECT
public:
    explicit RequestResponceHandling(QObject *parent = nullptr);

private:
    // пришедшие запросы
    QQueue<QNetworkReply *> replies;

private slots:
    // начало обработки ответа пришедшего от веб контекста
    void processingResponce(QNetworkReply *reply);
    // выполняется при окончании обработки ответа, то есть
    // когда он будет доступен для доступа
    void endOfProcessing();

signals:
    // при полном получении ответа
    void responceReady(IWebResponceModel *);
};

#endif // REQUESTRESPONCEHANDLING_H
