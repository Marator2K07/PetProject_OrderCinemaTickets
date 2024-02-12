#include "enumlistmodel.h"

EnumListModel::EnumListModel(QObject *parent)
    : QAbstractListModel{parent}
{
}

void EnumListModel::initializeAsRequestTypes()
{
    enumItems.clear();
    // важное замечание: при работе с данными модели, ее надо
    // предупреждать об этом командами beginInsertRows и endInsertRows
    beginInsertRows(QModelIndex(), 0, 1);
    enumItems.append(EnumItem((int)RequestEnums::Type::GET, "GET"));
    enumItems.append(EnumItem((int)RequestEnums::Type::POST, "POST"));
    endInsertRows();

    emit dataChanged(createIndex(0,0), createIndex(enumItems.count(), 0));
}

void EnumListModel::initializeAsRequestBodyTypes()
{
    enumItems.clear();
    // важное замечание: при работе с данными модели, ее надо
    // предупреждать об этом командами beginInsertRows и endInsertRows
    beginInsertRows(QModelIndex(), 0, 1);
    enumItems.append(EnumItem((int)RequestEnums::DataType::TEXT, "TEXT"));
    enumItems.append(EnumItem((int)RequestEnums::DataType::JSON, "JSON"));
    endInsertRows();

    emit dataChanged(createIndex(0,0), createIndex(enumItems.count(), 0));
}

int EnumListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return enumItems.count();
}

QVariant EnumListModel::data(const QModelIndex &index, int role) const
{
    // всевозможные проверки корректности пришедших данных
    if (!hasIndex(index.row(),
                  index.column(),
                  index.parent()) || !value.isValid()) {
        return QVariant{};
    }

    switch (role) {
    case ItemRole:
        return QVariant::fromValue(enumItems.value(index.row()));
    case ValueRole:
        return enumItems.value(index.row()).value();
    case InfoRole:
        return enumItems.value(index.row()).info();
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
