#ifndef BUTTONMENUITEMMODEL_H
#define BUTTONMENUITEMMODEL_H

#include <QQmlEngine>
#include <QObject>

///
/// \brief The ButtonMenuItemModel class
/// модель данных для работы с пунктом меню
/// ведущим себя как обычная кнопка
class ButtonMenuItemModel : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit ButtonMenuItemModel(QObject *parent = nullptr);
};

#endif // BUTTONMENUITEMMODEL_H
