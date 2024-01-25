#include "replywithidentifier.h"

ReplyWithIdentifier::ReplyWithIdentifier(QObject *parent)
    : QObject{parent}
    , reply{nullptr}
    , identifier{RequestEnums::IDENTIFIERNONE}
{
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
