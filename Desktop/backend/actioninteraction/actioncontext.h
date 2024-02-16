#ifndef ACTIONCONTEXT_H
#define ACTIONCONTEXT_H

#include "IAction.h"
#include <QObject>
#include <QHash>

///
/// \brief The ActionContext class
/// помощник организации
/// взаимодействия между объектами
class ActionContext : public QObject
{
    Q_OBJECT
public:
    explicit ActionContext(QObject *parent = nullptr);

private:
    QHash<QString, IAction *> actions;
};

#endif // ACTIONCONTEXT_H
