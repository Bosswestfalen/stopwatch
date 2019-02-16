#
# MUST NOT COMPILE
#
file(GLOB files "dont-*.cpp")
foreach(file ${files})
    get_filename_component(testname ${file} NAME_WE)

    add_executable(${testname}
                  ${file})

    target_link_libraries(${testname}
                          ${BWF_TARGET_NAME})

    target_include_directories(${testname}
                               PUBLIC
                               ${CMAKE_SOURCE_DIR}/src)

    set_target_properties(${testname}
                          PROPERTIES EXCLUDE_FROM_ALL TRUE)

    add_test(NAME COMPILE-${testname}_${CMAKE_BUILD_TYPE}
             COMMAND ${CMAKE_MAKE_PROGRAM} ${testname}
             WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

    set_tests_properties(COMPILE-${testname}_${CMAKE_BUILD_TYPE}
                         PROPERTIES WILL_FAIL TRUE)
endforeach()

#
# MUST COMPILE
#
file(GLOB files "compile-*.cpp")
foreach(file ${files})
    get_filename_component(testname ${file} NAME_WE)

    add_executable(${testname}
                  ${file})

    target_link_libraries(${testname}
                          ${BWF_TARGET_NAME})

    target_include_directories(${testname}
                               PUBLIC
                               ${CMAKE_SOURCE_DIR}/src)

    set_target_properties(${testname}
                          PROPERTIES EXCLUDE_FROM_ALL TRUE)

    add_test(NAME COMPILE-${testname}_${CMAKE_BUILD_TYPE}
             COMMAND ${CMAKE_MAKE_PROGRAM} ${testname}
             WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endforeach()
