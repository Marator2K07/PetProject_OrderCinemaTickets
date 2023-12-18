qt_add_library(qmlelements STATIC)
qt6_add_qml_module(qmlelements
    URI "qmlelements"
    VERSION 1.0
    QML_FILES
        WebRequestForm.qml
    RESOURCES
        fonts/fonts.txt
)
