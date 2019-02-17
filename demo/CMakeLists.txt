file(GLOB files "demo-*.cpp")
foreach(file ${files})
    get_filename_component(demo ${file} NAME_WE)
    
    add_executable(${demo}
                   ${file})

    target_link_libraries(${demo}
                          ${BWF_TARGET_NAME})
endforeach()

