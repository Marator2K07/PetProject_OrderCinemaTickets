#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    webContext = new WebContext(ui->webRequestWidget, this);
    webContext->ignoreSslVerify(); // отключаем верификацию
}

MainWindow::~MainWindow()
{
    delete ui;
}

