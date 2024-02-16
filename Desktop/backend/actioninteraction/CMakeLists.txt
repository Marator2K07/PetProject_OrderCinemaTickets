qt_add_library(actioninteraction STATIC
    IAction.h
    actioncontext.h actioncontext.cpp
    clickaction.h clickaction.cpp
)
target_link_libraries(actioninteraction PRIVATE
    Qt6::Core
    Qt6::Qml
)
target_link_libraries(actioninteraction PRIVATE
)
target_include_directories(actioninteraction PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
