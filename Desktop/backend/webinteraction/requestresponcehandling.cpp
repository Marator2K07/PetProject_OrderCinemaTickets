#include "requestresponcehandling.h"

RequestResponceHandling::RequestResponceHandling(QObject *parent)
    : QObject{parent}
{    
}

void RequestResponceHandling::processingResponce(QNetworkAccessManager *manager)
{
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(endOfProcessing(QNetworkReply*)));
    // помимо связи основанной на окончании загрузки ответа, также
    // ниже в будущем можно будет поместить обработчик прогресса загрузки
}

void RequestResponceHandling::endOfProcessing(QNetworkReply *reply)
{
    // пока просто тестовый вывод в консоль
    if(reply->error() == QNetworkReply::NoError){
        QString contents = QString::fromUtf8(reply->readAll());
        qDebug() << contents;
    }
    else{
        QString err = reply->errorString();
        qDebug() << err;
    }
}
