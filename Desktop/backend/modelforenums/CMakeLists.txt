qt_add_library(modelforenums STATIC
    enumitem.h enumitem.cpp	
    comboboxmodel.h comboboxmodel.cpp	
)
target_link_libraries(modelforenums PRIVATE
    Qt6::Core
    Qt6::Qml
)
target_link_libraries(modelforenums PRIVATE
    webinteraction
)
target_include_directories(modelforenums PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
