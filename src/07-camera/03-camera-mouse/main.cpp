#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "../../utils/imgui-utils.cpp"
#include "../../utils/init-window.h"
#include "../../utils/texture-utils.h"
#include "shader_s.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

void processInput(GLFWwindow **window, glm::vec3 *cameraPosP, glm::vec3 *cameraFrontP, glm::vec3 *cameraUpP, float *cameraSpeed) {
  if (glfwGetKey(*window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(*window, true);

  if (glfwGetKey(*window, GLFW_KEY_W) == GLFW_PRESS)
    *cameraPosP += *cameraSpeed * *cameraFrontP;
  if (glfwGetKey(*window, GLFW_KEY_S) == GLFW_PRESS)
    *cameraPosP -= *cameraSpeed * *cameraFrontP;
  if (glfwGetKey(*window, GLFW_KEY_A) == GLFW_PRESS)
    *cameraPosP -= glm::normalize(glm::cross(*cameraFrontP, *cameraUpP)) * *cameraSpeed;
  if (glfwGetKey(*window, GLFW_KEY_D) == GLFW_PRESS)
    *cameraPosP += glm::normalize(glm::cross(*cameraFrontP, *cameraUpP)) * *cameraSpeed;
}

bool firstMouse = true;
float yaw = -90.0f;// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
float fov = 45.0f;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
float cameraSpeed = 0.05f;

int main() {
  GLFWwindow *window;
  if (!initWindow(&window)) {
    return -1;
  }

  ImGuiUtils::init(&window);
  glEnable(GL_DEPTH_TEST);// enable depth testing
  glfwSetCursorPosCallback(window, mouse_callback);
  glfwSetScrollCallback(window, scroll_callback);

  // tell GLFW to capture our mouse
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  // build and compile our shader program
  // ------------------------------------
  Shader ourShader("./resources/shader.vs.glsl", "./resources/shader.fs.glsl");// you can name your shader files however you like

  // set up vertex data (and buffer(s)) and configure vertex attributes
  // ------------------------------------------------------------------

  float vertices[] = {
          -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
          0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
          0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
          0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
          -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
          -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

          -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
          0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
          0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
          0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
          -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
          -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

          -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
          -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
          -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
          -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
          -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
          -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

          0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
          0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
          0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
          0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
          0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
          0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

          -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
          0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
          0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
          0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
          -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
          -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

          -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
          0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
          0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
          0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
          -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
          -0.5f, 0.5f, -0.5f, 0.0f, 1.0f};

  glm::vec3 cubePositions[] = {
          glm::vec3(0.0f, 0.0f, 0.0f),
          glm::vec3(2.0f, 5.0f, -15.0f),
          glm::vec3(-1.5f, -2.2f, -2.5f),
          glm::vec3(-3.8f, -2.0f, -12.3f),
          glm::vec3(2.4f, -0.4f, -3.5f),
          glm::vec3(-1.7f, 3.0f, -7.5f),
          glm::vec3(1.3f, -2.0f, -2.5f),
          glm::vec3(1.5f, 2.0f, -2.5f),
          glm::vec3(1.5f, 0.2f, -1.5f),
          glm::vec3(-1.3f, 1.0f, -1.5f)};

  // 生成纹理
  stbi_set_flip_vertically_on_load(true);// tell stb_image.h to flip loaded texture's on the y-axis.
  unsigned int texture = loadTexture("./resources/container.jpg");
  unsigned int texture2 = loadTexture("./resources/awesomeFace.png");

  unsigned int VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // 位置属性
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
  glEnableVertexAttribArray(0);

  // 纹理坐标属性
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  ourShader.use();
  ourShader.setInt("texture1", 0);// 这儿的 name 需要 和 fs 中的 一致
  ourShader.setInt("texture2", 1);


  // 投影矩阵
  glm::mat4 projection = glm::perspective(glm::radians(fov), (float) 800 / (float) 600, 0.1f, 100.0f);
  ourShader.setMat4("projection", projection);
  // render loop
  // -----------
  while (!glfwWindowShouldClose(window)) {
    // input
    processInput(&window, &cameraPos, &cameraFront, &cameraUp, &cameraSpeed);

    ImGuiUtils::newFrame();

    ImGui::Begin("imgui");
    ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::SliderFloat("float", &cameraSpeed, 0.0f, 5.0f);
    //    ImGui::SetNextWindowSize(ImVec2(200, 100));
    //    ImGui::SetNextItemWidth(400);

    if (ImGui::Button("W")) {
      cameraPos += cameraSpeed * cameraFront;
    }
    if (ImGui::Button("S")) {
      cameraPos -= cameraSpeed * cameraFront;
    }
    if (ImGui::Button("A")) {
      cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }
    if (ImGui::Button("D")) {
      cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }

    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);

    ourShader.use();
    // 观察矩阵
    glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    ourShader.setMat4("view", view);

    glm::mat4 projection = glm::perspective(glm::radians(fov), (float) 800 / (float) 600, 0.1f, 100.0f);
    ourShader.setMat4("projection", projection);

    glBindVertexArray(VAO);

    for (unsigned int i = 0; i < 10; i++) {
      glm::mat4 model = glm::mat4(1.0f);
      model = glm::translate(model, cubePositions[i]);
      float angle = 20.0f * i;
      model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
      ourShader.setMat4("model", model);

      glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    ImGuiUtils::render();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // optional: de-allocate all resources once they've outlived their purpose:
  // ------------------------------------------------------------------------
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);

  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow *window, double xposIn, double yposIn) {
  float xpos = static_cast<float>(xposIn);
  float ypos = static_cast<float>(yposIn);

  if (firstMouse) {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }

  float xoffset = xpos - lastX;
  float yoffset = lastY - ypos;// reversed since y-coordinates go from bottom to top
  lastX = xpos;
  lastY = ypos;

  float sensitivity = 0.1f;// change this value to your liking
  xoffset *= sensitivity;
  yoffset *= sensitivity;

  yaw += xoffset;
  pitch += yoffset;

  // make sure that when pitch is out of bounds, screen doesn't get flipped
  if (pitch > 89.0f)
    pitch = 89.0f;
  if (pitch < -89.0f)
    pitch = -89.0f;

  glm::vec3 front;
  front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  front.y = sin(glm::radians(pitch));
  front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  cameraFront = glm::normalize(front);
}


// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
  std::cout << "scroll_callback: " << xoffset << ", " << yoffset << std::endl;
  if (fov >= 1.0f && fov <= 45.0f)
    fov -= yoffset;
  if (fov <= 1.0f)
    fov = 1.0f;
  if (fov >= 45.0f)
    fov = 45.0f;

  std::cout << "fov: " << fov <<  std::endl;
}