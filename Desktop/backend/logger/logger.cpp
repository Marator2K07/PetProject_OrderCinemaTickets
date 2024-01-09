#include "logger.h"

Logger::Logger(QObject *parent)
    : QObject{parent}
    , fileName{"app_log.txt"}
    , filePath{"/"}
{
}

Logger::Logger(const QString &fileName,
               const QString &filePath,
               QObject *parent)
    : QObject{parent}
    , fileName{fileName}
    , filePath{filePath}
{
}

void Logger::log(QString message)
{
    // не помешает добавить время к логируемому сообщению
    QString curTime = QDateTime::currentDateTime().
                      toString("dd.MM.yyyy hh:mm:ss");
    QString newMessage = QString("[1%] message: 2%").
                         arg(curTime, message);
    messages.append(newMessage);
}

void Logger::save()
{
    QFile file(filePath+fileName);
    // при успешном открытии файла мы освобождаем очередь
    // из сообщений и записываем каждое в файл лога
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream stream(&file);
        while (messages.size() > 0) {
            stream << messages.dequeue() << "\n";
        }
    } else {
        emit messageReady("Error occurred while saving the log file.");
        emit messageReady("Incorrect data for path/file name.\n");
    }
    file.close();
}

void Logger::onExit()
{
    log("End of work session");
    save();
}

QString Logger::getFileName() const
{
    return fileName;
}

void Logger::setFileName(const QString &newFileName)
{
    fileName = newFileName;
}

QString Logger::getFilePath() const
{
    return filePath;
}

void Logger::setFilePath(const QString &newFilePath)
{
    filePath = newFilePath;
}
