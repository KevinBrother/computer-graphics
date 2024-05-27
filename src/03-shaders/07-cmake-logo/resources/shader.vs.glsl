#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 vertexColor; // 为片段着色器指定一个颜色输出
void main()
{
  gl_Position = vec4(aPos, 1.0); // 把 一个 vec3 作为 vec4 的构造器的参数
  vertexColor = aColor;
}