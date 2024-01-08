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
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QQueue<QString> messages READ messages WRITE setMessages
                   NOTIFY messagesChanged)

public:
    explicit WindowLoggerModel(QObject *parent = nullptr);
    WindowLoggerModel(const WindowLoggerModel &other);

    // ILoggerModel interface {
    void setPath(const QString &path) override;
    QString path() const override;
    void setMessages(const QQueue<QString> &messages) override;
    QQueue<QString> messages() const override;
    void log(QString) override;
    // }

private:
    QString m_path;
    QQueue<QString> m_messages;

signals:
    void pathChanged(QString);
    void messagesChanged(QQueue<QString>);
};

#endif // WINDOWLOGGERMODEL_H
