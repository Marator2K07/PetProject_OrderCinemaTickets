#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/app_environment.h"
#include "RequestEnums.h"
#include "enumitemsmodel.h"
#include "webcontext.h"
#include "logger.h"
#include "requestresponcehandling.h"
#include "requestform/requestformmodel.h"
#include "loggersection/loggersectionmodel.h"

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
    qmlRegisterType<LoggerSectionModel>("LoggerSectionModel", 1, 0, "LoggerSectionModel");

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

    // создаем важные обьекты для приложения,
    // которые будут использоваться глобально
    Logger logger("/","log.txt");
    WebContext webContext;
    RequestResponceHandling responceHandler;
    // связываем, что нужно
    QObject::connect(&webContext, SIGNAL(startProcessingReply(QNetworkReply *, RequestEnums::Identifier)),
                     &responceHandler, SLOT(processingResponce(QNetworkReply *, RequestEnums::Identifier)));

    // назначаем корневые qml свойства
    engine.rootContext()->setContextProperty("logger", &logger);
    engine.rootContext()->setContextProperty("webContext", &webContext);
    engine.rootContext()->setContextProperty("responceHandler", &responceHandler);

    engine.load(urlLogger);
    engine.load(urlMain);

    return app.exec();
}
