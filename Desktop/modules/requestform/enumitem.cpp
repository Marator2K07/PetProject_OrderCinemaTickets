#include "enumitem.h"

EnumItem::EnumItem(QObject *parent)
    : QObject{parent}
{
}

EnumItem::EnumItem(int value,
                   QString text,
                   QObject *parent)
    : value{value}
    , text{text}
    , QObject{parent}
{
}

EnumItem::EnumItem(const EnumItem &other)
    : value{other.value}
    , text{other.text}
{
}

EnumItem &EnumItem::operator =(const EnumItem &other)
{
    return *this;
}
