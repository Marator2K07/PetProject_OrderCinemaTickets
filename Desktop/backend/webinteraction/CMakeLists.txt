qt_add_library(webinteraction STATIC
    types.h
)
target_link_libraries(webinteraction PRIVATE
    Qt6::Core
    Qt6::Network
    Qt6::Qml
    Qt6::Widgets    
)
target_link_libraries(webinteraction PRIVATE
    webrequestform
)
target_include_directories(webinteraction PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
