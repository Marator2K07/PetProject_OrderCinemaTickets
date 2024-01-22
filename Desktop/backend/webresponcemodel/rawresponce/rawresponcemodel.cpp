#include "rawresponcemodel.h"

RawResponceModel::RawResponceModel(QObject *parent)
    : QObject{parent}
{
}

RawResponceModel::RawResponceModel(const RawResponceModel &other)
    : m_error{other.error()}
    , m_data{other.data()}
{
}

void RawResponceModel::setError(const QString &error)
{
    if (error != m_error) {
        m_error = error;
        emit errorChanged(error);
    }
}

QString RawResponceModel::error() const
{
    return m_error;
}

void RawResponceModel::setData(const QByteArray &data)
{
    if (data != m_data) {
        m_data = data;
        emit dataChanged(data);
    }
}

QByteArray RawResponceModel::data() const
{
    return m_data;
}

RawResponceModel::~RawResponceModel()
{
}
