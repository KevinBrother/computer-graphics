
FILE(GLOB glad "${PROJECT_ROOT_PATH}/glad.c")      #告诉CMake源文件在哪里？
ADD_LIBRARY(glad STATIC ${glad})                       #告诉CMake生成的是一个静态库
