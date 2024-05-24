message(STATUS "01-main start")

FILE(GLOB main1 "${PROJECT_ROOT_PATH}/src/01-main/*.cpp")      #告诉CMake源文件在哪里？
ADD_LIBRARY(main1 STATIC ${main1})                       #告诉CMake生成的是一个静态库

message(STATUS "01-main end")