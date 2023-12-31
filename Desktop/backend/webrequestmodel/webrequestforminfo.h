#ifndef WEBREQUESTFORMINFO_H
#define WEBREQUESTFORMINFO_H

#include "IWebRequestInfo.h"
#include <QObject>
#include <QtQml>

///
/// \brief The WebRequestInfo class
/// класс для работы с данными запроса
/// теперь может обрабатываться/быть qml элементом
class WebRequestFormInfo : public QObject,
                           public IWebRequestInfo
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(RequestType::State type READ type
                   WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(RequestBodyType::State bodyType READ bodyType
                   WRITE setBodyType NOTIFY bodyTypeChanged)
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(QVariant data READ data WRITE setData NOTIFY dataChanged)

public:
    explicit WebRequestFormInfo(QObject *parent = nullptr);
    WebRequestFormInfo(const WebRequestFormInfo &other);

    // IWebRequestInfo interface {
    void setType(const RequestType::State &type) override;
    RequestType::State type() const override;
    void setBodyType(const RequestBodyType::State &type) override;
    RequestBodyType::State bodyType() const override;
    void setUrl(const QString &url) override;
    QString url() const override;
    void setData(const QVariant &data) override;
    QVariant data() const override;
    ~WebRequestFormInfo() override;
    // }

    QString getContentType() const;
    void setContentType(const QString &newContentType);

    QJsonObject getJsonData() const;
    QString getTextData() const;

public slots:
    // IWebRequestInfo interface
    void send(const IWebRequestInfo *) override;

private:
    RequestType::State m_type; // тип запроса (ГЕТ или ПОСТ)
    RequestBodyType::State m_bodyType; // тип данных запроса (ТЕКСТ или ДЖЕЙСОН)
    QString m_url; // сам текст строки запроса
    QVariant m_data; // содержимое тела запроса

    QString contentType; // информация для заголовка запроса

private:
    // проверка тела запроса в виде TEXT файла
    bool correctDataAsText();
    // проверка тела запроса в виде JSON файла
    bool correctDataAsJson();
    // IWebRequestInfo interface {
    bool isValid() override;
    // }

signals:
    void typeChanged();
    void bodyTypeChanged();
    void urlChanged();
    void dataChanged();

    // простой сигнал для вывода относительно важных сообщений
    void updateStatus(QString);
    // в случае валидности запроса
    void requestIsReady(WebRequestFormInfo *);
};
Q_DECLARE_METATYPE(WebRequestFormInfo)

#endif // WEBREQUESTFORMINFO_H
