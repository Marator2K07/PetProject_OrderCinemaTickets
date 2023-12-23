#ifndef COMBOBOXMODEL_H
#define COMBOBOXMODEL_H

#include "RequestType.h"
#include "RequestBodyType.h"
#include "enumitem.h"

#include <QObject>
#include <QHash>
#include <QList>

///
/// \brief The ComboBoxModel class
/// класс управления моделью для комбобокса формы веб запроса
class ComboBoxModel : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QList<EnumItem> model READ model
                   WRITE setModel NOTIFY modelChanged)

public:
    explicit ComboBoxModel(QObject *parent = nullptr);

    QList<EnumItem> model() const;
    void setModel(const QList<EnumItem> &model);
    Q_INVOKABLE void initializeAsRequestTypes();
    Q_INVOKABLE void addEnumItem(int value, QString text);

private:
    QList<EnumItem> m_model;

signals:
    void modelChanged();
};

#endif // COMBOBOXMODEL_H
