#version 330 core
out vec4 FragColor; // 指定一个片段着色器的输出变量名
in vec4 vertexColor; // 从顶点着色器传递过来的颜色(名称相同，类型相同)
void main()
{
   FragColor = vertexColor;
}