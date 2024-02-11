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
    Q_PROPERTY(int value READ value WRITE setValue)
    Q_PROPERTY(QString info READ info WRITE setInfo)
public:
    EnumItem() = default;
    EnumItem(const EnumItem &other);
    EnumItem(int value, QString info);

    EnumItem& operator =(const EnumItem &other);
    bool operator == (const EnumItem item) const;
    bool operator != (const EnumItem item) const;

    void setValue(const int &value);
    int value() const;
    void setInfo(const QString &info);
    QString info() const;

private:
    int m_value;
    QString m_info;
};

#endif // ENUMITEM_H
