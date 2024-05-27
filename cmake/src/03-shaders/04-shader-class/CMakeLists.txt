
FILE(GLOB window "${PROJECT_ROOT_PATH}/src/03-shaders/04-shader-class/main.cpp")      #告诉CMake源文件在哪里？

# 将静态资源复制到构建目录
ADD_CUSTOM_TARGET(CopyResources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_ROOT_PATH}/src/03-shaders/04-shader-class/resources ${EXECUTABLE_OUTPUT_PATH}/resources
)

# 添加可执行文件生成 (需要相关源文件)
ADD_EXECUTABLE(shader-class.exe
    ${window}
#    ${PROJECT_ROOT_PATH}/src/03-shaders/04-shader-class/shader_s.h
    ${PROJECT_ROOT_PATH}/glad.c
)

#自定义目标作为依赖项添加进去
ADD_DEPENDENCIES(shader-class.exe CopyResources)

# 链接依赖的库文件
target_link_libraries(shader-class.exe
    libglfw.3.4.dylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework CoreFoundation"
)
