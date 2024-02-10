#ifndef ENUMLISTMODEL_H
#define ENUMLISTMODEL_H

#include "RequestEnums.h"
#include "enumitem.h"

#include <QAbstractListModel>
#include <QHash>
#include <QList>

///
/// \brief The ComboBoxModel class
/// класс управления моделью в виде
/// списка значений перечислений
class EnumListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit EnumListModel(QObject *parent = nullptr);
    ///
    /// \brief initializeAsRequestTypes
    /// заполняем данную модель перечислениями из типа RequestType
    Q_INVOKABLE void initializeAsRequestTypes();
    ///
    /// \brief initializeAsRequestBodyTypes
    /// заполняем данную модель перечислениями из типа RequestBodyType
    Q_INVOKABLE void initializeAsRequestBodyTypes();

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    // }

private:
    QList<EnumItem> enumItems;
};

#endif // ENUMLISTMODEL_H
