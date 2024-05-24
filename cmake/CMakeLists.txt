# CMake的一个总入口，这个CMake设置一些全局的变

CMAKE_MINIMUM_REQUIRED(VERSION 2.8 ) #设定最小版本号
PROJECT(CG)                       #设定工程名

SET(PROJECT_ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../")

# SET(CMAKE_CXX_COMPILER "g++")         #设置编译器（可选的有gcc，g++）
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -pthread" ) # 设置编译选项, 允许c++11标准、O3优化、多线程。match选项可避免一些cpu上的问题

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcolor-diagnostics -fansi-escape-codes -Wall -g -Wno-deprecated")


set(CMAKE_BUILD_TYPE Release ) # 设置用debug还是release模式。debug允许断点，而release更快

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)  # 设定可执行二进制文件的目录

SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)  # 设定存放编译出来的库文件的目录

INCLUDE_DIRECTORIES(${PROJECT_ROOT_PATH}/dependencies/include)  # 设定头文件目录(告诉CMake头文件在哪里)
LINK_DIRECTORIES(${PROJECT_ROOT_PATH}/dependencies/library ${CMAKE_SOURCE_DIR}/lib) # 并且把该目录设为连接目录 (告诉CMake静态库在哪里)

find_package (Threads REQUIRED)

#增加子文件夹(注意我们的src路径是通过子文件夹的形式添加的，在这里面也是可以些CMakeLists.txt的)
ADD_SUBDIRECTORY(${CMAKE_SOURCE_DIR}/src) # 多目录，把 src 目录加进来，src 里面才是真正编译 main 和 tools 的
# 或者是 ADD_SUBDIRECTORY(src)