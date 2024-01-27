#ifndef MODULESTORAGE_H
#define MODULESTORAGE_H

#include <QObject>
#include <QHash>

///
/// \brief The ModuleStorage class
/// класс-помощник для qml элемента Loader
class ModuleStorage : public QObject
{
    Q_OBJECT
public:
    explicit ModuleStorage(QObject *parent = nullptr);

private:
    QHash<QString, QString> modules;
};

#endif // MODULESTORAGE_H
