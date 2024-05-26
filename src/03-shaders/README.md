# Shaders

1. 01-glsl
   - 主要功能为从顶点着色器向片段着色器发送数据
   - ```glsl
      // 顶点着色器输出数据
     out vec4 vertexColor;
  
      // 片段着色器从顶点着色器接收数据，需要名称相同，类型相同
     in vec4 vertexColor; 
     ```