qt_add_library(webinteraction STATIC
    RequestBodyType.h
    RequestType.h
    webcontext.h webcontext.cpp
    requestresponcehandling.h requestresponcehandling.cpp
)
target_link_libraries(webinteraction PRIVATE
    Qt6::Core
    Qt6::Network
)
target_link_libraries(webinteraction PRIVATE
    webrequestmodel
    webresponcemodel
)
target_include_directories(webinteraction PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
