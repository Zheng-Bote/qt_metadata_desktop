cmake_minimum_required(VERSION 3.23)
project(
    qt_metadata_desktop
    VERSION 0.01.0
    DESCRIPTION "Desktop app to manage Exif/IPTC/XMP metadata tags"
    HOMEPAGE_URL "https://github.com/Zheng-Bote/qt_metadata_desktop"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(CMAKE_CXX_COMPILER clang++)
  # set(CMAKE_CXX_CLANG_TIDY clang-tidy; -header-filter=.;
  # -checks=cppcoreguidelines-*)
endif()

set(PROG_EXEC_NAME "${PROJECT_NAME}")
set(PROG_NAME "Metadata Tags Editor")
set(PROG_VERSION "${PROJECT_VERSION}")
set(PROG_HOMEPAGE "${PROJECT_HOMEPAGE_URL}")
set(PROG_DESCRIPTION "${PROJECT_DESCRIPTION}")
set(PROG_ORGANIZATION_NAME "ZHENG Robert")
set(PROG_ORGANIZATION_DOMAIN "net.hase-zheng")

configure_file("${CMAKE_SOURCE_DIR}/configure/rz_config.h.in"
               "${CMAKE_SOURCE_DIR}/includes/rz_config.h")


find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Sql Concurrent)
find_package (SQLite3 REQUIRED)

qt_standard_project_setup()

qt_add_executable(qt_metatags_desktop
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.hpp
    mainwindow.ui
    includes/rz_qt_metatags.hpp
    includes/database.cpp
    includes/database.hpp
    includes/sqlite3.cpp includes/sqlite3.hpp
    includes/rz_qt_metatags.cpp

)

target_link_libraries(qt_metatags_desktop
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Sql
        Qt6::Concurrent
        SQLite::SQLite3
)

include(GNUInstallDirs)

install(TARGETS qt_metatags_desktop
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET qt_metatags_desktop
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
