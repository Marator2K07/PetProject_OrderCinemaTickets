qt_add_library(qmlCustom STATIC)
qt6_add_qml_module(qmlCustom
    URI "Custom"
    VERSION 1.0
    QML_FILES
        CustomComboBox.qml
        LineTextInput.qml
        MultiLineTextInput.qml
    RESOURCE_PREFIX "/"	
)
