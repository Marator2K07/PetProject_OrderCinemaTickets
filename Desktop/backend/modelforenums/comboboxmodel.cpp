#include "comboboxmodel.h"

ComboBoxModel::ComboBoxModel(QObject *parent)
    : QObject{parent}
{
}

QList<EnumItem> ComboBoxModel::model() const
{
    return m_model;
}

void ComboBoxModel::setModel(const QList<EnumItem> &model)
{
    if (model != m_model) {
        m_model = model;
        emit modelChanged();
    }
}

void ComboBoxModel::initializeAsRequestTypes()
{
    m_model.clear();
    m_model.append(EnumItem((int)RequestType::State::GET, "GET"));
    m_model.append(EnumItem((int)RequestType::State::POST, "POST"));
}

void ComboBoxModel::addEnumItem(int value, QString text)
{
    m_model.append(EnumItem(value, text));
}
