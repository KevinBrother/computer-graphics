#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
out vec2 texCoord; // 为片段着色器指定一个纹理坐标输出

uniform mat4 transform;

void main()
{
  gl_Position = transform * vec4(aPos, 1.0); // 对顶点位置进行变换
  texCoord = aTexCoord;
}