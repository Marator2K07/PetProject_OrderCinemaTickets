#ifndef IMENUITEMMODEL_H
#define IMENUITEMMODEL_H

#include <QString>

///
/// \brief The IMenuItemModel interface
/// организация фукнциональности модели и
/// структуры данных пункта абстрактного меню
class IMenuItemModel
{
public:
    // каждый пункт меню может иметь короткое описание
    virtual void setText(const QString &text) = 0;
    virtual QString text() const = 0;
    // также каждый пункт имеет картинку
    virtual void setImage(const QString &image) = 0;
    virtual QString image() const = 0;
    // возможная упрощенная форма (только картинка без текста)
    virtual void setSimplified(const bool &simplified) = 0;
    virtual bool simplified() = 0;

    virtual ~IMenuItemModel() {}
};

#endif // IMENUITEMMODEL_H
