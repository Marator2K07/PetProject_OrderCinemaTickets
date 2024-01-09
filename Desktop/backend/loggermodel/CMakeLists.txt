qt_add_library(loggermodel STATIC
    ILoggerModel.h
    windowlogger/windowloggermodel.h
    windowlogger/windowloggermodel.cpp
)
target_link_libraries(loggermodel PRIVATE
    Qt6::Core
    Qt6::Qml
)
target_link_libraries(loggermodel PRIVATE
    #
)
target_include_directories(loggermodel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
