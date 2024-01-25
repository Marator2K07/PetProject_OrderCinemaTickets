#ifndef REPLYWITHIDENTIFIER_H
#define REPLYWITHIDENTIFIER_H

#include "RequestEnums.h"

#include <QNetworkReply>
#include <QObject>

class ReplyWithIdentifier : public QObject
{
    Q_OBJECT
public:
    explicit ReplyWithIdentifier(QObject *parent = nullptr);

signals:

};

#endif // REPLYWITHIDENTIFIER_H
