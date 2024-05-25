FILE(GLOB EAO "${PROJECT_ROOT_PATH}/src/02-triangle/02-EAO/main.cpp")
FILE(GLOB drawArray "${PROJECT_ROOT_PATH}/src/02-triangle/03-drawArray/main.cpp")      #告诉CMake源文件在哪里？

ADD_EXECUTABLE(p-EAO.exe
        ${EAO}
        "${PROJECT_ROOT_PATH}/glad.c"
)

# 链接依赖的库文件
target_link_libraries(p-EAO.exe
        libglfw.3.4.dylib
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework CoreFoundation"
)

ADD_EXECUTABLE(p-drawArray.exe
    ${drawArray}
    "${PROJECT_ROOT_PATH}/glad.c"
)                                          

# 链接依赖的库文件
target_link_libraries(p-drawArray.exe
    libglfw.3.4.dylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework CoreFoundation"
)
