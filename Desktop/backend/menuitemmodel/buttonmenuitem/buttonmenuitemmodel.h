#ifndef BUTTONMENUITEMMODEL_H
#define BUTTONMENUITEMMODEL_H

#include <IMenuItemModel.h>
#include <QQmlEngine>
#include <QObject>

///
/// \brief The ButtonMenuItemModel class
/// модель данных для работы с пунктом меню
/// ведущим себя как обычная кнопка
class ButtonMenuItemModel : public QObject,
                            public IMenuItemModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString image READ image WRITE setImage NOTIFY imageChanged)
    Q_PROPERTY(bool simplified READ simplified WRITE setSimplified NOTIFY simplifiedChanged)

public:
    explicit ButtonMenuItemModel(QObject *parent = nullptr);
    ButtonMenuItemModel(const ButtonMenuItemModel &other);

    // IMenuItemModel interface {
    void setText(const QString &text) override;
    QString text() const override;
    void setImage(const QString &image) override;
    QString image() const override;
    void setSimplified(const bool &simplified) override;
    bool simplified() const override;
    ~ButtonMenuItemModel() override;
    // }

private:
    QString m_text;
    QString m_image;
    bool m_simplifier;

signals:
    void textChanged(QString);
    void imageChanged(QString);
    void simplifiedChanged(bool);
};

#endif // BUTTONMENUITEMMODEL_H
