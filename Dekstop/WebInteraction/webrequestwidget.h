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

    QComboBox *getRequestMethodType() const;
    void setRequestMethodType(QComboBox *newRequestMethodType);

private:
    WebRequestInfo *requestInfo;
    QLineEdit *urlLineEdit;
    QTextEdit *dataTextEdit;
    QLabel *parseStatusLabel;
    QPushButton *sendRequestButton;
    QComboBox *requestMethodType;

private slots:
    ///
    /// \brief tryParseJson
    /// проверка правильности ввода тела запроса как Json файла
    void tryParseJson();
    ///
    /// \brief prepareInfo
    /// подготавливаем данные для передачи веб контексту
    void prepareInfo();
    ///
    /// \brief catchWebResponse
    /// ловим ответ от класса веб контекста
    void catchWebResponse(QNetworkReply *responce);

signals:
    ///
    /// \brief jsonObjectReady
    /// в случае удачного парсинга
    void jsonObjectReady(QJsonObject jsonObject);
    ///
    /// \brief requestReady
    /// когда считали всю информацию с виджета
    void requestReady(QHash<QString, QVariant> request);
};

#endif // WEBREQUESTWIDGET_H
