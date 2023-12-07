#ifndef WEBREQUESTBODY_H
#define WEBREQUESTBODY_H

#include <QObject>
#include <QVariant>
#include <QJsonObject>

///
/// \brief The WebRequestBody class
/// класс для работы с данными запроса
/// (в нашем случае пока Json формат)
class WebRequestBody : public QObject
{
    Q_OBJECT

public:
    explicit WebRequestBody(QObject *parent = nullptr);

    QJsonObject getJsonData() const;

private:
    QVariant data;

private slots:
    void setJsonData(const QJsonObject &newJsonData);

};

#endif // WEBREQUESTBODY_H
