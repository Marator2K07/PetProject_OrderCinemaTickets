#include "windowloggermodel.h"

WindowLoggerModel::WindowLoggerModel(QObject *parent)
    : QObject{parent}
{    
}

WindowLoggerModel::WindowLoggerModel(const WindowLoggerModel &other)
    : m_path{other.path()}
    , m_messages{other.messages()}
{
}

void WindowLoggerModel::setPath(const QString &path)
{
    if (path != m_path) {
        m_path = path;
        emit pathChanged(path);
    }
}

QString WindowLoggerModel::path() const
{
    return m_path;
}

void WindowLoggerModel::setMessages(const QQueue<QString> &messages)
{
    if (messages != m_messages) {
        m_messages = messages;
        emit messagesChanged(messages);
    }
}

QQueue<QString> WindowLoggerModel::messages() const
{
    return m_messages;
}

void WindowLoggerModel::log(QString)
{
    
}
