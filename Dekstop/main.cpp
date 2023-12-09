#include "mainwindow.h"
#include "WebInteraction/webcontext.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //WebContext webContext;
    //webContext.sendGetRequest("https://localhost:7139/", QList<QString>{});

    return a.exec();
}
