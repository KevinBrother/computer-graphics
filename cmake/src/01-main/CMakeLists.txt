message(STATUS "01-main This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "01-main This is SOURCE dir " ${PROJECT_SOURCE_DIR})

FILE(GLOB main1 "${PROJECT_ROOT_PATH}/src/01-main/*.cpp")      #告诉CMake源文件在哪里？

# 添加可执行文件生成
ADD_EXECUTABLE(main1
    ${main1}
    "${PROJECT_ROOT_PATH}/glad.c"
)                                          #告诉CMake生成一个main可执行文件

# 链接依赖的库文件
target_link_libraries(main1 
    libglfw.3.4.dylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework CoreFoundation"
)