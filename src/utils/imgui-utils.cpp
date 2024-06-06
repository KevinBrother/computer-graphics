#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "tools/gui.h"
#include <iostream>

namespace ImGuiUtils {
  static void init(GLFWwindow **window) {
    // 设置主要和次要版本
    const char *glsl_version = "#version 330";

    // -----------------------
    // 创建imgui上下文
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;
    // 设置样式
    ImGui::StyleColorsDark();
    // 设置平台和渲染器
    ImGui_ImplGlfw_InitForOpenGL(*window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    // 支持中文输入
    io.Fonts->AddFontFromFileTTF("/System/Library/Fonts/Apple Braille Outline 6 Dot.ttf", 16.0f);
    // 设置默认字体
    io.FontDefault = io.Fonts->AddFontFromFileTTF("/Library/Fonts/Arial Unicode.ttf", 16.0f);
  }

  static void newFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
  }

  static void render() {
    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }
}// namespace ImGuiUtils