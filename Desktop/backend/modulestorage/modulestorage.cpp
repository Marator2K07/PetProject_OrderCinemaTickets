#include "modulestorage.h"

ModuleStorage::ModuleStorage(QObject *parent)
    : QObject{parent}
{
}

void ModuleStorage::add(QString moduleName, QString url)
{
    modules.insert(moduleName, url);
}

QString ModuleStorage::url(QString moduleName) const
{
    return modules.value(moduleName);
}

void ModuleStorage::remove(QString moduleName)
{
    modules.remove(moduleName);
}
