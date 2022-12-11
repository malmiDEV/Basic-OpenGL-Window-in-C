#ifndef CAMERA_H
#define CAMERA_H

#include "global.h"
#include "cglm/struct.h"

#include <stdbool.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

typedef struct 
{
    vec3s camera_pos;
    vec3s camera_front;
    vec3s camera_up;
    
    float fov;
    float delta;
    float last;
    float lastX;
    float lastY;
    float yaw;
    float pitch;
    float sensitivity;
    bool first_mouse;
} Camera;

Camera camera_set(void);

void camera_init(GLFWwindow *window);
void camera_move(GLFWwindow *window);

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void process_mouse(GLFWwindow *window, double xpos_in, double ypos_in);
void process_input(GLFWwindow *window);

#endif