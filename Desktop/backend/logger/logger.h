#ifndef LOGGER_H
#define LOGGER_H

#include "ILoggingObject.h"
#include <QTextStream>
#include <QDateTime>
#include <QObject>
#include <QQueue>
#include <QFile>

///
/// \brief The Logger class
/// основной класс для ведения лога
class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);
    Logger(const QString &fileName,
           const QString &filePath,
           QObject *parent = nullptr);

    QString getFilePath() const;
    void setFilePath(const QString &newFilePath);
    QString getFileName() const;
    void setFileName(const QString &newFileName);

public slots:
    void log(QString message);
    // сохранение всех оставшихся/накопившихся
    // сообщений в поле класса messages
    void save();

private:
    QString fileName;
    QString filePath;
    QQueue<QString> messages;

private slots:
    void onExit();

signals:
    // главный обьект логгера может посылать
    // сигналы всем подписчикам(моделям - логгерам)
    void showMessage(const QString);
};

#endif // LOGGER_H
