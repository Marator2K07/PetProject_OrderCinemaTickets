qt_add_library(qmlcustom STATIC)
qt6_add_qml_module(qmlcustom
    URI "Qml.Custom"
    VERSION 1.0
    QML_FILES
        CustomComboBox.qml
        MyLineText.qml
        MyMultiLineText.qml
        WebRequestForm.qml
	CustomButton.qml
	WindowLogger.qml
        LoadingScreen.qml
        RawResponceSection.qml
    RESOURCE_PREFIX "/"
    RESOURCES
        web_request_form.js
)
