set(TARGET_PATH src/12-lighting-maps/01-lighting-maps)
FILE(GLOB window ${PROJECT_ROOT_PATH}/${TARGET_PATH}/main.cpp)      #告诉CMake源文件在哪里？

# 将静态资源复制到构建目录
ADD_CUSTOM_TARGET(12-01-lighting-maps ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_ROOT_PATH}${TARGET_PATH}/resources ${EXECUTABLE_OUTPUT_PATH}/resources
)

# 添加可执行文件生成 (需要相关源文件)
ADD_EXECUTABLE(12-01-lighting-maps.exe
        ${window}
        ${PROJECT_ROOT_PATH}/glad.c
        ${PROJECT_ROOT_PATH}/src/utils/init-window.cpp
        ${PROJECT_ROOT_PATH}/dependencies/include/imgui/imgui_impl_glfw.cpp
        ${PROJECT_ROOT_PATH}/dependencies/include/imgui/imgui_impl_opengl3.cpp
        ${PROJECT_ROOT_PATH}/dependencies/include/imgui/imgui.cpp
        ${PROJECT_ROOT_PATH}/dependencies/include/imgui/imgui_draw.cpp
        ${PROJECT_ROOT_PATH}/dependencies/include/imgui/imgui_widgets.cpp
)

#自定义目标作为依赖项添加进去
ADD_DEPENDENCIES(12-01-lighting-maps.exe 12-01-lighting-maps)

# 链接依赖的库文件
target_link_libraries(12-01-lighting-maps.exe
        libglfw.3.4.dylib
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework CoreFoundation"
)
