#ifndef WEBREQUESTWIDGET_H
#define WEBREQUESTWIDGET_H

#include "MethodType.h"
#include "webrequestinfo.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QHash>

class WebRequestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WebRequestWidget(QWidget *parent = nullptr);

    WebContext *getWebContext() const;
    void setWebContext(WebContext *newWebContext);

private:
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
