#ifndef WEBREQUESTFORMINFO_H
#define WEBREQUESTFORMINFO_H

#include "IWebRequestInfo.h"
#include <QObject>

///
/// \brief The WebRequestInfo class
/// класс для работы с данными запроса
/// теперь может обрабатываться/быть qml элементом
class WebRequestFormInfo : public QObject,
                           public IWebRequestInfo
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
    explicit WebRequestFormInfo(QObject *parent = nullptr);
    WebRequestFormInfo(const WebRequestFormInfo &other);

    // IWebRequestInfo interface {
    void setRequestType(const RequestType::State &type) override;
    RequestType::State requestType() const override;
    void setRequestBodyType(const RequestBodyType::State &type) override;
    RequestBodyType::State requestBodyType() const override;
    void setUrl(const QString &url) override;
    QString url() const override;
    void setData(const QVariant &data) override;
    QVariant data() const override;
    // }

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

#endif // WEBREQUESTFORMINFO_H
