qt_add_library(qmlcustom STATIC)
qt6_add_qml_module(qmlcustom
    URI "Qml.Custom"
    VERSION 1.0
    QML_FILES
        MyComboBox.qml
        MyLineText.qml
        MyMultiLineText.qml
        WebRequestForm.qml
        MyButton.qml
        LoggerSection.qml
        LoadingScreen.qml
        RawResponceSection.qml
        ButtonMenuItem.qml
        AdaptiveMenu.qml
        AdaptiveContextMenu.qml
    RESOURCE_PREFIX "/"
    RESOURCES
        web_request_form.js
)
