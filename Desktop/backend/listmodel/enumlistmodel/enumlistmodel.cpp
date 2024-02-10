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
    if (parent.internalPointer() == nullptr) {
        return enumItems.count();
    } else {
        return 0;
    }
}

QVariant EnumListModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case Qt::DisplayRole:
        return QVariant::fromValue(enumItems.value(index.row()));
    // another case:
    }
    return QVariant{};
}
