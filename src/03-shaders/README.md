# Shaders

1. 01-glsl
   - 主要功能为从顶点着色器向片段着色器发送数据
   - ```glsl
      // 顶点着色器输出数据
     out vec4 vertexColor;
  
      // 片段着色器从顶点着色器接收数据，需要名称相同，类型相同
     in vec4 vertexColor; 
     ```

2. 02-uniforms
  - Uniform是另一种从我们的应用程序在 CPU 上传递数据到 GPU 上的着色器的方式
  - uniform是全局的(Global) 意味着uniform变量必须在每个着色器程序对象中都是独一无二的
  - 它可以被着色器程序的任意着色器在任意阶段访问
     