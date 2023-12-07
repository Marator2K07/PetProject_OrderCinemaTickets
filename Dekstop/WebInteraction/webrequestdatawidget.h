#ifndef WEBREQUESTDATAWIDGET_H
#define WEBREQUESTDATAWIDGET_H

#include <QWidget>
#include <QJsonObject>

class WebRequestDataWidget : public QWidget
{
    Q_OBJECT

private:
    QJsonObject currentJsonData;

public:
    explicit WebRequestDataWidget(QWidget *parent = nullptr);

signals:

};

#endif // WEBREQUESTDATAWIDGET_H
