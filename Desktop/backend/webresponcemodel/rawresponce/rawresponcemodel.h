#ifndef RAWRESPONCEMODEL_H
#define RAWRESPONCEMODEL_H

#include "IWebResponceModel.h"
#include <QObject>
#include <QtQml>

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

public:
    explicit RawResponceModel(QObject *parent = nullptr);
    RawResponceModel(const RawResponceModel &other);

    // IWebResponceModel interface {
    void setError(const QString &error) override;
    QString error() const override;
    void setData(const QByteArray &data) override;
    QByteArray data() const override;
    ~RawResponceModel() override;
    // }

private:
    QString m_error;
    QByteArray m_data;

signals:
    void errorChanged(QString);
    void dataChanged(QByteArray);
};

#endif // RAWRESPONCEMODEL_H
