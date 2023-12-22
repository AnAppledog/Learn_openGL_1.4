#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define WIDTH 800       // 宽度
#define HEIGHT 600      // 高度

GLFWwindow* gl_init();  // 初始化函数
void processInput(GLFWwindow*);    // 处理输入的函数
