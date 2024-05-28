#version 330 core
out vec4 FragColor; // 指定一个片段着色器的输出变量名
in vec3 vertexColor; // 从顶点着色器传递过来的颜色(名称相同，类型相同)
in vec2 texCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
void main()
{
//  FragColor = texture(texture2, texCoord);
  // 0.2会返回80%的第一个输入颜色和20%的第二个输入颜色，即返回两个纹理的混合色。 0 返回第一个输入颜色，1 返回第二个输入颜色。
   FragColor = mix(texture(texture1, texCoord), texture(texture2,  vec2(1.0-texCoord.x, texCoord.y)), 0.2);
}