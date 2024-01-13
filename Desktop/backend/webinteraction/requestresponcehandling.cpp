#include "requestresponcehandling.h"

RequestResponceHandling::RequestResponceHandling(QObject *parent)
    : QObject{parent}
{    
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
