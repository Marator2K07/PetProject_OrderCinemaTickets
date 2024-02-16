#ifndef ACTIONCONTEXT_H
#define ACTIONCONTEXT_H

#include "clickaction.h"
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
    // создание нового действия определенного типа,
    // с возможностью его привязки извне
    IAction* newAction(QString name, ActionTypes actionType);

private:
    QHash<QString, IAction *> actions;
};

#endif // ACTIONCONTEXT_H
