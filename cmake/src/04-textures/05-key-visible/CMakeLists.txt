
set(TARGET_PATH src/04-textures/05-key-visible)
FILE(GLOB window ${PROJECT_ROOT_PATH}/${TARGET_PATH}/main.cpp)      #告诉CMake源文件在哪里？

# 将静态资源复制到构建目录
ADD_CUSTOM_TARGET(04-05-key-visible ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_ROOT_PATH}${TARGET_PATH}/resources ${EXECUTABLE_OUTPUT_PATH}/resources
)

# 添加可执行文件生成 (需要相关源文件)
ADD_EXECUTABLE(04-05-key-visible.exe
    ${window}
    ${PROJECT_ROOT_PATH}/glad.c
    ${PROJECT_ROOT_PATH}/src/utils/init-window.cpp
)

#自定义目标作为依赖项添加进去
ADD_DEPENDENCIES(04-05-key-visible.exe 04-05-key-visible)

# 链接依赖的库文件
target_link_libraries(04-05-key-visible.exe
    libglfw.3.4.dylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework CoreFoundation"
)
