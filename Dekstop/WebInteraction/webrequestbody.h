#ifndef WEBREQUESTBODY_H
#define WEBREQUESTBODY_H

#include <QObject>

///
/// \brief The WebRequestBody class
/// класс для работы с данными запроса
/// (в нашем случае пока Json формат)
class WebRequestBody : public QObject
{
    Q_OBJECT
public:
    explicit WebRequestBody(QObject *parent = nullptr);

signals:

};

#endif // WEBREQUESTBODY_H
