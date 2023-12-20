qt_add_library(qmlcustomwidgets STATIC)
qt6_add_qml_module(qmlcustomwidgets
    URI QmlCustomWidgets
    VERSION 1.0
    QML_FILES
        LineTextInput.qml
        MultiLineTextInput.qml
        CustomComboBox.qml
)
