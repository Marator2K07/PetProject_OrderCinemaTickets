#ifndef ACTIONCONTEXT_H
#define ACTIONCONTEXT_H

#include "IAction.h"

#include <QQmlEngine>
#include <QObject>
#include <QHash>

///
/// \brief The ActionContext class
/// помощник организации
/// взаимодействия между объектами
class ActionContext : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    enum ActionTypes {
        ClickType = 0,
        UpdateType
    };
    Q_ENUM(ActionTypes)

    explicit ActionContext(QObject *parent = nullptr);
    IAction* newAction(QString name);

private:
    QHash<QString, IAction *> actions;
};

#endif // ACTIONCONTEXT_H
