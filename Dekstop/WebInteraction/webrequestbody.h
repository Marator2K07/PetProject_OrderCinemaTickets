#ifndef WEBREQUESTBODY_H
#define WEBREQUESTBODY_H

#include <QObject>
#include <QVariant>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>

///
/// \brief The WebRequestBody class
/// класс для работы с данными запроса
/// (в нашем случае пока Json формат)
class WebRequestBody : public QObject
{
    Q_OBJECT

private:
    QVariant data;

public:
    explicit WebRequestBody(QObject *parent = nullptr);

    QJsonObject getJsonData() const;

private slots:
    void setJsonData(const QJsonObject &newJsonData);

};

#endif // WEBREQUESTBODY_H
