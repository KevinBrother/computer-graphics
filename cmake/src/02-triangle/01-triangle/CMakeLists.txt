
FILE(GLOB window "${PROJECT_ROOT_PATH}/src/02-triangle/01-triangle/main.cpp")      #告诉CMake源文件在哪里？

# 添加可执行文件生成 (需要相关源文件)
ADD_EXECUTABLE(triangle.exe
    ${window}
    "${PROJECT_ROOT_PATH}/glad.c"
)                                          

# 链接依赖的库文件
target_link_libraries(triangle.exe
    libglfw.3.4.dylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework CoreFoundation"
)
