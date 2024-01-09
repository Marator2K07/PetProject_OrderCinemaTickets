#include "logger.h"

Logger::Logger(QObject *parent)
    : QObject{parent}
{
}

void Logger::log(QString message)
{
    // не помешает добавить время к логируемому сообщению
    QString curTime = QDateTime::currentDateTime().
                      toString("dd.MM.yyyy hh:mm:ss");
    QString newMessage = QString("1%; message: 2%").
                         arg(curTime, message);
    messages.append(newMessage);
}
