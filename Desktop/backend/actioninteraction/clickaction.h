#ifndef CLICKACTION_H
#define CLICKACTION_H

#include <IAction.h>
#include <QObject>

///
/// \brief The ClickAction class
/// наследник IAction для действия нажатия
class ClickAction : public QObject,
                    public IAction
{
    Q_OBJECT
public:
    explicit ClickAction(QObject *parent = nullptr);
    // IAction interface
    void handle(QString param = nullptr) override;

signals:
    // IAction interface {
    void exec() override;
    void exec(QString) override;
    // }
};

#endif // CLICKACTION_H
