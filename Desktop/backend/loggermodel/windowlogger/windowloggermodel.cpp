#include "windowloggermodel.h"

WindowLoggerModel::WindowLoggerModel(QObject *parent)
    : QObject{parent}
{    
}

WindowLoggerModel::WindowLoggerModel(const WindowLoggerModel &other)
    : m_messages{other.messages()}
{
}

void WindowLoggerModel::setMessages(const QString &messages)
{
    if (messages != m_messages) {
        m_messages = messages;
        emit messagesChanged(messages);
    }
}

QString WindowLoggerModel::messages() const
{
    return m_messages;
}

void WindowLoggerModel::acceptMessage(QString message)
{
    m_messages.append(message);
    emit messagesChanged(m_messages);
}
