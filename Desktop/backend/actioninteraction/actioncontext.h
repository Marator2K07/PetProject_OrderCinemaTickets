#ifndef ACTIONCONTEXT_H
#define ACTIONCONTEXT_H

#include <QObject>

///
/// \brief The ActionContext class
/// помощник организации
/// взаимодействия между объектами
class ActionContext : public QObject
{
    Q_OBJECT
public:
    explicit ActionContext(QObject *parent = nullptr);

signals:

};

#endif // ACTIONCONTEXT_H
