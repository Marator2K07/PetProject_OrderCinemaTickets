#ifndef WEBREQUESTFORMINFO_H
#define WEBREQUESTFORMINFO_H

#include "IWebRequestModel.h"
#include <QObject>
#include <QtQml>

///
/// \brief The WebRequestInfo class
/// класс для работы с данными запроса
/// теперь может обрабатываться/быть qml элементом
class WebRequestFormInfo : public QObject,
                           public IWebRequestModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(RequestEnums::Type type READ type
                   WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(RequestEnums::DataType bodyType READ bodyType
                   WRITE setBodyType NOTIFY bodyTypeChanged)
    Q_PROPERTY(RequestEnums::Identifier identifier READ identifier
                   WRITE setIdentifier NOTIFY identifierChanged)
    Q_PROPERTY(QString contentType READ contentType
                   WRITE setContentType NOTIFY contentTypeChanged)
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(QVariant data READ data WRITE setData NOTIFY dataChanged)    

public:
    explicit WebRequestFormInfo(QObject *parent = nullptr);
    WebRequestFormInfo(const WebRequestFormInfo &other);

    // IWebRequestInfo interface {
    void setType(const RequestEnums::Type &type) override;
    RequestEnums::Type type() const override;
    void setBodyType(const RequestEnums::DataType &type) override;
    RequestEnums::DataType bodyType() const override;
    void setIdentifier(const RequestEnums::Identifier &identifier) override;
    RequestEnums::Identifier identifier() const override;
    void setUrl(const QString &url) override;
    QString url() const override;
    void setData(const QVariant &data) override;
    QVariant data() const override;
    void setContentType(const QString &сontentType) override;
    QString contentType() const override;
    ~WebRequestFormInfo() override;
    // }

public slots:
    // IWebRequestInfo interface
    void send(const IWebRequestModel *) override;

private:
    RequestEnums::Type m_type; // тип запроса (ГЕТ или ПОСТ)
    RequestEnums::DataType m_bodyType; // тип данных запроса (ТЕКСТ или ДЖЕЙСОН)
    RequestEnums::Identifier m_identifier; // для распознавания источника запроса
    QString m_url; // сам текст строки запроса
    QVariant m_data; // содержимое тела запроса
    QString m_contentType; // информация для заголовка запроса о типе контента тела

private:
    // проверка тела запроса в виде TEXT файла
    bool correctDataAsText();
    // проверка тела запроса в виде JSON файла
    bool correctDataAsJson();
    // IWebRequestInfo interface {
    bool isValid() override;
    // }

signals:
    void typeChanged(RequestEnums::Type);
    void bodyTypeChanged(RequestEnums::DataType);
    void identifierChanged(RequestEnums::Identifier);
    void urlChanged(QString);
    void dataChanged(QVariant);
    void contentTypeChanged(QString);

    // простой сигнал для вывода относительно важных сообщений
    void updateStatus(QString);
    // в случае валидности запроса
    void requestIsReady(WebRequestFormInfo *);
};
Q_DECLARE_METATYPE(WebRequestFormInfo)

#endif // WEBREQUESTFORMINFO_H
