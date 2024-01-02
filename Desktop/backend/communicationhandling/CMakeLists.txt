qt_add_library(communicationhandling STATIC
    communicationhandler.h
    communicationhandler.cpp
)
target_link_libraries(communicationhandling PRIVATE
    Qt6::Core
    Qt6::Network
)
target_link_libraries(communicationhandling PRIVATE
    # здесь, если нужно, подключаем свои собственные библиотеки
)
target_include_directories(communicationhandling PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
