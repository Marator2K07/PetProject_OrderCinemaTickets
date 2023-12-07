#include "webrequestdatawidget.h"

WebRequestDataWidget::WebRequestDataWidget(QWidget *parent)
    : QWidget{parent}
{
    // инициализация полей/виджетов
    textEdit = new QTextEdit(this);
    parseStatusLabel = new QLabel("Status");
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

}
