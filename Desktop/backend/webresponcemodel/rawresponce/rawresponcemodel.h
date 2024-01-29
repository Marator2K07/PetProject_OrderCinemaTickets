#ifndef RAWRESPONCEMODEL_H
#define RAWRESPONCEMODEL_H

#include "IWebResponceModel.h"
#include <QQmlEngine>
#include <QObject>

///
/// \brief The RawResponceModel class
/// модель данных для простого окна просмотра
/// веб-ответа без какого-либо форматирования
class RawResponceModel : public QObject,
                         public IWebResponceModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString error READ error WRITE setError NOTIFY errorChanged)
    Q_PROPERTY(QByteArray data READ data WRITE setData NOTIFY dataChanged)
    Q_PROPERTY(bool isLoading READ isLoading WRITE setIsLoading NOTIFY isLoadingChanged)

public:
    explicit RawResponceModel(QObject *parent = nullptr);
    RawResponceModel(const RawResponceModel &other);

    // IWebResponceModel interface {
    void setError(const QString &error) override;
    QString error() const override;
    void setData(const QByteArray &data) override;
    QByteArray data() const override;
    void setIsLoading(const bool &isLoading) override;
    bool isLoading() const override;
    ~RawResponceModel() override;
    Q_INVOKABLE void subscribe(RequestResponceHandling *responceHandler,
                               RequestEnums::Identifier identifier) override;
    // }

private:
    QString m_error;
    QByteArray m_data;
    bool m_isLoading;

signals:
    void errorChanged(QString);
    void dataChanged(QByteArray);
    void isLoadingChanged(bool);
};

#endif // RAWRESPONCEMODEL_H
