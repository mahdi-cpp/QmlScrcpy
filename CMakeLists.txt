# For VS2019 and Xcode 12+ support.
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

# Global config
#

# QC is "Qt CMake"
# https://www.kdab.com/wp-content/uploads/stories/QTVTC20-Using-Modern-CMake-Kevin-Funk.pdf

# QC Custom config
set(QC_PROJECT_NAME "QtScrcpy")
# Read version numbers from file
file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/version QC_FILE_VERSION)
set(QC_PROJECT_VERSION ${QC_FILE_VERSION})

configure_file(
        res/opengl/squircle.vsh
        res/opengl/squircle.fsh
)

# Project declare
project(${QC_PROJECT_NAME} VERSION ${QC_PROJECT_VERSION} LANGUAGES CXX)
message(STATUS "[${PROJECT_NAME}] Project ${PROJECT_NAME} ${PROJECT_VERSION}")

# QC define

# check arch
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(QC_CPU_ARCH x64)
else ()
    set(QC_CPU_ARCH x86)
endif ()
message(STATUS "[${PROJECT_NAME}] CPU_ARCH:${QC_CPU_ARCH}")

# CMake set
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# default RelWithDebInfo
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif ()
message(STATUS "[${PROJECT_NAME}] BUILD_TYPE:${CMAKE_BUILD_TYPE}")

# Compiler set
message(STATUS "[${PROJECT_NAME}] C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")


message(STATUS "[${PROJECT_NAME}] Set warnings as error")
# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic -Werror)

# disable some warning
add_compile_options(-Wno-nested-anon-types -Wno-c++17-extensions -Wno-overloaded-virtual)


#
# Qt
#

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Network Multimedia WebSockets Quick Qml REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Network Multimedia WebSockets Quick Qml REQUIRED)
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(QT NAMES Qt6 Qt5 COMPONENTS X11Extras REQUIRED)
    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS X11Extras REQUIRED)
endif ()

message(STATUS "[${PROJECT_NAME}] Qt version is: ${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}")


# Sources
# main
set(QC_MAIN_SOURCES main.cpp)

# ui
set(QC_UI_SOURCES
        ui/scene/Scene.h
        ui/scene/Scene.cpp
        ui/scene/SceneRenderer.h
        ui/scene/SceneRenderer.cpp

        ui/sceneprovider/SceneProvider.h
        ui/sceneprovider/SceneProvider.cpp
        ui/sceneprovider/SceneProviderRenderer.h
        ui/sceneprovider/SceneProviderRenderer.cpp

        ui/service/ServiceManager.h
        ui/service/ServiceManager.cpp
        ui/service/ResourceService.h
        ui/service/ResourceService.cpp

        ui/service/websocket/websocket.cpp
        ui/service/websocket/websocket.h
        ui/service/websocket/State.cpp
        ui/service/websocket/State.h

        ui/service/udp/Broadcast.h
        ui/service/udp/Broadcast.cpp

        ui/scene/MainWindow.cpp
        ui/scene/MainWindow.h
        ui/scene/PieChart.cpp
        ui/scene/PieChart.h

        ui/util/config.h
        ui/util/config.cpp

        ui/render/OpenGLWindow.cpp
        ui/render/OpenGLWindow.h
        ui/render/TriangleWindow.cpp
        ui/render/TriangleWindow.h
        ui/render/qyuvopenglwidget.h
        ui/render/qyuvopenglwidget.cpp

        ui/render/LogoRenderer/logorenderer.h
        ui/render/LogoRenderer/logorenderer.cpp
        ui/render/LogoRenderer/fboinsgrenderer.h
        ui/render/LogoRenderer/fboinsgrenderer.cpp
        )

# Translation related (use shell script instead of cmake to handle translation)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/res/i18n)

# all sources
set(QC_PROJECT_SOURCES
        ${QC_MAIN_SOURCES}
        ${QC_UI_SOURCES})


add_executable(${PROJECT_NAME} ${QC_RUNTIME_TYPE} ${QC_PROJECT_SOURCES})

#
# Internal include path (todo: remove this, use absolute path include)
#

target_include_directories(${PROJECT_NAME} PRIVATE ui/toolform/fontawesome)
target_include_directories(${PROJECT_NAME} PRIVATE ui/util)
target_include_directories(${PROJECT_NAME} PRIVATE uibase)
target_include_directories(${PROJECT_NAME} PRIVATE ui)
target_include_directories(${PROJECT_NAME} PRIVATE ui/render)

# output dir
# https://cmake.org/cmake/help/latest/prop_gbl/GENERATOR_IS_MULTI_CONFIG.html
get_property(QC_IS_MUTIL_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
message(STATUS "multi config:" QC_IS_MUTIL_CONFIG)

# $<0:> Use a generator expression to set RUNTIME_OUTPUT_DIRECTORY for each config, so that multi config will not automatically append the CMAKE_BUILD_TYPE subdirectory
# 1. multi config introduce https://cmake.org/cmake/help/latest/prop_gbl/GENERATOR_IS_MULTI_CONFIG.html

# 2. multi config Automatically append subdirectory descriptions when not using the expression builder
# https://cmake.org/cmake/help/latest/prop_tgt/RUNTIME_OUTPUT_DIRECTORY.html

# 3. Use the expression builder to prohibit multi config from automatically appending subdirectory solutions
# https://stackoverflow.com/questions/7747857/in-cmake-how-do-i-work-around-the-debug-and-release-directories-visual-studio-2

set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.output/${QC_CPU_ARCH}/${CMAKE_BUILD_TYPE}/$<0:>"
        )

# Linux
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    get_target_property(QSC_BIN_OUTPUT_PATH ${PROJECT_NAME} RUNTIME_OUTPUT_DIRECTORY)
    set(QSC_DEPLOY_PATH ${QSC_BIN_OUTPUT_PATH})

    #    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    #            COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_CURRENT_SOURCE_DIR}/sndcpy/sndcpy.sh" "${QSC_BIN_OUTPUT_PATH}"
    #            COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_CURRENT_SOURCE_DIR}/sndcpy/sndcpy.apk" "${QSC_BIN_OUTPUT_PATH}"
    #            )

    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)

    target_link_libraries(${PROJECT_NAME} PRIVATE
            # qx11
            Qt${QT_VERSION_MAJOR}::X11Extras
            # xcb https://doc.qt.io/qt-5/linux-requirements.html
            xcb
            # pthread
            Threads::Threads
            )

    # linux set app icon: https://blog.csdn.net/MrNoboday/article/details/82870853
endif ()

#
# common deps
#

add_subdirectory(core)

# Qt
target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Network
        Qt${QT_VERSION_MAJOR}::Multimedia
        Qt${QT_VERSION_MAJOR}::Quick
        Qt${QT_VERSION_MAJOR}::Qml
        core
        )
