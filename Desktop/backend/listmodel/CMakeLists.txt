qt_add_library(listmodel STATIC
    enumlistmodel/enumitem.h
    enumlistmodel/enumitem.cpp
    enumlistmodel/enumlistmodel.h
    enumlistmodel/enumlistmodel.cpp
)
target_link_libraries(listmodel PRIVATE
    Qt6::Core
    Qt6::Qml
)
target_link_libraries(listmodel PRIVATE
    webinteraction
)
target_include_directories(listmodel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
