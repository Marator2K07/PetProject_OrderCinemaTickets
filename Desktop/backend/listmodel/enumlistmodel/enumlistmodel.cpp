#include "enumlistmodel.h"

EnumListModel::EnumListModel(QObject *parent)
    : QAbstractListModel{parent}
{
}

void EnumListModel::initializeAsRequestTypes()
{
    enumItems.clear();
    enumItems.append(EnumItem((int)RequestEnums::Type::GET, "GET"));
    enumItems.append(EnumItem((int)RequestEnums::Type::POST, "POST"));
}

void EnumListModel::initializeAsRequestBodyTypes()
{
    enumItems.clear();
    enumItems.append(EnumItem((int)RequestEnums::DataType::TEXT, "TEXT"));
    enumItems.append(EnumItem((int)RequestEnums::DataType::JSON, "JSON"));
}

int EnumListModel::rowCount(const QModelIndex &parent) const
{
    return enumItems.count();
}

QVariant EnumListModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case Qt::DisplayRole:
        return enumItems.value(index.row()).info();
    case Qt::EditRole:
        return enumItems.value(index.row()).value();
    // another case:
    }
    return QVariant{};
}

QHash<int, QByteArray> EnumListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ItemRole] = "item";
    roles[ValueRole] = "value";
    roles[InfoRole] = "info";
    return roles;
}
