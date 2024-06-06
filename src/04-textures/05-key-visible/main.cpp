#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#define visibility visibility
#include "../../utils/init-window.h"
#include "../../utils/texture-utils.h"
#include "shader_s.h"

float mixValue = 0.2f;

void processUpOrDown(GLFWwindow *window, Shader &ourShader) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);

  if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
    mixValue += 0.001f;
    if (mixValue >= 1.0f)
      mixValue = 1.0f;
  }

  if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
    mixValue -= 0.001f;
    if (mixValue <= 0.0f)
      mixValue = 0.0f;
  }
}

int main() {
  GLFWwindow *window;
  if (!initWindow(&window)) {
    return -1;
  }

  // build and compile our shader program
  // ------------------------------------
  Shader ourShader("./resources/shader.vs.glsl", "./resources/shader.fs.glsl");// you can name your shader files however you like

  // set up vertex data (and buffer(s)) and configure vertex attributes
  // ------------------------------------------------------------------
  float vertices[] = {
          //     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
          0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
          0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
          -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
          -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
  };

  unsigned int indices[] = {
          0, 1, 3,// first triangle
          1, 2, 3 // second triangle
  };

  stbi_set_flip_vertically_on_load(true);// tell stb_image.h to flip loaded texture's on the y-axis.

  unsigned int texture = loadTexture("./resources/container.jpg");
  unsigned int texture2 = loadTexture("./resources/awesomeFace.png");

  unsigned int VBO, VAO, EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  // 位置属性
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
  glEnableVertexAttribArray(0);

  // 颜色属性
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  // 纹理坐标属性
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float)));
  glEnableVertexAttribArray(2);


  ourShader.use();
  ourShader.setInt("texture1", 0);// 这儿的 name 需要 和 fs 中的 一致
  ourShader.setInt("texture2", 1);
  ourShader.setFloat("visibility", mixValue);

  // render loop
  // -----------
  while (!glfwWindowShouldClose(window)) {
    // input
    // -----
//    processInput(window);
    processUpOrDown(window, ourShader);

    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ourShader.setFloat("visibility", mixValue);

    ourShader.use();

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // optional: de-allocate all resources once they've outlived their purpose:
  // ------------------------------------------------------------------------
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);

  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}
