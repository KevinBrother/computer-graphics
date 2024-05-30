#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../src/utils/init-window.h"
#include "tools/gui.h"
#include <iostream>

using namespace std;

int main() {

  GLFWwindow *window;
  if (!initWindow(&window)) {
    return -1;
  }

  // 设置主要和次要版本
  const char *glsl_version = "#version 330";

  // -----------------------
  // 创建imgui上下文
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;
  // 设置样式
  ImGui::StyleColorsDark();
  // 设置平台和渲染器
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(glsl_version);

  // -----------------------

  float f = 0.0f;
  ImVec4 clear_color = ImVec4(0.21, 0.3, 0.21, 1.0);
  char buf[256] = "hello world";  // 使用256作为缓冲区大小，可以根据需求调整大小

  // render loop
  // 渲染循环， 不然绘制一个图形后，程序就退出了
  // -----------
  while (!glfwWindowShouldClose(window)) {
    // input
    // -----
    processInput(window);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("imgui");
    ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::InputText("string", buf, IM_ARRAYSIZE(buf));
    ImGui::SliderFloat("float", &f, 0.0f, 5.0f);
    ImGui::ColorEdit3("clear color3", (float *)&clear_color);
    ImGui::End();

    cout << "f = " << f << endl;

    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    // glBindVertexArray(0); // no need to unbind it every time

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved
    // etc.)
    // -------------------------------------------------------------------------------

    // 渲染 gui
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}
