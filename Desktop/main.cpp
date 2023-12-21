#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "src/app_environment.h"

int main(int argc, char *argv[])
{
    // устанвливаем окружение (пока ничего нет)
    set_qt_environment();

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/DesktopApp/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    // загружаем путь для импорта модуля/плагина в заданной папке
    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");

    engine.load(url);

    return app.exec();
}
