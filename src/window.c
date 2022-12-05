#include "window.h"

struct GLFWwindow* init_window(unsigned int width, unsigned int height, const char* title) 
{
    glfwInit();

    struct GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);

    glfwMakeContextCurrent(window);
    gladLoadGL();

    return window;
}

void window_close() 
{
    glfwTerminate();
}
