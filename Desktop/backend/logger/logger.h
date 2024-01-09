#ifndef LOGGER_H
#define LOGGER_H

#include "ILoggingObject.h"
#include <QDateTime>
#include <QObject>
#include <QQueue>

///
/// \brief The Logger class
/// основной класс для ведения лога
class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);

public slots:
    void log(QString message);

private:
    QString filePath;
    QQueue<QString> messages;
};

#endif // LOGGER_H
