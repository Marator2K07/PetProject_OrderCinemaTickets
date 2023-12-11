#ifndef WEBREQUESTWIDGET_H
#define WEBREQUESTWIDGET_H

#include "typesforrequestmethod.h"
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
    QComboBox *getMethodDataTypeComboBox() const;
    void setMethodDataTypeComboBox(QComboBox *newMethodDataTypeComboBox);

private:
    WebRequestInfo *requestInfo;
    QLineEdit *urlLineEdit;
    QTextEdit *dataTextEdit;
    QLabel *parseStatusLabel;
    QPushButton *sendRequestButton;
    QComboBox *requestMethodType;
    QComboBox *methodDataTypeComboBox ; // выбор типа данных тела запроса

    ///
    /// \brief correctText
    /// проверка правильности ввода тела запроса как обычного текста
    bool correctText();
    ///
    /// \brief correctJson
    /// проверка правильности ввода тела запроса как Json файла
    bool correctJson();

private slots:
    ///
    /// \brief prepareInfo
    /// подготавливаем данные для передачи веб контексту
    void prepareInfo();
    ///
    /// \brief catchWebResponse
    /// ловим ответ от класса веб контекста
    void catchWebResponseError(QNetworkReply *responce);

signals:
    ///
    /// \brief requestReady
    /// когда считали всю информацию с виджета
    void requestReady(QHash<QString, QVariant> request);
};

#endif // WEBREQUESTWIDGET_H
