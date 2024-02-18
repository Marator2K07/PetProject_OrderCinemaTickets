qt_add_library(qmlconstants STATIC)
qt6_add_qml_module(qmlconstants
    URI "Qml.Constants"
    VERSION 1.0
    QML_FILES        
        ConstSizes.qml
        ConstColors.qml
)
