#ifndef ILOGGERMODEL_H
#define ILOGGERMODEL_H

#include <QQueue>

///
/// \brief The ILoggerModel interface
/// для организации функциональности логгера приложения
class ILoggerModel
{
public:
    // каждый логгер содержит путь для сохранения данных
    virtual void setPath(const QString &path) = 0;
    virtual QString path() const = 0;
    // каждый логгер содержит в себе произошедшие события
    virtual void setMessages(const QQueue<QString> &messages) = 0;
    virtual QString messages() const = 0;

    // запись данных в обьект модели логгера
    virtual void writeInModel(QString) = 0;
    // обычная запись в файл
    virtual void writeInFile(QString) = 0;

    virtual ~ILoggerModel() {}
};

#endif // ILOGGERMODEL_H
