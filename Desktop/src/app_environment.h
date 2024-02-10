#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QHash>

#include "requestresponcehandling.h"
#include "webcontext.h"
#include "logger.h"

#include "modulestorage.h"
#include "enumlistmodel/enumlistmodel.h"
#include "requestform/requestformmodel.h"
#include "fullviewlogger/fullviewloggermodel.h"
#include "rawresponce/rawresponcemodel.h"
#include "buttonmenuitem/buttonmenuitemmodel.h"

void set_qt_environment()
{
    //qputenv("QT_QUICK_CONTROLS_CONF", ":/qtquickcontrols2.conf");
}

void set_qml_types() {
    // регистрация типов перечислений из библиотеки webinteraction
    qmlRegisterType<RequestEnums>("RequestEnums", 1, 0, "RequestEnums");
    // и не только перечислений
    qmlRegisterType<EnumListModel>("EnumListModel", 1, 0, "EnumListModel");
    qmlRegisterType<RequestFormModel>("RequestFormModel", 1, 0, "RequestFormModel");
    qmlRegisterType<FullViewLoggerModel>("FullViewLoggerModel", 1, 0, "FullViewLoggerModel");
    qmlRegisterType<RawResponceModel>("RawResponceModel", 1, 0, "RawResponceModel");
    qmlRegisterType<ButtonMenuItemModel>("ButtonMenuItemModel", 1, 0, "ButtonMenuItemModel");
}

ModuleStorage *initStorage() {
    ModuleStorage *moduleStorage = new ModuleStorage();
    // ...
    return moduleStorage;
}

QHash<QString, QObject *> set_root_context_properties(QQmlApplicationEngine &engine) {
    // создаем и инициализируем при возможности эти важные обьекты
    Logger *logger = new Logger("/","log.txt");
    WebContext *webContext = new WebContext;
    ModuleStorage *moduleStorage = initStorage();
    RequestResponceHandling *responceHandler = new RequestResponceHandling;
    // связываем, что нужно
    QObject::connect(webContext, SIGNAL(startProcessingReply(QNetworkReply *, RequestEnums::Identifier)),
                     responceHandler, SLOT(processingResponce(QNetworkReply *, RequestEnums::Identifier)));
    // назначаем корневые qml свойства
    engine.rootContext()->setContextProperty("logger", logger);
    engine.rootContext()->setContextProperty("webContext", webContext);
    engine.rootContext()->setContextProperty("moduleStorage", moduleStorage);
    engine.rootContext()->setContextProperty("responceHandler", responceHandler);
    // на возврате на всякий случай получаем хэш-словарь наших корневых обьектов
    QHash<QString, QObject *> rootObjects;
    rootObjects.insert("logger", logger);
    rootObjects.insert("webContext", webContext);
    rootObjects.insert("moduleStorage", moduleStorage);
    rootObjects.insert("responceHandler", responceHandler);
    return rootObjects;
}
