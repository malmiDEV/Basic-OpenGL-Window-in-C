#ifndef SHADER_H
#define SHADER_H    

#include "cglm/cglm.h"
#include "cglm/struct.h"

typedef struct 
{
    unsigned int id;
    mat4s proj;
    mat4s model;
    mat4s view;
} Shader;  

Shader shader(const char* vertex_path, const char* frag_path);
char *shader_read_file(const char* file_path);

#endif