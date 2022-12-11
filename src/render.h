#ifndef RENDER_H
#define REDNER_H

#include "render_internal.h"

typedef struct 
{
    float width;    
    float height;
} Render_State;

void draw_quad(void);
void render_init(void);
void render_begin(void);

#endif