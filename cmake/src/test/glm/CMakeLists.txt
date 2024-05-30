FILE(GLOB window ${PROJECT_ROOT_PATH}/test/glm.cpp)

# 添加可执行文件生成 (需要相关源文件)
ADD_EXECUTABLE(test-glm.exe
        ${window}
)