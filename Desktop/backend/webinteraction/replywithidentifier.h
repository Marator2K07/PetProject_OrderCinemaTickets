#ifndef REPLYWITHIDENTIFIER_H
#define REPLYWITHIDENTIFIER_H

#include "RequestEnums.h"

#include <QNetworkReply>
#include <QObject>

///
/// \brief The ReplyWithIdentifier class
/// для совместного хранения двух важных
/// связанных в контексте задачи обьектов
/// (QNetworkReply и RequestEnums::Identifier)
class ReplyWithIdentifier : public QObject
{
    Q_OBJECT
public:
    explicit ReplyWithIdentifier(QObject *parent = nullptr);

    QNetworkReply *getReply() const;
    void setReply(QNetworkReply *newReply);
    RequestEnums::Identifier getIdentifier() const;
    void setIdentifier(const RequestEnums::Identifier &newIdentifier);

private:
    QNetworkReply *reply;
    RequestEnums::Identifier identifier;
};

#endif // REPLYWITHIDENTIFIER_H
