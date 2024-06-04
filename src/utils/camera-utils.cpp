#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class CameraUtils {
  double *lastX;
  double *lastY;
  bool firstMouse = true;
  float yaw;
  float pitch;
  glm::vec3 *cameraFront;

  public:
  CameraUtils(GLFWwindow *window, double *lastX, double *lastY, glm::vec3 *cameraFront) {
    this->lastX = lastX;
    this->lastY = lastY;
    this->cameraFront = cameraFront;
  }

  void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
    if (firstMouse) {
      *lastX = xpos;
      *lastY = ypos;
      firstMouse = false;
    }

    float xoffset = xpos - *lastX;
    float yoffset = *lastY - ypos;
    *lastX = xpos;
    *lastY = ypos;

    float sensitivity = 0.05;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
      pitch = 89.0f;
    if (pitch < -89.0f)
      pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    *cameraFront = glm::normalize(front);
  }
};