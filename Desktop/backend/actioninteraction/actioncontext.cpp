#include "actioncontext.h"

ActionContext::ActionContext(QObject *parent)
    : QObject{parent}
{
}

IAction *ActionContext::newAction(QString name)
{

}
