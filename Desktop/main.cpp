#include "src/app_environment.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    // регистрируем свои qml типы
    set_qml_types();

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
    QHash<QString, QObject *> rootObjects = set_root_context_properties(engine, app);

    engine.load(urlLogger);
    engine.load(urlMain);

    return app.exec();
}
