#include "shader.h"

unsigned int shader_propram(const char* vertexShaderSource, const char* fragmentShaderSource) {
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);   // 定义一个顶点着色器
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);    // 附加代码
    glCompileShader(vertexShader);                  // 编译

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);   // 定义一个顶点着色器
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);    // 附加代码
    glCompileShader(fragmentShader);                  // 编译

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    return program;
}