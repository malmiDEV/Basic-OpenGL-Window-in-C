#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "global.h"

#include <math.h>

static Render_Internal render = {0};

void render_init(void) 
{   
    global.render.width = 800;
    global.render.height = 600;
    
    init_shader();
    init_quad(&render.vao, &render.vbo, &render.ebo);
}

void draw_quad(void) 
{
    global.shader.proj = glms_mat4_identity();
    global.shader.proj = glms_perspective(glm_rad(global.camera.fov), global.render.width / global.render.height, 0.1f, 100.0f);

    glUniformMatrix4fv(glGetUniformLocation(global.shader.id, "projection"), 1, GL_FALSE, (const GLfloat *) &global.shader.proj.raw);

    vec3s cubes[] = {
        {{0.0f, 0.0f, 0.0f}},
        {{2.0f,  5.0f, -15.0f}}, 
        {{-1.5f, -2.2f, -2.5f}},  
        {{-3.8f, -2.0f, -12.3f}},  
        {{2.4f, -0.4f, -3.5f}},  
        {{-1.7f,  3.0f, -7.5f}},  
        {{1.3f, -2.0f, -2.5f}},  
        {{1.5f,  2.0f, -2.5f}}, 
        {{1.5f,  0.2f, -1.5f}}, 
        {{-1.3f,  1.0f, -1.5f}}
    };

    glBindVertexArray(render.vao);
    for (unsigned int i = 0; i < 10; i++) 
    {
        global.shader.model = glms_mat4_identity();
        global.shader.model = glms_translate(global.shader.model, cubes[i]);
        float angle = 20.0f * i;
        global.shader.model = glms_scale(global.shader.model, (vec3s){{1.0f, 1.0f, 1.0f}});
        global.shader.model = glms_rotate(global.shader.model, (float)glfwGetTime() * glm_rad(angle), (vec3s){{1.0f, 0.3f, 0.5f}});

        glUniformMatrix4fv(glGetUniformLocation(global.shader.id, "model"), 1, GL_FALSE, (const GLfloat *) &global.shader.model.raw);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    
    glBindVertexArray(0);
}

void render_begin(void)
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.00,0.1,0.1,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
