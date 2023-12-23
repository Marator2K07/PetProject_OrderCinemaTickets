qt_add_library(webrequestform STATIC
    webrequestinfo.h webrequestinfo.cpp
)

qt6_add_qml_module(webrequestform
    URI WebRequestForm
    VERSION 1.0
    QML_FILES
        WebRequestForm.qml
    SOURCES
        webrequestinfo.h webrequestinfo.cpp               
)

target_link_libraries(webrequestform PRIVATE
    webinteraction
)
target_include_directories(webrequestform PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
