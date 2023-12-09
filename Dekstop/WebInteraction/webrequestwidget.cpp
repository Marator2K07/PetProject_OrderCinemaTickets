#include "webrequestwidget.h"

WebRequestWidget::WebRequestWidget(QWidget *parent)
    : QWidget{parent}
{
    // инициализация полей и их связей
    requestBody = new WebRequestBody(this);
    connect(this, SIGNAL(jsonObjectReady(QJsonObject)),
            requestBody, SLOT(setJsonData(QJsonObject)));
    dataTextEdit = new QTextEdit(this);
    urlLineEdit = new QLineEdit(this);
    parseStatusLabel = new QLabel("Status");
    sendRequestButton = new QPushButton("Отправить", this);
    connect(sendRequestButton, SIGNAL(pressed()), this, SLOT(sendJson()));
    requestMethodType = new QComboBox(this);
    requestMethodType->insertItem(0, "GET", MethodType::GET);
    requestMethodType->insertItem(1, "POST", MethodType::POST);

    // инициализация других виджетов и их связей
    QLabel *lineEditLabel = new QLabel("&Адрес запроса:", this);
    lineEditLabel->setBuddy(dataTextEdit);
    QLabel *textEditLabel = new QLabel("&Тело запроса:", this);
    textEditLabel->setBuddy(dataTextEdit);
    QPushButton *parseButton = new QPushButton("Проверить тело запроса", this);
    connect(parseButton, SIGNAL(pressed()), this, SLOT(tryParseJson()));

    // установки компоновщиков
    QHBoxLayout *verLayout = new QHBoxLayout();
    verLayout->addWidget(lineEditLabel);
    verLayout->addWidget(urlLineEdit);
    verLayout->addWidget(requestMethodType);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(verLayout);
    layout->addWidget(textEditLabel);
    layout->addWidget(dataTextEdit);
    layout->addWidget(parseStatusLabel);
    layout->addWidget(parseButton);
    layout->addWidget(sendRequestButton);
}

QComboBox *WebRequestWidget::getRequestMethodType() const
{
    return requestMethodType;
}

void WebRequestWidget::setRequestMethodType(QComboBox *newRequestMethodType)
{
    requestMethodType = newRequestMethodType;
}

void WebRequestWidget::tryParseJson()
{
    // пытаемся запарсить
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::
        fromJson(dataTextEdit->toPlainText().toUtf8(), &error);
    // выводим успешность парсинга
    parseStatusLabel->setText(error.errorString());
}

void WebRequestWidget::sendJson()
{
    // парсим
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::
        fromJson(dataTextEdit->toPlainText().toUtf8(), &error);
    // если все в порядке
    if (error.error == error.NoError) {
        emit jsonObjectReady(doc.object());
    }
    // анализируем текущий обьект джейсона, если впорядке - отправляем
    QJsonObject curJson = requestBody->getJsonData();
    if(!curJson.isEmpty() && urlLineEdit->text().length() > 0) {
        webContext->sendPostRequest(urlLineEdit->text(), curJson);
        parseStatusLabel->setText("succesful sended");
    } else {
        parseStatusLabel->setText("error while sending");
    }
}
