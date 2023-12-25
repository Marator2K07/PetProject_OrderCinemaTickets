qt_add_library(enumsmodel STATIC
    enumitem.h enumitem.cpp	
    enumitemsmodel.h enumitemsmodel.cpp
)
target_link_libraries(enumsmodel PRIVATE
    Qt6::Core
    Qt6::Qml
)
target_link_libraries(enumsmodel PRIVATE
    webinteraction
)
target_include_directories(enumsmodel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
