#ifndef SIMPLEWINDOWMODEL_H
#define SIMPLEWINDOWMODEL_H

#include "IWebResponceModel.h"
#include <QObject>
#include <QtQml>

///
/// \brief The SimpleWindowInfo class
/// модель данных для простого окна просмотра
/// веб-ответа без какого-либо форматирования
class SimpleWindowModel : public QObject,
                          public IWebResponceModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit SimpleWindowModel(QObject *parent = nullptr);

signals:

};

#endif // SIMPLEWINDOWMODEL_H
