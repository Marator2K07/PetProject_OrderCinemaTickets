qt_add_library(logger STATIC
    ILoggingObject.h
    logger.h logger.cpp
)
target_link_libraries(logger PRIVATE
    Qt6::Core
)
target_link_libraries(logger PRIVATE
    #
)
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
