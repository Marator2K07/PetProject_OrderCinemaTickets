#include "buttonmenuitemmodel.h"

ButtonMenuItemModel::ButtonMenuItemModel(QObject *parent)
    : QObject{parent}
{
}

ButtonMenuItemModel::ButtonMenuItemModel(const ButtonMenuItemModel &other)
    : m_text{other.text()}
    , m_image{other.image()}
    , m_simplifier{other.simplified()}
{
}

void ButtonMenuItemModel::setText(const QString &text)
{
    if (text != m_text) {
        m_text = text;
        emit textChanged(text);
    }
}

QString ButtonMenuItemModel::text() const
{
    return m_text;
}

void ButtonMenuItemModel::setImage(const QString &image)
{
    if (image != m_image) {
        m_image = image;
        emit imageChanged(image);
    }
}

QString ButtonMenuItemModel::image() const
{
    return m_image;
}

void ButtonMenuItemModel::setSimplified(const bool &simplified)
{
    if (simplified != m_simplifier) {
        m_simplifier = simplified;
        emit simplifiedChanged(simplified);
    }
}

bool ButtonMenuItemModel::simplified() const
{
    return m_simplifier;
}

ButtonMenuItemModel::~ButtonMenuItemModel()
{
}
