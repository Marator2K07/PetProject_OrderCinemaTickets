qt_add_library(actioninteraction STATIC
    IAction.h
    actioncontext.h actioncontext.cpp
)
target_link_libraries(actioninteraction PRIVATE
    Qt6::Core
)
target_link_libraries(actioninteraction PRIVATE
)
target_include_directories(actioninteraction PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
