#ifndef ENUMITEMSMODEL_H
#define ENUMITEMSMODEL_H

#include "RequestType.h"
#include "RequestBodyType.h"
#include "enumitem.h"

#include <QObject>
#include <QHash>
#include <QList>

///
/// \brief The ComboBoxModel class
/// класс управления моделью в виде
/// списка значений перечислений
class EnumItemsModel : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QList<EnumItem> model READ model
                   WRITE setModel NOTIFY modelChanged)

public:
    explicit EnumItemsModel(QObject *parent = nullptr);

    QList<EnumItem> model() const;
    void setModel(const QList<EnumItem> &model);
    Q_INVOKABLE void initializeAsRequestTypes();
    Q_INVOKABLE void addEnumItem(int value, QString text);
    Q_INVOKABLE EnumItem getEnumItem(int pos) const;
    Q_INVOKABLE int itemsCount() const;

private:
    QList<EnumItem> m_model;

signals:
    void modelChanged();
};

#endif // ENUMITEMSMODEL_H
