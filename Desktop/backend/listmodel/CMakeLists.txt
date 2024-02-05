qt_add_library(listmodel STATIC
    menulistmodel/menulistmodel.h
    menulistmodel/menulistmodel.cpp
)
target_link_libraries(listmodel PRIVATE
    Qt6::Core
    Qt6::Qml
)
target_link_libraries(listmodel PRIVATE
    menuitemmodel
)
target_include_directories(listmodel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
