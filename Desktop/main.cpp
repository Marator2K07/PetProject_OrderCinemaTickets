#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/app_environment.h"
#include "RequestEnums.h"
#include "enumitemsmodel.h"
#include "webcontext.h"
#include "requestresponcehandling.h"
#include "requestform/requestformmodel.h"

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

    const QUrl url(u"qrc:/DesktopApp/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
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

    engine.load(url);

    return app.exec();
}
