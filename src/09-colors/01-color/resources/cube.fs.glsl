#version 330 core
out vec4 FragColor; // 指定一个片段着色器的输出变量名
in vec2 texCoord;

uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{
   FragColor = vec4(lightColor * objectColor, 1.0);
}