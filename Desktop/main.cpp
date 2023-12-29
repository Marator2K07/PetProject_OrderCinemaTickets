#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/app_environment.h"

#include "RequestType.h"
#include "RequestBodyType.h"

#include "enumitemsmodel.h"
#include "webrequestforminfo.h"

int main(int argc, char *argv[])
{
    // устанвливаем окружение (пока ничего нет)
    set_qt_environment();

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // регистрация типов перечислений из библиотеки webinteraction
    qmlRegisterType<RequestType>("RequestTypes", 1, 0, "RequestTypes");
    qmlRegisterType<RequestBodyType>("RequestBodyTypes", 1, 0, "RequestBodyTypes");
    // и не только перечислений
    qmlRegisterType<EnumItemsModel>("EnumItemsModel", 1, 0, "EnumItemsModel");
    qmlRegisterType<WebRequestFormInfo>("WebRequestFormInfo", 1, 0, "WebRequestFormInfo");

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
