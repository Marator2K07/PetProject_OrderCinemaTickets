qt_add_library(webrequestmodel STATIC     
    IWebRequestModel.h
    requestform/requestformmodel.h
    requestform/requestformmodel.cpp
)
target_link_libraries(webrequestmodel PRIVATE
    Qt6::Core
    Qt6::Qml
)
target_link_libraries(webrequestmodel PRIVATE
    webinteraction
    logger
)
target_include_directories(webrequestmodel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
