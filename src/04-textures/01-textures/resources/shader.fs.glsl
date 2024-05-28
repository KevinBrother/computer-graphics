#version 330 core
out vec4 FragColor; // 指定一个片段着色器的输出变量名
in vec3 vertexColor; // 从顶点着色器传递过来的颜色(名称相同，类型相同)
in vec2 texCoord;

uniform sampler2D ourTexture; // 声明一个采样器，名称为ourTexture

void main()
{
//  FragColor = texture(ourTexture, texCoord);
   FragColor = texture(ourTexture, texCoord) * vec4(vertexColor, 1.0);
}