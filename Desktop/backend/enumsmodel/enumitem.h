#ifndef ENUMITEM_H
#define ENUMITEM_H

#include <QQmlEngine>

///
/// \brief The EnumItem class
/// элемент для модели EnumItemsModel
class EnumItem
{
    Q_GADGET
    QML_ELEMENT

public:
    EnumItem(const EnumItem &other);
    EnumItem(int value, QString text);

    EnumItem& operator =(const EnumItem &other);
    bool operator == (const EnumItem item) const;
    bool operator != (const EnumItem item) const;

    Q_INVOKABLE int value() const;
    Q_INVOKABLE QString text() const;

private:
    int m_value;
    QString m_text;
};

#endif // ENUMITEM_H
