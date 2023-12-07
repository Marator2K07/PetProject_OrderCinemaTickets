#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    webContext = new WebContext(this);
    ui->webRequestWidget->setWebContext(webContext);
}

MainWindow::~MainWindow()
{
    delete ui;
}

