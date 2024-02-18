qt_add_library(qmlpages STATIC)
qt6_add_qml_module(qmlpages 
    URI "Qml.Pages"
    VERSION 1.0
    QML_FILES
        WelcomePage.qml
)
