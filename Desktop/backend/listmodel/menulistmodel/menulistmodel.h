#ifndef MENULISTMODEL_H
#define MENULISTMODEL_H

#include <QAbstractListModel>
#include "IMenuItemModel.h"

class MenuListModel : public QAbstractListModel
{
public:
    explicit MenuListModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index,
                 const QVariant &value,
                 int role) override;
    // }

private:
    QList<IMenuItemModel *> menuItems;
};

#endif // MENULISTMODEL_H
