qt_add_library(qmlpages STATIC)
qt6_add_qml_module(qmlpages 
    URI "Qml.Pages"
    VERSION 1.0
    QML_FILES
        TemplatePage.qml
        WelcomePage.qml        
)
# устанавливаем связь/подключаем нужные библиотеки
target_link_libraries(qmlpages PRIVATE
    qmlconstantsplugin
)
