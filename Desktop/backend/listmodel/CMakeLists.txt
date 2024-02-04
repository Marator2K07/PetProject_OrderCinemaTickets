qt_add_library(listmodel STATIC
)
target_link_libraries(listmodel PRIVATE
    Qt6::Core
    Qt6::Qml
)
target_link_libraries(listmodel PRIVATE
    #
)
target_include_directories(listmodel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
