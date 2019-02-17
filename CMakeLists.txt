cmake_minimum_required(VERSION 3.12)

project("stopwatch"
        VERSION 0.0.1
        LANGUAGES CXX)


if(NOT "${CMAKE_BUILD_TYPE}")
    message(STATUS "Build type not specified -> changed to DEBUG")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BWF_TARGET_NAME ${PROJECT_NAME})

add_library(${BWF_TARGET_NAME} INTERFACE)

target_include_directories(${BWF_TARGET_NAME}
                           INTERFACE
                           $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>)

target_compile_features(${BWF_TARGET_NAME}
                        INTERFACE
                        cxx_std_17)

option(BUILD_DEMO
       "Build demo applications"
       ON)

option(BUILD_DOCS
       "Build doxygen documentation"
       ON)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()

if(BUILD_DEMO)
    add_subdirectory(demo)
endif()

if(BUILD_DOCS)
    find_package(Doxygen REQUIRED)

    set(DOXYGEN_FULL_PATH_NAMES "YES")
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/doc)
    set(DOXYGEN_STRIP_FROM_PATH ${CMAKE_SOURCE_DIR}/src)
    doxygen_add_docs(doc ${CMAKE_SOURCE_DIR}/src)
endif()
