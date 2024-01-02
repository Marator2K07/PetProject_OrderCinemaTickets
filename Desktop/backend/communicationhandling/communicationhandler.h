#ifndef COMMUNICATIONHANDLER_H
#define COMMUNICATIONHANDLER_H

#include <QObject>

///
/// \brief The CommunicationHandler class
/// класс посредник для коммуникации отдельных обьектов
/// с помощью механизма сигналов и слотов
class CommunicationHandler : public QObject
{
    Q_OBJECT
public:
    explicit CommunicationHandler(QObject *parent = nullptr);

signals:

};

#endif // COMMUNICATIONHANDLER_H
