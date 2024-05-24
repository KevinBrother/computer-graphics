message(STATUS "src start")

ADD_SUBDIRECTORY(01-main)

message(STATUS "src 01-main end")
# 添加可执行文件生成 (需要相关源文件)
ADD_EXECUTABLE(main1.exe
    01-main
    "${PROJECT_ROOT_PATH}/glad.c"
)                                          

# 链接依赖的库文件
target_link_libraries(main1.exe 
    main1
    libglfw.3.4.dylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework CoreFoundation"
)

message(STATUS "src end")