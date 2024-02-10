#include "enumitemsmodel.h"

EnumItemsModel::EnumItemsModel(QObject *parent)
    : QObject{parent}
{
}

QList<EnumItem> EnumItemsModel::model() const
{
    return m_model;
}

void EnumItemsModel::setModel(const QList<EnumItem> &model)
{
    if (model != m_model) {
        m_model = model;
        emit modelChanged();
    }
}

void EnumItemsModel::initializeAsRequestTypes()
{
    m_model.clear();
    m_model.append(EnumItem((int)RequestEnums::Type::GET, "GET"));
    m_model.append(EnumItem((int)RequestEnums::Type::POST, "POST"));
}

void EnumItemsModel::initializeAsRequestBodyTypes()
{
    m_model.clear();
    m_model.append(EnumItem((int)RequestEnums::DataType::TEXT, "TEXT"));
    m_model.append(EnumItem((int)RequestEnums::DataType::JSON, "JSON"));
}

void EnumItemsModel::addEnumItem(int value, QString text)
{
    m_model.append(EnumItem(value, text));
}

EnumItem EnumItemsModel::getEnumItem(int pos) const
{
    if (pos >= 0 && pos-1 <= m_model.length()) {
        return m_model[pos];
    }
    // в случае неудачи пока что возвращаем особый элемент с ошибкой
    return EnumItem(2222, "Not found");
}

int EnumItemsModel::itemsCount() const
{
    return m_model.length();
}
