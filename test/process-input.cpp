#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "../src/utils/init-window.h"

int main() {
  GLFWwindow *window;
  if (!initWindow(&window)) {
    return -1;
  }

  while (!glfwWindowShouldClose(window)) {

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
      std::cout << "Space key pressed" << std::endl;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
      std::cout << "Up key pressed" << std::endl;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
      std::cout << "W key pressed" << std::endl;

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}