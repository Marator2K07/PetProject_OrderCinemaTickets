#ifndef IACTION_H
#define IACTION_H

#include <QString>

///
/// \brief The IAction interface
/// организация функциональности для абстрактного
/// элемента-посредника, поддерживающего какое-то действие
class IAction
{
public:
    // обработка пришедшего события и отправка
    // выбранного сигнала уже настоящему исполнителю
    virtual void handle(QString param = nullptr) = 0;
signals:
    virtual void exec() = 0;
    virtual void exec(QString) = 0;
};

#endif // IACTION_H
