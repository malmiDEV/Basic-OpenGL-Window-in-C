#ifndef WINDOW_H
#define WINDOW_H

#include "gfx.h"

struct GLFWwindow* init_window(unsigned int width, unsigned int height, const char* title);
void window_close();

#endif