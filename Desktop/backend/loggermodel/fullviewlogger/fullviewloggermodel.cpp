#include "fullviewloggermodel.h"

FullViewLoggerModel::FullViewLoggerModel(QObject *parent)
    : QObject{parent}
{    
}

FullViewLoggerModel::FullViewLoggerModel(const FullViewLoggerModel &other)
    : m_messages{other.messages()}
{
}

void FullViewLoggerModel::setMessages(const QString &messages)
{
    if (messages != m_messages) {
        m_messages = messages;
        emit messagesChanged(messages);
    }
}

QString FullViewLoggerModel::messages() const
{
    return m_messages;
}

void FullViewLoggerModel::acceptMessage(QString message)
{
    m_messages.append(message);
    emit messagesChanged(m_messages);
}
