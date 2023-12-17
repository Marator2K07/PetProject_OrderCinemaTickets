qt_add_library(webinteraction STATIC
    webcontext.h
    webcontext.cpp
    webrequestinfo.h
    webrequestinfo.cpp
    typesforrequestmethod.h
)
target_link_libraries(webinteraction PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Network
)
target_include_directories(webinteraction INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

