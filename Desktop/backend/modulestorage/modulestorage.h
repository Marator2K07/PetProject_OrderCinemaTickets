#ifndef MODULESTORAGE_H
#define MODULESTORAGE_H

#include <QObject>

class ModuleStorage : public QObject
{
    Q_OBJECT
public:
    explicit ModuleStorage(QObject *parent = nullptr);
};

#endif // MODULESTORAGE_H
