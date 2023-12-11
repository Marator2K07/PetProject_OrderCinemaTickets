#include "webrequestwidget.h"

WebRequestWidget::WebRequestWidget(QWidget *parent)
    : QWidget{parent}
{
    // инициализация полей и их связей
    requestInfo = new WebRequestInfo(this);
    connect(this, SIGNAL(jsonObjectReady(QJsonObject)),
            requestInfo, SLOT(setJsonData(QJsonObject)));
    dataTextEdit = new QTextEdit(this);
    urlLineEdit = new QLineEdit(this);
    parseStatusLabel = new QLabel("Status");
    sendRequestButton = new QPushButton("Отправить", this);
    connect(sendRequestButton, SIGNAL(pressed()), this, SLOT(prepareInfo()));
    requestMethodType = new QComboBox(this);
    requestMethodType->insertItem(0, "GET", MethodType::GET);
    requestMethodType->insertItem(1, "POST", MethodType::POST);
    methodDataTypeComboBox = new QComboBox(this);
    methodDataTypeComboBox->insertItem(0, "TEXT", MethodBodyType::TEXT);
    methodDataTypeComboBox->insertItem(1, "JSON", MethodBodyType::JSON);

    // инициализация других виджетов и их связей
    QLabel *lineEditLabel = new QLabel("&Адрес запроса:", this);
    lineEditLabel->setBuddy(dataTextEdit);
    QLabel *textEditLabel = new QLabel("&Тело запроса:", this);
    textEditLabel->setBuddy(dataTextEdit);
    QPushButton *parseButton = new QPushButton("Проверить тело запроса как Json", this);
    connect(parseButton, SIGNAL(pressed()), this, SLOT(tryParseJson()));

    // установки компоновщиков
    QHBoxLayout *verLayout = new QHBoxLayout();
    verLayout->addWidget(lineEditLabel);
    verLayout->addWidget(urlLineEdit);
    verLayout->addWidget(requestMethodType);
    QHBoxLayout *hDataLayout = new QHBoxLayout();
    hDataLayout->addWidget(textEditLabel);
    hDataLayout->addWidget(methodDataTypeComboBox);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(verLayout);
    layout->addLayout(hDataLayout);
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

void WebRequestWidget::prepareInfo()
{    
    // если POST запрос
    // тестовая реализация!
    if ((MethodType)requestMethodType->currentIndex() == MethodType::POST) {
        // парсим
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::
            fromJson(dataTextEdit->toPlainText().toUtf8(), &error);
        // если все в порядке
        if (error.error == error.NoError) {
            emit jsonObjectReady(doc.object());
            requestInfo->setContentType("application/json");
        }
    }

    // подготоваливаем словарь и записываем данные запроса и отправляем их
    QHash<QString, QVariant> result;
    result.insert("Url", urlLineEdit->text());
    result.insert("Content type", requestInfo->getContentType());
    result.insert("Data", requestInfo->getData());
    emit requestReady(result);
}

void WebRequestWidget::catchWebResponse(QNetworkReply *responce)
{
    parseStatusLabel->setText(responce->errorString());
}
