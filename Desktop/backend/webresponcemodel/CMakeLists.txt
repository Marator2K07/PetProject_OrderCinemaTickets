qt_add_library(webresponcemodel STATIC
    IWebResponceModel.h
    simplewindow/simplewindowmodel.h
    simplewindow/simplewindowmodel.cpp
)
target_link_libraries(webresponcemodel PRIVATE
    Qt6::Core
    Qt6::Qml
)
target_link_libraries(webresponcemodel PRIVATE
    webinteraction
)
target_include_directories(webresponcemodel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
