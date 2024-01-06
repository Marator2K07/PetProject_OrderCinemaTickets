#ifndef ILOGGINGOBJECT_H
#define ILOGGINGOBJECT_H

#include <QString>

///
/// \brief The ILoggingObject interface
/// для организации функциональности логируемого класса
class ILoggingObject
{
public:
    // отправка данных в обьект логгера
    virtual void log(QString) = 0;
};

#endif // ILOGGINGOBJECT_H
