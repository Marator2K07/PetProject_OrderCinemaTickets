#ifndef MENULISTMODEL_H
#define MENULISTMODEL_H

#include <QAbstractListModel>
#include "IMenuItemModel.h"

class MenuListModel : public QAbstractListModel
{
public:
    explicit MenuListModel(QObject *parent = nullptr);

private:
    QList<IMenuItemModel *> menuItems;
};

#endif // MENULISTMODEL_H
