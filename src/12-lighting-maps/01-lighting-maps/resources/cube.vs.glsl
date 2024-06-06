#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal; // 法向量
layout (location = 2) in vec2 aTexCoords; // 纹理坐标

out vec3 Normal; // 法向量输出
out vec3 FragPos; // 片段位置输出
out vec2 TexCoords; // 纹理坐标输出

uniform mat4 model; // 模型矩阵
uniform mat4 view; // 视图矩阵
uniform mat4 projection; // 投影矩阵

void main()
{
  FragPos = vec3(model * vec4(aPos, 1.0)); // 片段位置输出
  Normal = aNormal; // 法向量输出
  TexCoords = aTexCoords; // 纹理坐标输出
  gl_Position = projection * view * model * vec4(aPos, 1.0); // 对顶点位置进行变换
}