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

signals:

};

#endif // WEBREQUESTDATAWIDGET_H
