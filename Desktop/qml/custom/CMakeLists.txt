qt_add_library(qmlcustom STATIC)
qt6_add_qml_module(qmlcustom
    URI "Qml.Custom"
    VERSION 1.0
    QML_FILES
        CustomComboBox.qml
        LineTextInput.qml
        MultiLineTextInput.qml
        WebRequestForm.qml
	CustomButton.qml
	WindowLogger.qml
        LoadingScreen.qml
    RESOURCE_PREFIX "/"
    RESOURCES
        web_request_form.js
)
