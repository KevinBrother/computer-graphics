
FILE(GLOB window "${PROJECT_ROOT_PATH}/src/01-window/refactor/main.cpp")      #告诉CMake源文件在哪里？

# 添加可执行文件生成 (需要相关源文件)
ADD_EXECUTABLE(window-refactor.exe
    ${window}
    ${PROJECT_ROOT_PATH}/glad.c
    ${PROJECT_ROOT_PATH}/src/utils/init-window.cpp
)

# 链接依赖的库文件
target_link_libraries(window-refactor.exe
    libglfw.3.4.dylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework CoreFoundation"
)
