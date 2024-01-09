#ifndef WINDOWLOGGERMODEL_H
#define WINDOWLOGGERMODEL_H

#include <ILoggerModel.h>
#include <QObject>
#include <QQmlEngine>

class WindowLoggerModel : public QObject,
                          public ILoggerModel

{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString messages READ messages WRITE setMessages
                   NOTIFY messagesChanged)
public:
    explicit WindowLoggerModel(QObject *parent = nullptr);
    WindowLoggerModel(const WindowLoggerModel &other);

    // ILoggerModel interface {
    void setMessages(const QString &messages) override;
    QString messages() const override;
    void acceptMessage(QString msg) override;
    // }

private:
    QString m_messages;

signals:
    void messagesChanged(QString);
};

#endif // WINDOWLOGGERMODEL_H
