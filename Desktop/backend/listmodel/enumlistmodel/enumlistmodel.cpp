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

bool EnumListModel::setData(const QModelIndex &index,
                            const QVariant &value,
                            int role)
{
    // всевозможные проверки корректности пришедших данных
    if (!hasIndex(index.row(),
                  index.column(),
                  index.parent()) || !value.isValid()) {
        return false;
    }

    EnumItem &item = enumItems[index.row()];
    switch (role) {
    case ItemRole:
        item = qvariant_cast<EnumItem>(value);
    case ValueRole:
        item.setValue(value.toInt());
    case InfoRole:
        item.setInfo(value.toString());
    default:
        return false;
    }
    emit dataChanged(index, index, {role});
    return true;
}

QVariant EnumListModel::data(const QModelIndex &index, int role) const
{
    // всевозможные проверки корректности пришедших данных
    if (!hasIndex(index.row(),
                  index.column(),
                  index.parent())) {
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
