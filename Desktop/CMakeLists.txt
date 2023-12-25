cmake_minimum_required(VERSION 3.16)

project(DesktopApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS
    Core
    Widgets
    Network
    Qml
    Quick
)

add_subdirectory(backend)

qt6_add_executable(appDesktopApp
    main.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appDesktopApp PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appDesktopApp
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appDesktopApp PRIVATE
    Qt6::Quick
    Qt6::Qml
)
target_link_libraries(appDesktopApp PRIVATE
    webinteraction
    modelforenums
)

include(GNUInstallDirs)
install(TARGETS appDesktopApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
# вся работа с qml файлами происходит здесь
include(${CMAKE_CURRENT_SOURCE_DIR}/qmlsettings)
