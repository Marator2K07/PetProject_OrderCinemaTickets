#include "menulistmodel.h"

MenuListModel::MenuListModel(QObject *parent)
    : QAbstractListModel{parent}
{
}

int MenuListModel::rowCount(const QModelIndex &parent) const
{

}

QVariant MenuListModel::data(const QModelIndex &index, int role) const
{

}

bool MenuListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}

Qt::ItemFlags MenuListModel::flags(const QModelIndex &index) const
{

}
