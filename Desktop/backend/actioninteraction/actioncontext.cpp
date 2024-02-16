#include "actioncontext.h"

ActionContext::ActionContext(QObject *parent)
    : QObject{parent}
{
}

IAction *ActionContext::newAction(QString name, ActionTypes actionType)
{
    switch (actionType) {
    case ClickType:
        ClickAction *newAction = new ClickAction(this);
        actions.insert(name, newAction);
        return newAction;
        break;
    // another case
    }
    return nullptr;
}
