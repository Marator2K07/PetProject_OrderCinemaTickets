#include "simplewindowmodel.h"

SimpleWindowModel::SimpleWindowModel(QObject *parent)
    : QObject{parent}
{
}

SimpleWindowModel::SimpleWindowModel(const SimpleWindowModel &other)
    : m_error{other.error()}
    , m_data{other.data()}
{
}

void SimpleWindowModel::setError(const QString &error)
{
    if (error != m_error) {
        m_error = error;
        emit errorChanged(error);
    }
}

QString SimpleWindowModel::error() const
{
    return m_error;
}

void SimpleWindowModel::setData(const QByteArray &data)
{
    if (data != m_data) {
        m_data = data;
        emit dataChanged(data);
    }
}

QByteArray SimpleWindowModel::data() const
{
    return m_data;
}

SimpleWindowModel::~SimpleWindowModel()
{
}
