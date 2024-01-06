#ifndef ILOGGERMODEL_H
#define ILOGGERMODEL_H

#include <QQueue>

///
/// \brief The ILoggerModel interface
/// для организации функциональности логгера приложения
class ILoggerModel
{
public:
    // каждый логгер содержит путь для сохранения данных
    virtual void setPath(const QString &path) = 0;
    virtual QString path() const = 0;
    // каждый логгер содержит в себе произошедшие события
    virtual void setMessages(const QQueue<QString> &messages) = 0;
    virtual QString messages() const = 0;

    // будущий слот принятия информационных сообщений
    virtual void newInfo(QString) = 0;

    virtual ~ILoggerModel() {}
};

#endif // ILOGGERMODEL_H
