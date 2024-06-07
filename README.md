# OpenGL study

## mac 初始化

1. 安装 homebrew
2. 安装 glfw

```
brew install glfw
```

3. 安装 glad

```
brew install glad
```

## 配置

1. 已经配置好vscode的task，通过command + shift + b快捷键生成app可执行文件,
    再运行

    ``` bash
     ./app 
    ```

## document

[OpenGL setup: GLFW and GLAD in Visual Studio Code on macOS](https://www.youtube.com/watch?v=7-dL6a5_B3I)
[learn opengl](https://learnopengl.com/Introduction)
[docs.GL](https://docs.gl/gl3/glPolygonMode)

## 问题

1. GLFW 是什么

    - Graphics Library Framework（图形库框架）
    - GLFW 是一款跨平台的开源库，用于创建窗口，接收和处理输入，管理 OpenGL 内容，并提供对多种平台的支持。
    - GLFW 的主要功能是创建并管理窗口和 OpenGL 上下文，同时还提供了处理手柄、键盘、鼠标输入的功能。

2. GLAD 是什么 [在线服务](https://glad.dav1d.de/)
    - GLAD - Multi-Language GL/GLES/EGL/GLX/WGL Loader-Generator
    - GLAD是继GL3W，GLEW之后，当前最新的用来访问OpenGL规范接口的第三方库
    - GLAD 是 OpenGL 加载器自动生成器，它能够根据 OpenGL 版本和平台自动生成函数指针。
    - 它支持多种编程语言，包括C/C++、Python、Rust等，使开发者能够方便地访问和使用OpenGL的功能。
    - GLAD的主要目标是简化OpenGL的初始化过程，使得开发者能够更快速、高效地开始使用OpenGL进行图形编程。


## 待解决问题
[ ] 如何在vscode中运行、调试OpenGL程序
[ ] 10-02-cube-rotating 中，如何物体自转时，光线效果能正常显示
[ ] imgui 的中文乱码问题。
[ ] emission-map 的动画效果无法正常显示。