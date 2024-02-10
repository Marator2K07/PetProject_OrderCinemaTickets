#include "enumlistmodel.h"

EnumListModel::EnumListModel(QObject *parent)
    : QAbstractListModel{parent}
{
}

void EnumListModel::initializeAsRequestTypes()
{
    m_model.clear();
    m_model.append(EnumItem((int)RequestEnums::Type::GET, "GET"));
    m_model.append(EnumItem((int)RequestEnums::Type::POST, "POST"));
}

void EnumListModel::initializeAsRequestBodyTypes()
{
    m_model.clear();
    m_model.append(EnumItem((int)RequestEnums::DataType::TEXT, "TEXT"));
    m_model.append(EnumItem((int)RequestEnums::DataType::JSON, "JSON"));
}

int EnumListModel::rowCount(const QModelIndex &parent) const
{

}

QVariant EnumListModel::data(const QModelIndex &index, int role) const
{

}
