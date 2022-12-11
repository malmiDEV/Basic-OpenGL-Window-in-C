#ifndef GLOBAL_H
#define GLOBAL_H

#include "render.h"
#include "shader.h"
#include "camera.h"

typedef struct 
{
    Shader shader;
    Render_State render;
    Camera camera;
} Global;

extern Global global;

#endif