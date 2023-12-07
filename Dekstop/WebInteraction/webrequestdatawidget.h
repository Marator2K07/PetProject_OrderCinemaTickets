#ifndef WEBREQUESTDATAWIDGET_H
#define WEBREQUESTDATAWIDGET_H

#include <QWidget>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>

class WebRequestDataWidget : public QWidget
{
    Q_OBJECT

private:
    QJsonObject currentJsonData;
    QTextEdit *textEdit;
    QLabel *parseStatusLabel;

public:
    explicit WebRequestDataWidget(QWidget *parent = nullptr);

private slots:
    void tryParse();

signals:
    ///
    /// \brief jsonObjectReady
    /// в случае удачного парсинга
    void jsonObjectReady(QJsonObject jsonObject);

};

#endif // WEBREQUESTDATAWIDGET_H
