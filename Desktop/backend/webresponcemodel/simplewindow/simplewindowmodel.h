#ifndef SIMPLEWINDOWMODEL_H
#define SIMPLEWINDOWMODEL_H

#include "IWebResponceModel.h"
#include <QObject>
#include <QtQml>

///
/// \brief The SimpleWindowModel class
/// модель данных для простого окна просмотра
/// веб-ответа без какого-либо форматирования
class SimpleWindowModel : public QObject,
                          public IWebResponceModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString error READ error WRITE setError NOTIFY errorChanged)
    Q_PROPERTY(QByteArray data READ data WRITE setData NOTIFY dataChanged)

public:
    explicit SimpleWindowModel(QObject *parent = nullptr);
    SimpleWindowModel(const SimpleWindowModel &other);

    // IWebResponceModel interface {
    void setError(const QString &error) override;
    QString error() const override;
    void setData(const QByteArray &data) override;
    QByteArray data() const override;
    ~SimpleWindowModel() override;
    // }

private:
    QString m_error;
    QByteArray m_data;

signals:
    void errorChanged(QString);
    void dataChanged(QByteArray);
};

#endif // SIMPLEWINDOWMODEL_H
