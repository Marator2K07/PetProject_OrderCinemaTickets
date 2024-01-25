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

void RawResponceModel::setIsLoading(const bool &isLoading)
{
    if (isLoading != m_isLoading) {
        m_isLoading = isLoading;
        emit isLoadingChanged(isLoading);
    }
}

bool RawResponceModel::isLoading() const
{
    return m_isLoading;
}

RawResponceModel::~RawResponceModel()
{
}

void RawResponceModel::subscribe(RequestResponceHandling *responceHandler,
                                 RequestEnums::Identifier identifier)
{
    responceHandler->takeSubscriber(this, identifier);
}
