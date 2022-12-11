#include "global.h"

void camera_init(GLFWwindow *window) 
{
    global.camera = camera_set();

    glfwSetCursorPosCallback(window,  process_mouse);
    glfwSetScrollCallback(window, scroll_callback);
}

Camera camera_set(void) 
{
    Camera camera = {
        .camera_pos = {{0.0f, 0.0f, 3.0f}},
        .camera_front = {{0.0f, 0.0f, -1.0f}},
        .camera_up = {{0.0f, 1.0f, 0.0f}},  
        .delta = 0.0f,
        .last = 0.0f,
        .first_mouse = true,  
        .lastX = 400.0f,
        .lastY = 300.0f,
        .sensitivity = 0.1f,
        .yaw = -90.0f,
        .pitch = 0.0f,
        .fov = 90.0f,
    };

    return camera;
}

void camera_move(GLFWwindow *window) 
{
    process_input(window);

    global.shader.view = glms_lookat(global.camera.camera_pos, glms_vec3_add(global.camera.camera_pos, global.camera.camera_front), global.camera.camera_up);         
    glUniformMatrix4fv(glGetUniformLocation(global.shader.id, "view"), 1, GL_FALSE, (const GLfloat *) &global.shader.view.raw);

}

void process_input(GLFWwindow *window) 
{
    float cur_frame = (float)glfwGetTime();
    global.camera.delta = cur_frame - global.camera.last;
    global.camera.last = cur_frame;

    float speed = 10.0f * global.camera.delta;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        global.camera.camera_pos = glms_vec3_add(glms_vec3_scale(global.camera.camera_front, speed), global.camera.camera_pos);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        global.camera.camera_pos = glms_vec3_add(glms_vec3_scale(glms_vec3_negate(global.camera.camera_front), speed), global.camera.camera_pos);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        global.camera.camera_pos = glms_vec3_add(glms_vec3_scale(glms_vec3_negate(glms_vec3_normalize(glms_vec3_cross(global.camera.camera_front, global.camera.camera_up))), speed), global.camera.camera_pos);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        global.camera.camera_pos = glms_vec3_add(glms_vec3_scale(glms_vec3_normalize(glms_vec3_cross(global.camera.camera_front, global.camera.camera_up)), speed), global.camera.camera_pos);
        
    printf("vec3(%f, %f, %f)\n", global.camera.camera_pos.x, global.camera.camera_pos.y, global.camera.camera_pos.z);
}

void process_mouse(GLFWwindow *window, double xpos_in, double ypos_in) 
{
    float xpos = (float)xpos_in;
    float ypos = (float)ypos_in;

    if (global.camera.first_mouse)
    {
        global.camera.lastX = xpos;
        global.camera.lastY = ypos;
        global.camera.first_mouse = false;
    }

    float xOffset = xpos - global.camera.lastX;
    float yOffset = global.camera.lastY - ypos;
    global.camera.lastX = xpos;
    global.camera.lastY = ypos;

    global.camera.yaw += xOffset * 0.1;
    global.camera.pitch += yOffset * 0.1;

    if (global.camera.pitch > 89.0f)
        global.camera.pitch = 89.0f;
    if (global.camera.pitch < -89.0f)
        global.camera.pitch = -89.0f;

    vec3s front = {
        .x = cos(glm_rad(global.camera.yaw)) * cos(glm_rad(global.camera.pitch)),
        .y = sin(glm_rad(global.camera.pitch)),
        .z = sin(glm_rad(global.camera.yaw)) * cos(glm_rad(global.camera.pitch))
    };
    global.camera.camera_front = glms_vec3_normalize(front);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    global.camera.fov -= (float)yoffset;
    if (global.camera.fov < 1.0f)
        global.camera.fov = 1.0f;
    if (global.camera.fov > 90.0f)
        global.camera.fov = 90.0f;
}