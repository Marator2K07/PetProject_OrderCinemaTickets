#ifndef ILOGGINGOBJECT_H
#define ILOGGINGOBJECT_H

#include <QString>

///
/// \brief The ILoggingObject interface
/// организация функциональности логируемого класса
class ILoggingObject
{
signals:
    // отправка данных в обьект логгера
    virtual void updateInfo(QString) = 0;
};

#endif // ILOGGINGOBJECT_H
