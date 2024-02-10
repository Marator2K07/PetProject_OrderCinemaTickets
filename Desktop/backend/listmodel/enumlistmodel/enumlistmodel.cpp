#include "enumlistmodel.h"

EnumListModel::EnumListModel(QObject *parent)
    : QObject{parent}
{
}

QList<EnumItem> EnumListModel::model() const
{
    return m_model;
}

void EnumListModel::setModel(const QList<EnumItem> &model)
{
    if (model != m_model) {
        m_model = model;
        emit modelChanged();
    }
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

void EnumListModel::addEnumItem(int value, QString text)
{
    m_model.append(EnumItem(value, text));
}

EnumItem EnumListModel::getEnumItem(int pos) const
{
    if (pos >= 0 && pos-1 <= m_model.length()) {
        return m_model[pos];
    }
    // в случае неудачи пока что возвращаем особый элемент с ошибкой
    return EnumItem(2222, "Not found");
}

int EnumListModel::itemsCount() const
{
    return m_model.length();
}
