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
    enum EnumRoles {
        ItemRole = Qt::UserRole + 1,
        ValueRole,
        InfoRole
    };
    Q_ENUM(EnumRoles)

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
    QHash<int, QByteArray> roleNames() const override;
    // }

private:
    QList<EnumItem> enumItems;
};

#endif // ENUMLISTMODEL_H
