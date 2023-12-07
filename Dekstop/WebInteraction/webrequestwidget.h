#ifndef WEBREQUESTWIDGET_H
#define WEBREQUESTWIDGET_H

#include "webrequestbody.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>

class WebRequestWidget : public QWidget
{
    Q_OBJECT

private:
    WebRequestBody *requestBody;
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

