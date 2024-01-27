qt_add_library(modulestorage STATIC
    modulestorage.h modulestorage.cpp    
)
target_link_libraries(modulestorage PRIVATE
    Qt6::Core
)
target_link_libraries(modulestorage PRIVATE
    #
)
target_include_directories(modulestorage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
