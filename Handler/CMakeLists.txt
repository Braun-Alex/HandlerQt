cmake_minimum_required(VERSION 3.5)
project(Handler VERSION 0.1 LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Xml Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Xml Test REQUIRED)
set(PROJECT_SOURCES
        main.cpp
        handler.h
        handler.cpp
        handler.ui
)
add_executable(Handler ${PROJECT_SOURCES})
target_link_libraries(Handler PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Xml Qt${QT_VERSION_MAJOR}::Test)
if(QT_VERSION_MAJOR EQUAL 6)
qt_finalize_executable(Handler)
endif()
