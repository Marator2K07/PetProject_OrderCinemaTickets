#ifndef FULLVIEWLOGGERMODEL_H
#define FULLVIEWLOGGERMODEL_H

#include <ILoggerModel.h>
#include <QObject>
#include <QQmlEngine>

///
/// \brief The FullViewLoggerModel class
/// частный случай модели логгера для представления
/// в виде отдельного окна с многострочным текстом
class FullViewLoggerModel : public QObject,
                            public ILoggerModel

{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString messages READ messages WRITE setMessages
                   NOTIFY messagesChanged)
public:
    explicit FullViewLoggerModel(QObject *parent = nullptr);
    FullViewLoggerModel(const FullViewLoggerModel &other);

    // ILoggerModel interface {
    void setMessages(const QString &messages) override;
    QString messages() const override;
    // }

public slots:
    // ILoggerModel interface
    void acceptMessage(QString message) override;

private:
    QString m_messages;

signals:
    void messagesChanged(QString);
};

#endif // FULLVIEWLOGGERMODEL_H
