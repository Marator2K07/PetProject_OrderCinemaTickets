#ifndef ILOGGERMODEL_H
#define ILOGGERMODEL_H

#include <QString>

///
/// \brief The ILoggerModel interface
/// для организации функциональности
/// модели логгера приложения
class ILoggerModel
{
public:
    // каждая модель логгера содержит в себе произошедшие события
    virtual void setMessages(const QString &messages) = 0;
    virtual QString messages() const = 0;

    // будущий слот принятия информационных сообщений
    virtual void acceptMessage(QString) = 0;

    virtual ~ILoggerModel() {}
};

#endif // ILOGGERMODEL_H
