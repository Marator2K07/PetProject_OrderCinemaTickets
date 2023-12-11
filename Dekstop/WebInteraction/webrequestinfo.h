#ifndef WEBREQUESTINFO_H
#define WEBREQUESTINFO_H

#include <QObject>
#include <QVariant>
#include <QJsonObject>

///
/// \brief The WebRequestBody class
/// класс для работы с данными запроса
/// (сейчас это: Text и Json формат)
class WebRequestInfo : public QObject
{
    Q_OBJECT

public:
    explicit WebRequestInfo(QObject *parent = nullptr);
    WebRequestInfo(const WebRequestInfo &other);

    QString getUrl() const;
    void setUrl(const QString &newUrl);
    QString getContentType() const;
    void setContentType(const QString &newContentType);

    QVariant getData() const;
    QJsonObject getJsonData() const;
    QString getTextData() const;

public slots:
    void setData(const QVariant &newData);

private:
    QString contentType; // информация для заголовка запроса
    QString url;
    QVariant data;
};
Q_DECLARE_METATYPE(WebRequestInfo)

#endif // WEBREQUESTINFO_H
