#include "webrequestdatawidget.h"

WebRequestDataWidget::WebRequestDataWidget(QWidget *parent)
    : QWidget{parent}
{
    // инициализация полей/виджетов
    textEdit = new QTextEdit(this);
    QLabel *textEditLabel = new QLabel("Текст &Json запроса:", this);
    textEditLabel->setBuddy(textEdit);
    // установки компоновщика
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textEditLabel);
    layout->addWidget(textEdit);
}
