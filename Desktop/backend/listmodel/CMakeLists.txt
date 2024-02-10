qt_add_library(listmodel STATIC
    enumslistmodel/enumitem.h
    enumslistmodel/enumitem.cpp
    enumslistmodel/enumitemsmodel.h
    enumslistmodel/enumitemsmodel.cpp
)
target_link_libraries(listmodel PRIVATE
    Qt6::Core
    Qt6::Qml
)
target_link_libraries(listmodel PRIVATE
    webinteraction
)
target_include_directories(listmodel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
