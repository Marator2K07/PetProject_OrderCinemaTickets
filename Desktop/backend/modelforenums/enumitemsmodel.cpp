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
    m_model.append(EnumItem((int)RequestType::State::GET, "GET"));
    m_model.append(EnumItem((int)RequestType::State::POST, "POST"));
}

void EnumItemsModel::addEnumItem(int value, QString text)
{
    m_model.append(EnumItem(value, text));
}
