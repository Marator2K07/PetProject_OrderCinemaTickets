#ifndef COMBOBOXMODEL_H
#define COMBOBOXMODEL_H

#include "RequestType.h"
#include "RequestBodyType.h"

#include <QObject>
#include <QHash>
#include <QtQml>

///
/// \brief The ComboBoxModel class
/// класс управления моделью для комбобокса формы веб запроса
class ComboBoxModel : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QHash<int, QString> model READ model
                   WRITE setModel NOTIFY modelChanged)

public:
    explicit ComboBoxModel(QObject *parent = nullptr);

    QHash<int, QString> model() const;
    void setModel(const QHash<int, QString> &model);

private:
    QHash<int, QString> m_model;

signals:
    void modelChanged();
};

#endif // COMBOBOXMODEL_H
