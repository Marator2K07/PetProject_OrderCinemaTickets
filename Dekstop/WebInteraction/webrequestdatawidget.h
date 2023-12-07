#ifndef WEBREQUESTDATAWIDGET_H
#define WEBREQUESTDATAWIDGET_H

#include <QWidget>
#include <QJsonObject>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>

class WebRequestDataWidget : public QWidget
{
    Q_OBJECT

private:
    QJsonObject currentJsonData;
    QTextEdit *textEdit;

public:
    explicit WebRequestDataWidget(QWidget *parent = nullptr);

signals:

};

#endif // WEBREQUESTDATAWIDGET_H
