#ifndef REQUESTRESPONCEHANDLING_H
#define REQUESTRESPONCEHANDLING_H

#include "IWebResponceModel.h"

#include <QNetworkAccessManager>
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

private:
    // пока ничего

private slots:
    // начало обработки ответа пришедшего от веб контекста
    void processingResponce(QNetworkAccessManager *manager);
    // выполняется при окончании обработки ответа, то есть
    // когда он будет доступен для доступа
    void endOfProcessing(QNetworkReply *reply);

signals:
    // при полном получении ответа
    void responceReady(IWebResponceModel *);
};

#endif // REQUESTRESPONCEHANDLING_H
