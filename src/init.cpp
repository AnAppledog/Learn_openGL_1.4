#include "init.h"

GLFWwindow* gl_init() {
    glfwInit();     // 初始化
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // 设置版本为3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);        
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 选择为内核版本        

    GLFWwindow* mywindow = glfwCreateWindow(WIDTH, HEIGHT, "1.4.1", NULL, NULL);
    if (mywindow == NULL) {
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(mywindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        return NULL;
    } 
    return mywindow;
}

void processInput(GLFWwindow* mywindow) {
    if (glfwGetKey(mywindow, GLFW_KEY_ESCAPE) == GLFW_PRESS){   // 输入ESC退出窗口
        glfwSetWindowShouldClose(mywindow, true);
    }
    return;
}