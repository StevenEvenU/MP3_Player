cmake_minimum_required(VERSION 3.19)
project(MP3_Player LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Multimedia)

qt_standard_project_setup()

qt_add_executable(MP3_Player
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    songcontrol.h
    songcontrol.cpp
)

target_link_libraries(MP3_Player
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Multimedia
)

install(TARGETS MP3_Player
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET MP3_Player
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
