qt_add_library(webinteraction STATIC
    webcontext.h webcontext.cpp
    webrequestinfo.h webrequestinfo.cpp
)
target_link_libraries(webinteraction PRIVATE
    Qt6::Core
    Qt6::Network
    Qt6::Qml
)
target_include_directories(webinteraction INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

