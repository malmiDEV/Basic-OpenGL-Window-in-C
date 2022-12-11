#ifndef RENDER_INTERNAL_H
#define RENDER_INTERNAL_H

#include "stb/stb_image.h"
#include "cglm/cglm.h"

typedef struct
{
    unsigned int vao;
    unsigned int vbo;
    unsigned int ebo;
} Render_Internal;

void init_quad(unsigned int *vao, unsigned int *vbo, unsigned int *ebo);
void init_shader(void);

#endif