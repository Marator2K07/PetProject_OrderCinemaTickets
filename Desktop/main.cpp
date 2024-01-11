#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/app_environment.h"
#include "RequestEnums.h"
#include "enumitemsmodel.h"
#include "webcontext.h"
#include "requestresponcehandling.h"
#include "requestform/requestformmodel.h"
#include "windowlogger/windowloggermodel.h"

int main(int argc, char *argv[])
{
    // устанвливаем окружение (пока ничего нет)
    set_qt_environment();

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // регистрация типов перечислений из библиотеки webinteraction
    qmlRegisterType<RequestEnums>("RequestEnums", 1, 0, "RequestEnums");
    // и не только перечислений
    qmlRegisterType<EnumItemsModel>("EnumItemsModel", 1, 0, "EnumItemsModel");
    qmlRegisterType<RequestFormModel>("RequestFormModel", 1, 0, "RequestFormModel");
    qmlRegisterType<WindowLoggerModel>("WindowLoggerModel", 1, 0, "WindowLoggerModel");

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

    // связываем два взаимодействующих класса для работы с запросами/ответами сразу
    WebContext webContext;
    RequestResponceHandling responceHandler;
    QObject::connect(&webContext, SIGNAL(startProcessingReply(QNetworkReply*)),
                     &responceHandler, SLOT(processingResponce(QNetworkReply*)));

    // назначаем корневые qml свойства
    engine.rootContext()->setContextProperty("webContext", &webContext);
    engine.rootContext()->setContextProperty("responceHandler", &responceHandler);

    engine.load(urlLogger);
    engine.load(urlMain);

    return app.exec();
}
