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
    replies.append(reply);
    // помимо связи основанной на окончании загрузки ответа, также
    // ниже в будущем можно будет поместить обработчик прогресса загрузки
}

void RequestResponceHandling::endOfProcessing()
{
    // 1) берем самый первый ответ в очереди
    QNetworkReply *curReply = replies.dequeue();

    // 2) Обработка данных и их отправка (через сигнал)
    // пока просто тестовый вывод в консоль
    if(curReply->error() == QNetworkReply::NoError){
        QString contents = QString::fromUtf8(curReply->readAll());
        qDebug() << contents;
    }
    else{
        QString err = curReply->errorString();
        qDebug() << err;
    }

    // 3) Убираем всю лишнюю информацию и связи
    disconnect(curReply, SIGNAL(finished()), this, SLOT(endOfProcessing()));
    curReply->deleteLater();
}
