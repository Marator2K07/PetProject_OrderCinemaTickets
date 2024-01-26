#include "replywithidentifier.h"

ReplyWithIdentifier::ReplyWithIdentifier(QObject *parent)
    : QObject{parent}
    , reply{nullptr}
    , identifier{RequestEnums::IDENTIFIERNONE}
{
}

ReplyWithIdentifier::ReplyWithIdentifier(const ReplyWithIdentifier &other,
                                         QObject *parent)
    : reply{other.reply}
    , identifier{other.identifier}
    , QObject{parent}
{
}

ReplyWithIdentifier &ReplyWithIdentifier::operator =(const ReplyWithIdentifier &other)
{
    reply = other.getReply();
    identifier = other.getIdentifier();
    return *this;
}

QNetworkReply *ReplyWithIdentifier::getReply() const
{
    return reply;
}

void ReplyWithIdentifier::setReply(QNetworkReply *newReply)
{
    reply = newReply;
}

RequestEnums::Identifier ReplyWithIdentifier::getIdentifier() const
{
    return identifier;
}

void ReplyWithIdentifier::setIdentifier(const RequestEnums::Identifier &newIdentifier)
{
    identifier = newIdentifier;
}
