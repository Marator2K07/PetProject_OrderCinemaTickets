#include "loggersectionmodel.h"

LoggerSectionModel::LoggerSectionModel(QObject *parent)
    : QObject{parent}
{    
}

LoggerSectionModel::LoggerSectionModel(const LoggerSectionModel &other)
    : m_messages{other.messages()}
{
}

void LoggerSectionModel::setMessages(const QString &messages)
{
    if (messages != m_messages) {
        m_messages = messages;
        emit messagesChanged(messages);
    }
}

QString LoggerSectionModel::messages() const
{
    return m_messages;
}

void LoggerSectionModel::acceptMessage(QString message)
{
    m_messages.append(message);
    emit messagesChanged(m_messages);
}
