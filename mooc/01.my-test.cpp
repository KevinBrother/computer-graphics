#include "../dependencies/include/glad/glad.h"
#include "../dependencies/include/GLFW/glfw3.h"
#include <iostream>
using namespace std;

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
int screen_width = 1280;
int screen_height = 720;
int main()
{
  // 通过glfwInit 初始化GLFW,
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // 创建一个窗口对象 start, 这个窗口对象村发了所有和窗口相关的数据，且会被GLFW的其他函数频繁的用到
  GLFWwindow *window = glfwCreateWindow(800, 600, "my-window", NULL, NULL);
  // auto window = glfwCreateWindow(screen_width, screen_height, "window", nullptr, nullptr);

  if (window == NULL)
  {
    cout << "Failed to create GLFW window" << endl;
    glfwTerminate();
    return -1;
  }
  // 创建一个窗口对象 end
  // 通知GLFW将window上下文，设置为当前线程的主上下文
  glfwMakeContextCurrent(window);

  // 在调用任何OpenGL的函数之前需要初始化GLAD start
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    cout << "Failed to create GLAD" << endl;

    return -1;
  }
  // 在调用任何OpenGL的函数之前需要初始化GLAD end

  glViewport(0, 0, screen_width, screen_height);

  // 注册调整窗口大小的函数
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // 渲染

  while (!glfwWindowShouldClose(window))
  {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
// 定义一个可以可以修改用户视口大小的函数
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
}