#ifndef WEBREQUESTINFO_H
#define WEBREQUESTINFO_H

#include "types.h"

#include <QVariant>
#include <QJsonObject>
#include <QtQml>

///
/// \brief The WebRequestInfo class
/// класс для работы с данными запроса
/// теперь может обрабатываться/быть qml элементом
class WebRequestInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(Types::Request requestType READ requestType
                   WRITE setRequestType NOTIFY requestTypeChanged)
    Q_PROPERTY(Types::RequestBody requestBodyType READ requestBodyType
                   WRITE setRequestBodyType NOTIFY requestBodyTypeChanged)
public:
    explicit WebRequestInfo(QObject *parent = nullptr);
    WebRequestInfo(const WebRequestInfo &other);

    void setRequestType(const Types::Request &type);
    Types::Request requestType() const;
    void setRequestBodyType(const Types::RequestBody &type);
    Types::RequestBody requestBodyType() const;

    QString getUrl() const;
    void setUrl(const QString &newUrl);
    QString getContentType() const;
    void setContentType(const QString &newContentType);

    void setData(const QVariant &newData);
    QVariant getData() const;
    QJsonObject getJsonData() const;
    QString getTextData() const;

private:
    Types::Request m_requestType; // тип запроса (ГЕТ или ПОСТ)
    Types::RequestBody m_requestBodyType; // тип данных запроса (ТЕКСТ или ДЖЕЙСОН)

    QString contentType; // информация для заголовка запроса
    QString url;
    QVariant data;

signals:
    void requestTypeChanged();
    void requestBodyTypeChanged();
};
Q_DECLARE_METATYPE(WebRequestInfo)

#endif // WEBREQUESTINFO_H
