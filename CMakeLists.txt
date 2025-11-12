cmake_minimum_required(VERSION 3.5)

project(PowerSystem LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
endif()

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

set(CMAKE_AUTOUIC_SEARCH_PATHS
    "${CMAKE_CURRENT_SOURCE_DIR}/ui"
    "${CMAKE_CURRENT_SOURCE_DIR}/ui/login"
    "${CMAKE_CURRENT_SOURCE_DIR}/ui/homeMain"
    )

file(GLOB_RECURSE SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/homeMain/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/login/*.cpp
    )

file(GLOB_RECURSE UI_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui
    )

file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/homeMain/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/login/*.h
    )

file(GLOB RESOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/res/*.qrc)
qt5_add_resources(QRC_FILES ${RESOURCE_FILES})

list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/homeMain)
list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/login)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/homeMain)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/login)


add_executable(PowerSystem
    WIN32
    main.cpp
    ${QRC_FILES}
    ${SRC_FILES}
    ${HEADER_FILES}
    ${UI_FILES}
)

target_link_libraries(PowerSystem
    PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)

