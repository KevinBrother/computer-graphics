
FILE(GLOB window "${PROJECT_ROOT_PATH}/test/use-imgui-utils.cpp")      #告诉CMake源文件在哪里？

# 添加可执行文件生成 (需要相关源文件)
ADD_EXECUTABLE(test-use-imgui-utils.exe
    ${window}
    ${PROJECT_ROOT_PATH}/glad.c
    ${PROJECT_ROOT_PATH}/src/utils/init-window.cpp
    ${PROJECT_ROOT_PATH}/dependencies/include/imgui/imgui_impl_glfw.cpp
    ${PROJECT_ROOT_PATH}/dependencies/include/imgui/imgui_impl_opengl3.cpp
    ${PROJECT_ROOT_PATH}/dependencies/include/imgui/imgui.cpp
    ${PROJECT_ROOT_PATH}/dependencies/include/imgui/imgui_draw.cpp
    ${PROJECT_ROOT_PATH}/dependencies/include/imgui/imgui_widgets.cpp
)

# 链接依赖的库文件
target_link_libraries(test-use-imgui-utils.exe
    libglfw.3.4.dylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework CoreFoundation"
)
