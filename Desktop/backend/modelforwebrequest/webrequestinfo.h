#ifndef WEBREQUESTINFO_H
#define WEBREQUESTINFO_H

#include "RequestType.h"
#include "RequestBodyType.h"

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
    Q_PROPERTY(RequestType::State requestType READ requestType
                   WRITE setRequestType NOTIFY requestTypeChanged)
    Q_PROPERTY(RequestBodyType::State requestBodyType READ requestBodyType
                   WRITE setRequestBodyType NOTIFY requestBodyTypeChanged)
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(QVariant data READ data WRITE setData NOTIFY dataChanged)

public:
    explicit WebRequestInfo(QObject *parent = nullptr);
    WebRequestInfo(const WebRequestInfo &other);

    void setRequestType(const RequestType::State &type);
    RequestType::State requestType() const;
    void setRequestBodyType(const RequestBodyType::State &type);
    RequestBodyType::State requestBodyType() const;
    void setUrl(const QString &url);
    QString url() const;
    void setData(const QVariant &data);
    QVariant data() const;

    QString getContentType() const;
    void setContentType(const QString &newContentType);

    QJsonObject getJsonData() const;
    QString getTextData() const;

private:
    RequestType::State m_requestType; // тип запроса (ГЕТ или ПОСТ)
    RequestBodyType::State m_requestBodyType; // тип данных запроса (ТЕКСТ или ДЖЕЙСОН)
    QString m_url; // сам текст строки запроса
    QVariant m_data; // содержимое тела запроса

    QString contentType; // информация для заголовка запроса    

signals:
    void requestTypeChanged();
    void requestBodyTypeChanged();
    void urlChanged();
    void dataChanged();
};
Q_DECLARE_METATYPE(WebRequestInfo)

#endif // WEBREQUESTINFO_H