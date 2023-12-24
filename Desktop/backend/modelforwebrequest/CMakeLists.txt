qt_add_library(modelforwebrequest STATIC
    
)
target_link_libraries(modelforwebrequest PRIVATE
    Qt6::Core
    Qt6::Qml
)
target_link_libraries(modelforwebrequest PRIVATE
    webinteraction
)
target_include_directories(modelforwebrequest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
