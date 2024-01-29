qt_add_library(menuitemmodel STATIC
    IMenuItemModel.h
)
target_link_libraries(menuitemmodel PRIVATE
    Qt6::Core
    Qt6::Qml
)
target_link_libraries(menuitemmodel PRIVATE
    #
)
target_include_directories(menuitemmodel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
