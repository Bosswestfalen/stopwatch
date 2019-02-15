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

if(BUILD_TESTING)
	enable_testing()
	add_subdirectory(test)
endif()

