
set(TARGET_PATH src/03-shaders/07-cmake-logo)
FILE(GLOB window "${PROJECT_ROOT_PATH}/${TARGET_PATH}/main.cpp")      #告诉CMake源文件在哪里？

# 将静态资源复制到构建目录
ADD_CUSTOM_TARGET(cmake-logo ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_ROOT_PATH}${TARGET_PATH}/resources ${EXECUTABLE_OUTPUT_PATH}/resources
)

# 添加可执行文件生成 (需要相关源文件)
ADD_EXECUTABLE(cmake-logo.exe
    ${window}
    ${PROJECT_ROOT_PATH}/glad.c
)

#自定义目标作为依赖项添加进去
ADD_DEPENDENCIES(cmake-logo.exe cmake-logo)

# 链接依赖的库文件
target_link_libraries(cmake-logo.exe
    libglfw.3.4.dylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework CoreFoundation"
)
