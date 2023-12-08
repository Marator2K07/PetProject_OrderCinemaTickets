#ifndef WEBREQUESTWIDGET_H
#define WEBREQUESTWIDGET_H

#include "webrequestbody.h"
#include "webcontext.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>

class WebRequestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WebRequestWidget(QWidget *parent = nullptr);

    WebContext *getWebContext() const;
    void setWebContext(WebContext *newWebContext);

private:
    WebContext *webContext;
    WebRequestBody *requestBody;
    QLineEdit *urlLineEdit;
    QTextEdit *dataTextEdit;
    QLabel *parseStatusLabel;
    QPushButton *sendRequestButton;

private slots:
    ///
    /// \brief tryParse
    /// проверка правильности ввода тела запроса
    void tryParseJson();
    ///
    /// \brief sendJson
    /// метод-слот для отправки запроса
    /// в виде Json файла через WebContext
    void sendJson();

signals:
    ///
    /// \brief jsonObjectReady
    /// в случае удачного парсинга
    void jsonObjectReady(QJsonObject jsonObject);

};

#endif // WEBREQUESTWIDGET_H
