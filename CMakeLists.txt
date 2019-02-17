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

add_library(${BWF_TARGET_NAME}
            INTERFACE)

target_include_directories(${BWF_TARGET_NAME}
                           INTERFACE
                           $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>)

target_compile_features(${BWF_TARGET_NAME}
                        INTERFACE
                        cxx_std_17)

option(BUILD_DEMO
       "Build demo applications"
       ON)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()

if(BUILD_DEMO)
    add_subdirectory(demo)
endif()

