#include "webrequestwidget.h"

WebRequestWidget::WebRequestWidget(QWidget *parent)
    : QWidget{parent}
{
    // инициализация полей и их связей
    requestInfo = new WebRequestInfo(this);
    dataTextEdit = new QTextEdit(this);
    urlLineEdit = new QLineEdit(this);
    parseStatusLabel = new QLabel("Status");
    sendRequestButton = new QPushButton("Отправить", this);
    connect(sendRequestButton, SIGNAL(pressed()), this, SLOT(prepareInfo()));
    requestMethodType = new QComboBox(this);
    requestMethodType->insertItem(0, "GET", MethodType::GET);
    requestMethodType->insertItem(1, "POST", MethodType::POST);
    connect(requestMethodType, SIGNAL(currentIndexChanged(int)),
            this, SLOT(subwidgetsConditionChanges()));
    methodDataTypeComboBox = new QComboBox(this);
    methodDataTypeComboBox->insertItem(0, "TEXT", MethodBodyType::TEXT);
    methodDataTypeComboBox->insertItem(1, "JSON", MethodBodyType::JSON);

    // инициализация других виджетов и их связей
    QLabel *lineEditLabel = new QLabel("&Адрес запроса:", this);
    lineEditLabel->setBuddy(dataTextEdit);
    QLabel *textEditLabel = new QLabel("&Тело запроса:", this);
    textEditLabel->setBuddy(dataTextEdit);

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
    layout->addWidget(sendRequestButton);

    // включение/отключение  виджетов
    subwidgetsConditionChanges();
}

QComboBox *WebRequestWidget::getRequestMethodType() const
{
    return requestMethodType;
}

void WebRequestWidget::setRequestMethodType(QComboBox *newRequestMethodType)
{
    requestMethodType = newRequestMethodType;
}

QComboBox *WebRequestWidget::getMethodDataTypeComboBox() const
{
    return methodDataTypeComboBox;
}

void WebRequestWidget::setMethodDataTypeComboBox(QComboBox *newMethodDataTypeComboBox)
{
    methodDataTypeComboBox = newMethodDataTypeComboBox;
}

bool WebRequestWidget::correctText()
{
    // проверка на корректность текста пока довольно условна
    if (dataTextEdit->toPlainText().length() >= 1) {
        requestInfo->setContentType("text/plain");
        requestInfo->setData(QVariant::fromValue(dataTextEdit->toPlainText()));
        return true;
    } else {
        parseStatusLabel->setText("text is too short");
        return false;
    }
}

bool WebRequestWidget::correctJson()
{
    // пытаемся запарсить
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::
        fromJson(dataTextEdit->toPlainText().toUtf8(), &error);
    // возвращаем успешность парсинга, причем при успехе - пишем данные
    if (error.error == error.NoError) {
        requestInfo->setContentType("application/json");
        requestInfo->setData(QVariant::fromValue(doc.object()));
        return true;
    } else {
        parseStatusLabel->setText(error.errorString());
        return false;
    }
}

void WebRequestWidget::prepareInfo()
{
    bool correctParse = true;
    // если POST запрос, то нужна дополнительная обработка
    if ((MethodType)requestMethodType->currentIndex() == MethodType::POST) {
        // парсим в соотвествии с типом
        switch ((MethodBodyType)methodDataTypeComboBox->currentIndex()) {
        case MethodBodyType::TEXT:
            correctParse = correctText();
            break;
        case MethodBodyType::JSON:
            correctParse = correctJson();
            break;
        default:
            break;
        }
    }
    // если была ошибка на предыдущем этапе, то запрос отправлять нет смысла
    if (!correctParse) {
        return;
    }
    // подготоваливаем словарь и записываем данные запроса, далее отправляем их
    QHash<QString, QVariant> result;
    result.insert("Url", urlLineEdit->text());
    result.insert("Content type", requestInfo->getContentType());
    result.insert("Data", requestInfo->getData());
    emit requestReady(result);
}

void WebRequestWidget::catchWebResponseError(QNetworkReply *responce)
{
    if (responce->error() != QNetworkReply::NoError) {
        QString error = responce->errorString();
        parseStatusLabel->setText(error);
    } else if (responce->error() == QNetworkReply::NoError) {
        parseStatusLabel->setText("request was successfully processed");
    } else {
        parseStatusLabel->setText("unidentified situation");
    }
}

void WebRequestWidget::subwidgetsConditionChanges()
{
    MethodType curType = (MethodType)requestMethodType->currentIndex();
    if (curType == MethodType::GET) {
        dataTextEdit->setEnabled(false);
        methodDataTypeComboBox->setEnabled(false);
    } else if (curType == MethodType::POST) {
        dataTextEdit->setEnabled(true);
        methodDataTypeComboBox->setEnabled(true);
    }
}
