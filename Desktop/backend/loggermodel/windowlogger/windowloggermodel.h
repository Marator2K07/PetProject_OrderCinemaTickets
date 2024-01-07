#ifndef WINDOWLOGGERMODEL_H
#define WINDOWLOGGERMODEL_H

#include <QObject>
#include <QQmlEngine>

class WindowLoggerModel : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit WindowLoggerModel(QObject *parent = nullptr);

signals:

};

#endif // WINDOWLOGGERMODEL_H
