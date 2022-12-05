#include "render.h"
#include "global.h"

struct Render render = {0};

void render_init(void) {
    load_shader(&render);
    init_quad(&render.vao, &render.vbo, &render.ebo);
}

void draw_quad(void) {
    glUseProgram(global.shader.id);

    glBindVertexArray(render.vao);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

void init_quad(unsigned int *vao, unsigned int *vbo, unsigned int *ebo) {
    float vertices[] = {
        0.5f,  0.5f, 0.0f, 
        0.5f, -0.5f, 0.0f,  
        -0.5f, -0.5f, 0.0f,  
        -0.5f,  0.5f, 0.0f   
    };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    glGenVertexArrays(1, vao);
    glGenBuffers(1, vbo);
    glGenBuffers(1, ebo);

    glBindVertexArray(*vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER,  sizeof(vertices), vertices, GL_STATIC_DRAW); 

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  

}

void load_shader(struct Render *render) {
    global.shader = shader("default.vert", "default.frag");
}

void render_begin(void) {
    glClearColor(0.00, 0.1, 0.1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

