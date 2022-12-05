#ifndef RENDER_H
#define REDNER_H

#include "gfx.h"
#include "shader.h"

struct Render {
    unsigned int vao;
    unsigned int vbo;
    unsigned int ebo;
};

void init_quad(unsigned int *vao, unsigned int *vbo, unsigned int *ebo);
void draw_quad(void);
void load_shader(struct Render *render);

void render_init(void);
void render_begin(void);

#endif