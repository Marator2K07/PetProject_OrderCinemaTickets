#ifndef ENUMLISTMODEL_H
#define ENUMLISTMODEL_H

#include "RequestEnums.h"
#include "enumitem.h"

#include <QObject>
#include <QHash>
#include <QList>

///
/// \brief The ComboBoxModel class
/// класс управления моделью в виде
/// списка значений перечислений
class EnumListModel : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QList<EnumItem> model READ model
                   WRITE setModel NOTIFY modelChanged)

public:
    explicit EnumListModel(QObject *parent = nullptr);

    QList<EnumItem> model() const;
    void setModel(const QList<EnumItem> &model);
    ///
    /// \brief initializeAsRequestTypes
    /// заполняем данную модель перечислениями из типа RequestType
    Q_INVOKABLE void initializeAsRequestTypes();
    ///
    /// \brief initializeAsRequestBodyTypes
    /// заполняем данную модель перечислениями из типа RequestBodyType
    Q_INVOKABLE void initializeAsRequestBodyTypes();
    Q_INVOKABLE void addEnumItem(int value, QString text);
    Q_INVOKABLE EnumItem getEnumItem(int pos) const;
    Q_INVOKABLE int itemsCount() const;

private:
    QList<EnumItem> m_model;

signals:
    void modelChanged();
};

#endif // ENUMLISTMODEL_H
