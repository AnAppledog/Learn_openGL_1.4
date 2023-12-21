#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "init.h"
#include "shader.h"

float vertexs[] {           // 记录六个顶点 分别对应两个三角形
    -0.5f,  0.5f, 0.0f,     // 第一个
     0.5f,  0.5f, 0.0f,  
     0.0f,  0.0f, 0.0f,
     0.0f,  0.0f, 0.0f,
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f 
};

const char* vertexShaderSource =    // 顶点着色器源码
"#version 330 core \n"
"layout (location = 0) in vec3 aPos; \n"
"void main() { \n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); \n"
"} \0";

const char* fragmentShaderSource1 =  //第一个片段着色器源码
"#version 330 core \n"
"out vec4 FragColor; \n"
"void main() { \n"
"   FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f); \n"
"} \0";

const char* fragmentShaderSource2 =  //第二个片段着色器源码
"#version 330 core \n"
"out vec4 FragColor; \n"
"void main() { \n"
"   FragColor = vec4(0.0f, 0.0f, 1.0f, 1.0f); \n"
"} \0";

int main() {
    GLFWwindow* mywindow;
    if ((mywindow = gl_init()) == NULL) { // 初始化  若失败则输出错误信息并返回
        std::cout << "Failed to init a window" << std::endl;
        return -1;
    }

    glViewport(0, 0, WIDTH, HEIGHT);        // 设置一个视口

    unsigned int VAO[2];
    glGenVertexArrays(2, VAO);
    unsigned int VBO[2];
    glGenBuffers(2, VBO);

    // VAO[0] 和 VBO[0] 用于绘制第一个三角形
    glBindVertexArray(VAO[0]);                 
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);     

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexs), vertexs, GL_STATIC_DRAW);        // 传输数据
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);  // 设置顶点属性
    glEnableVertexAttribArray(0);               //启用第0号顶点属性

    // VAO[1] 和 VBO[1] 用于绘制第二个三角形
    glBindVertexArray(VAO[1]);                 //绑定VAO[1]
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);     // 绑定VBO[1]

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexs), vertexs, GL_STATIC_DRAW);        // 传输数据
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);  // 设置顶点属性
    glEnableVertexAttribArray(0);               //启用第0号顶点属性

    
    unsigned int ShaderPropram1 = shader_propram(vertexShaderSource, fragmentShaderSource1);              //创建第一个着色器程序（绿色）
    unsigned int ShaderPropram2 = shader_propram(vertexShaderSource, fragmentShaderSource2);              //创建第二个着色器程序（蓝色）
    
    while(!glfwWindowShouldClose(mywindow)) {   // 渲染循环
        processInput(mywindow);

        glClearColor(1.0f, 0.75f, 0.79f, 1.0f); // 设置清屏颜色
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(ShaderPropram1);            // 使用该着色器程序
        glBindVertexArray(VAO[0]);              // 使用该VAO绑定的顶点属性与VBO
        glDrawArrays(GL_TRIANGLES, 0, 3);       // 从第一个点到第三个点绘制第一个三角形
        glUseProgram(ShaderPropram2);
        glBindVertexArray(VAO[1]);
        glDrawArrays(GL_TRIANGLES, 3, 3);       // 从第三个点到第六个点绘制第二个三角形

        glfwSwapBuffers(mywindow);
        glfwPollEvents();
    }

    glDeleteBuffers(2, VBO);
    glDeleteVertexArrays(2, VAO);
    glfwTerminate();

    return 0;
}
