#include "enumitem.h"

EnumItem::EnumItem(int value, QString text)
    : m_value{value}
    , m_text{text}
{
}

EnumItem::EnumItem(const EnumItem &other)
    : m_value{other.m_value}
    , m_text{other.m_text}
{
}

int EnumItem::value() const {
    return m_value;
}

QString EnumItem::text() const {
    return m_text;
}

EnumItem &EnumItem::operator =(const EnumItem &other)
{
    return *this;
}

bool EnumItem::operator ==(const EnumItem item) const
{
    return this->m_value == item.m_value &&
           this->m_text == item.m_text;
}

bool EnumItem::operator !=(const EnumItem item) const
{
    return this->m_value != item.m_value ||
           this->m_text != item.m_text;
}
