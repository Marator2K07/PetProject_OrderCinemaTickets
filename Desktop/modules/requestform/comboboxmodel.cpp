#include "comboboxmodel.h"

ComboBoxModel::ComboBoxModel(QObject *parent)
    : QObject{parent}
{
}

QHash<int, QString> ComboBoxModel::model() const
{
    return m_model;
}

void ComboBoxModel::setModel(const QHash<int, QString> &model)
{
    if (model != m_model) {
        m_model = model;
        emit modelChanged();
    }
}

