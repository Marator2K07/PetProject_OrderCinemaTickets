qt_add_library(webrequestmodel STATIC
    webrequestforminfo.h webrequestforminfo.cpp
    IWebRequestModel.h
)
target_link_libraries(webrequestmodel PRIVATE
    Qt6::Core
    Qt6::Qml
)
target_link_libraries(webrequestmodel PRIVATE
    webinteraction
)
target_include_directories(webrequestmodel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
