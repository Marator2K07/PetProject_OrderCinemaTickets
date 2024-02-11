#include "enumitem.h"

EnumItem::EnumItem(int value, QString info)
    : m_value{value}
    , m_info{info}
{
}

EnumItem::EnumItem(const EnumItem &other)
    : m_value{other.m_value}
    , m_info{other.m_info}
{
}

void EnumItem::setValue(const int &value)
{
    if (value != m_value) {
        m_value = value;
    }
}

int EnumItem::value() const {
    return m_value;
}

void EnumItem::setInfo(const QString &info)
{
    if (info != m_info) {
        m_info = info;
    }
}

QString EnumItem::info() const
{
    return m_info;
}

EnumItem &EnumItem::operator =(const EnumItem &other)
{
    m_value = other.value();
    m_info = other.info();
    return *this;
}

bool EnumItem::operator ==(const EnumItem item) const
{
    return this->m_value == item.m_value &&
           this->m_info == item.m_info;
}

bool EnumItem::operator !=(const EnumItem item) const
{
    return this->m_value != item.m_value ||
           this->m_info != item.m_info;
}

