#include "requestresponcehandling.h"

RequestResponceHandling::RequestResponceHandling(QObject *parent)
    : QObject{parent}
{    
}

void RequestResponceHandling::takeSubscriber(IWebResponceModel *newSubscriber,
                                             RequestEnums::Identifier identifier)
{
    // в случае если у нас еще не был отмечен переданный идентификатор
    // мы создаем новую запись в хэш-списке в виде нового списка,
    // проициниализированный одной записью - записью нашего нового подписчика
    if (!subscribers.contains(identifier)) {
        subscribers.insert(identifier, QList<IWebResponceModel *>{newSubscriber});
    }
    // если такой идентификатор уже существует, далее смотрим наличие или
    // отсутствие переданного подписчика в нем
    else {
        QList<IWebResponceModel *> currentList = subscribers.value(identifier);
        if (currentList.indexOf(newSubscriber) == -1) {
            subscribers[identifier].push_back(newSubscriber);
        }
    }
}

void RequestResponceHandling::processingResponce(QNetworkReply *reply,
                                                 RequestEnums::Identifier identifier)
{
    connect(reply, SIGNAL(finished()), this, SLOT(endOfProcessing()));
    // уведомляем подписчиков, что загрузка информации началась
    if (subscribers.contains(identifier)) {
        foreach (IWebResponceModel *responceModel, subscribers[identifier]) {
            responceModel->setIsLoading(true);
        }
    }
    // ставим ответ с идентификатором в условную очередь
    repliesWithIdentifiers.append(ReplyWithIdentifier(reply, identifier));

    // помимо связи основанной на окончании загрузки ответа, также
    // ниже в будущем можно будет поместить обработчик прогресса загрузки
}

void RequestResponceHandling::endOfProcessing()
{
    // берем готовый ответ и идентификатор из очереди
    ReplyWithIdentifier curReplyWithIdentifier = repliesWithIdentifiers.dequeue();
    QNetworkReply *curReply = curReplyWithIdentifier.getReply();
    RequestEnums::Identifier curIdentifier = curReplyWithIdentifier.getIdentifier();
    // обработка полученных данных для ответа
    QString replyError;
    QByteArray replyContent;
    if(curReply->error() == QNetworkReply::NoError){
        replyContent = curReply->readAll();
    }
    else{
        replyError = QString("%1%2").arg(curReply->errorString(),
                                         curReply->readAll());
    }
    // отправляем ответ и уведомляем, что загрузка/обработка информации закончилась
    if (subscribers.contains(curIdentifier)) {
        foreach (IWebResponceModel *responceModel, subscribers[curIdentifier]) {
            responceModel->setError(replyError);
            responceModel->setData(replyContent);
            responceModel->setIsLoading(false);
        }
    }
    // подчищаем всю использованную информацию и связи
    disconnect(curReply, SIGNAL(finished()), this, SLOT(endOfProcessing()));
    curReply->deleteLater();
}
