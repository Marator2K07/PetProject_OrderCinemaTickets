#ifndef MENULISTMODEL_H
#define MENULISTMODEL_H

#include <QAbstractListModel>

class MenuListModel : public QAbstractListModel
{
public:
    explicit MenuListModel(QObject *parent = nullptr);
};

#endif // MENULISTMODEL_H
