#include "webrequestdatawidget.h"

WebRequestDataWidget::WebRequestDataWidget(QWidget *parent)
    : QWidget{parent}
{
    // инициализация полей и их связей
    requestBody = new WebRequestBody(this);
    connect(this, SIGNAL(jsonObjectReady(QJsonObject)),
            requestBody, SLOT(setJsonData(QJsonObject)));
    textEdit = new QTextEdit(this);
    parseStatusLabel = new QLabel("Status");

    // инициализация виджетов и их связей
    QLabel *textEditLabel = new QLabel("Текст &Json запроса:", this);
    textEditLabel->setBuddy(textEdit);
    QPushButton *parseButton = new QPushButton("Запарсить", this);
    connect(parseButton, SIGNAL(pressed()), this, SLOT(tryParse()));

    // установки компоновщика
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textEditLabel);
    layout->addWidget(textEdit);
    layout->addWidget(parseStatusLabel);
    layout->addWidget(parseButton);
}

void WebRequestDataWidget::tryParse()
{
    // пытаемся запарсить
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::
        fromJson(textEdit->toPlainText().toUtf8(), &error);
    parseStatusLabel->setText(error.errorString());
    // если все в порядке
    if (error.error == error.NoError) {
        currentJsonData = doc.object();
        emit jsonObjectReady(currentJsonData);
    }
}
