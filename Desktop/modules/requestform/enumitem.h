#ifndef ENUMITEM_H
#define ENUMITEM_H

#include <QObject>
#include <QQmlEngine>

///
/// \brief The EnumItem class
/// элемент для модели EnumItemsModel
class EnumItem : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit EnumItem(QObject *parent = nullptr);
    EnumItem(const EnumItem &other);
    EnumItem(int value,
             QString text,
             QObject *parent = nullptr);

    EnumItem& operator =(const EnumItem &other);
    bool operator == (const EnumItem item) const;
    bool operator != (const EnumItem item) const;

private:
    int value;
    QString text;
};

#endif // ENUMITEM_H
