qt_add_library(webrequestform STATIC)

qt6_add_qml_module(webrequestform
    URI Web.Request.Form
    VERSION 1.0
    QML_FILES
        WebRequestForm.qml
    SOURCES
	webrequestinfo.h webrequestinfo.cpp	
    RESOURCES
        fonts/fonts.txt
)
