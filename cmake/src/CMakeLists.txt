message(STATUS "src start")

ADD_SUBDIRECTORY(01-main)
# ADD_SUBDIRECTORY(glad) # CMakeLists 管理 glad

message(STATUS "src 01-main end")
# 添加可执行文件生成 (需要相关源文件)
ADD_EXECUTABLE(main1.exe
    01-main
    # glad # CMakeLists 管理 glad
    "${PROJECT_ROOT_PATH}/glad.c" # 也可以改为 CMakeLists 管理 glad.c 的方式
)                                          

# 链接依赖的库文件
target_link_libraries(main1.exe 
    main1
    # glad # CMakeLists 管理 glad
    libglfw.3.4.dylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework CoreFoundation"
)

message(STATUS "src end")