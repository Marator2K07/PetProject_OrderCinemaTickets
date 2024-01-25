#ifndef REQUESTRESPONCEHANDLING_H
#define REQUESTRESPONCEHANDLING_H

#include "IWebResponceModel.h"
#include "RequestEnums.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QDebug>
#include <QQueue>
#include <QHash>
#include <QList>

class IWebResponceModel;

///
/// \brief The RequestResponceHandling class
/// класс посредник для обработки ответа на запрос
/// и отправки его конкретному обьекту модели ответа
class RequestResponceHandling : public QObject
{
    Q_OBJECT
public:
    explicit RequestResponceHandling(QObject *parent = nullptr);
    // подключаем модель ответа для получения информации
    void takeSubscriber(IWebResponceModel *newSubscriber,
                        RequestEnums::Identifier identifier);

private:
    // обрабатываемые в ходе запросов веб-ответы
    QQueue<QNetworkReply *> replies;
    // хэш-список подписчиков (моделей, готовых получать ответ)
    QHash<RequestEnums::Identifier, QList<IWebResponceModel *>> subscribers;

private slots:
    // начало обработки ответа пришедшего от веб контекста
    void processingResponce(QNetworkReply *reply,
                            RequestEnums::Identifier identifier);
    // выполняется при окончании обработки ответа,
    // то есть когда он будет доступен
    void endOfProcessing();

signals:
    // при полном получении ответа
    void responceReady(IWebResponceModel *);
};

#endif // REQUESTRESPONCEHANDLING_H
