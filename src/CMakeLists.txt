cmake_minimum_required(VERSION 3.23)

# CPack
# su -
# cd src & pipx install conan
# pipx upgrade conan
# conan remote update conancenter --url="https://center2.conan.io"
# conan install . -s:b compiler=clang --output-folder=../build --build=missing
# cd build
# export QTIFWDIR=/opt/Qt/Tools/QtInstallerFramework/4.10/bin
# cpack -G "IFW;ZIP;DEB;RPM" -B Packaging


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
endif()

set(PROG_EXEC_NAME "${PROJECT_NAME}")
set(PROG_NAME "Metadata Tags Editor")
set(PROG_VERSION "${PROJECT_VERSION}")
set(PROG_HOMEPAGE "${PROJECT_HOMEPAGE_URL}")
set(PROG_DESCRIPTION "${PROJECT_DESCRIPTION}")
set(PROG_ORGANIZATION_NAME "ZHENG Robert")
set(PROG_ORGANIZATION_DOMAIN "net.hase-zheng")

set(PROG_BUILD_TYPE "${CMAKE_BUILD_TYPE}")

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

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    message("DEBUG mode")
    if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
        set(CMAKE_CXX_CLANG_TIDY clang-tidy;  -header-filter=.; -checks=cppcoreguidelines-*)
    ENDIF()
ENDIF()


# IFW needs to set external export QTIFWDIR=...
set(QTIFWDIR "/opt/Qt/Tools/QtInstallerFramework/4.10/bin")
include(InstallRequiredSystemLibraries)
set(CPACK_IFW_ROOT "${GLOBAL}/Qt/Tools/QtInstallerFramework/4.10")
set(CPACK_RESOURCE_FILE_LICENSE  ${CMAKE_CURRENT_SOURCE_DIR}/../LICENSE)
set(CPACK_PACKAGE_VENDOR "${PROG_AUTHOR}")
set(CPACK_PACKAGE_CONTACT "${PROG_AUTHOR_CONTACT}")
set(CPACK_RPM_PACKAGE_VENDOR "${PROG_AUTHOR_CONTACT}")
set(CPACK_PACKAGE_DESCRIPTION "${PROJECT_DESCRIPTION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "metadata editor")
set(CPACK_THREADS "6")
set(CPACK_PACKAGE_CHECKSUM SHA256)
set(CPACK_DEBIAN_PACKAGE_SECTION "editors")
set(CPACK_PACKAGE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/Packaging")
set(CPACK_GENERATOR "IFW;DEB;ZIP;RPM")

include(CPack)
