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

install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/
        DESTINATION include)

option(BUILD_TESTS
       "Build tests"
       ON)

option(BUILD_DEMOS
       "Build demo applications"
       OFF)

option(BUILD_DOCS
       "Build doxygen documentation"
       OFF)

option(BUILD_CODEANALYSIS
       "Use clang-tidy to analyse code"
       OFF)


if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()


if(BUILD_DEMOS)
    add_subdirectory(demo)
endif()


if(BUILD_DOCS)
    find_package(Doxygen REQUIRED)

    set(DOXYGEN_FULL_PATH_NAMES "YES")
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/docs)
    set(DOXYGEN_STRIP_FROM_PATH ${CMAKE_SOURCE_DIR}/src)
    doxygen_add_docs(doc ${CMAKE_SOURCE_DIR}/src)
endif()

if(BUILD_CODEANALYSIS)
    find_program(CLANG_TIDY clang-tidy)
    if(${CLANG_TIDY} STREQUAL "CLANG_TIDY-NOTFOUND")
        message(FATAL_ERROR "Code analysis enabled, but clang-tidy not available!")
    endif()

    add_custom_target(codeanalysis
                      COMMAND clang-tidy
                      -checks=*,-google-readability-namespace-comments,-llvm-header-guard,-llvm-namespace-comment,-fuchsia-trailing-return
                      ${CMAKE_SOURCE_DIR}/src/bosswestfalen/stopwatch.hpp
                      -extra-arg=-std=c++17)
endif()

