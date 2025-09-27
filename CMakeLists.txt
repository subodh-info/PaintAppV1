cmake_minimum_required(VERSION 3.19)
project(PaintAppV1 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(PaintAppV1
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    paintcanvas.h paintcanvas.cpp
    resource.qrc
)

target_link_libraries(PaintAppV1
    PRIVATE
        Qt::Core
        Qt::Widgets
)
target_link_libraries(PaintAppV1 PRIVATE Qt6::Widgets)

include(GNUInstallDirs)

install(TARGETS PaintAppV1
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET PaintAppV1
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
