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

    Q_INVOKABLE void add(QString moduleName, QString moduleUrl);
    Q_INVOKABLE QString url(QString moduleName) const;
    Q_INVOKABLE void remove(QString moduleName);

private:
    QHash<QString, QString> modules;
};

#endif // MODULESTORAGE_H
