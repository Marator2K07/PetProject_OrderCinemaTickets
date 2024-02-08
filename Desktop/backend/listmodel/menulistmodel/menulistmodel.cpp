#include "menulistmodel.h"

MenuListModel::MenuListModel(QObject *parent)
    : QAbstractListModel{parent}
{
}

int MenuListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.internalPointer() == nullptr) {
        return menuItems.count();
    } else {
        return 0;
    }
}

QVariant MenuListModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case Qt::DisplayRole:
        return menuItems.value(index.row())->text();
    // another case:
    }
    return "";
}

bool MenuListModel::setData(const QModelIndex &index,
                            const QVariant &value,
                            int role)
{
    switch (role) {
    case Qt::EditRole:
        IMenuItemModel *menuItem = qvariant_cast<IMenuItemModel *>(value);
        if (index.row() >= 0 && index.row() < menuItems.size()) {
            menuItems.insert(index.row(), menuItem);
        } else {
            menuItems.append(menuItem);
        }
        return true;
    // another case:
    }
    return false;
}
