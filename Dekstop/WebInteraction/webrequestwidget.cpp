#include "webrequestwidget.h"

WebContext *WebRequestWidget::getWebContext() const
{
    return webContext;
}

void WebRequestWidget::setWebContext(WebContext *newWebContext)
{
    webContext = newWebContext;
}

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

    // инициализация других виджетов и их связей
    QLabel *lineEditLabel = new QLabel("&Адрес запроса:", this);
    lineEditLabel->setBuddy(dataTextEdit);
    QLabel *textEditLabel = new QLabel("&Тело запроса (json):", this);
    textEditLabel->setBuddy(dataTextEdit);
    QPushButton *parseButton = new QPushButton("Запарсить", this);
    connect(parseButton, SIGNAL(pressed()), this, SLOT(tryParse()));
    QPushButton *sendButton = new QPushButton("Отправить", this);
    connect(sendButton, SIGNAL(pressed()), this, SLOT(sendJson()));

    // установки компоновщика
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(lineEditLabel);
    layout->addWidget(urlLineEdit);
    layout->addWidget(textEditLabel);
    layout->addWidget(dataTextEdit);
    layout->addWidget(parseStatusLabel);
    layout->addWidget(parseButton);
    layout->addWidget(sendButton);
}

void WebRequestWidget::tryParse()
{
    // пытаемся запарсить
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::
        fromJson(dataTextEdit->toPlainText().toUtf8(), &error);
    parseStatusLabel->setText(error.errorString());
    // если все в порядке
    if (error.error == error.NoError) {
        emit jsonObjectReady(doc.object());
    }
}

void WebRequestWidget::sendJson()
{
    // анализируем текущий обьект джейсона, если впорядке - отправляем
    QJsonObject curJson = requestBody->getJsonData();
    if(!curJson.isEmpty()) {
        webContext->sendPostRequest("https://localhost:7053/animal/new", curJson);
        parseStatusLabel->setText("Succesful sended");
    } else {
        parseStatusLabel->setText("Error while send");
    }
}
