#ifndef GLOBAL_H
#define GLOBAL_H

#include "shader.h"

struct Global {
    struct Shader shader;
};

extern struct Global global;

#endif