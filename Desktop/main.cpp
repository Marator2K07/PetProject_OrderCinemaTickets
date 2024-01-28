#include <QGuiApplication>

#include "src/app_environment.h"

#include "RequestEnums.h"
#include "enumitemsmodel.h"
#include "requestform/requestformmodel.h"
#include "fullviewlogger/fullviewloggermodel.h"
#include "rawresponce/rawresponcemodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // регистрация типов перечислений из библиотеки webinteraction
    qmlRegisterType<RequestEnums>("RequestEnums", 1, 0, "RequestEnums");
    // и не только перечислений
    qmlRegisterType<EnumItemsModel>("EnumItemsModel", 1, 0, "EnumItemsModel");
    qmlRegisterType<RequestFormModel>("RequestFormModel", 1, 0, "RequestFormModel");
    qmlRegisterType<FullViewLoggerModel>("FullViewLoggerModel", 1, 0, "FullViewLoggerModel");
    qmlRegisterType<RawResponceModel>("RawResponceModel", 1, 0, "RawResponceModel");

    // запоминаем все пути до основных визуальных элементов приложения
    const QUrl urlMain(u"qrc:/DesktopApp/Main.qml"_qs);
    const QUrl urlLogger(u"qrc:/DesktopApp/Logger.qml"_qs);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [urlMain](QObject *obj, const QUrl &objUrl) {
            if (!obj && urlMain == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    // загружаем путь для импорта модуля/плагина в заданной папке
    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");

    // создаем важные обьекты для приложения, которые будут использоваться глобально
    QHash<QString, QObject *> rootObjects = set_root_context_properties(engine);

    engine.load(urlLogger);
    engine.load(urlMain);

    return app.exec();
}
