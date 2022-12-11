#include "shader.h"
#include <glad/glad.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Shader shader(const char* vertex_path, const char* frag_path) 
{
    Shader shader = {0};
    shader.id = glCreateProgram();

    int success;
    char infolog[512];

    const char* vert_shader_src = shader_read_file(vertex_path);
    const char* frag_shader_src = shader_read_file(frag_path);

    // vert shader load
    unsigned int vert_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert_shader, 1, &vert_shader_src, NULL);
    glCompileShader(vert_shader);
    glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &success);
    if (!success) 
    {
        glGetShaderInfoLog(vert_shader, 512, NULL, infolog);
        printf("VERT SHADER COMPILE ERROR: %s", infolog);
    }

    // frag shader load
    unsigned int frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag_shader, 1, &frag_shader_src, NULL);
    glCompileShader(frag_shader);
    glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &success);
    if (!success) 
    {
        glGetShaderInfoLog(frag_shader, 512, NULL, infolog);
        printf("FRAG SHADER COMPILE ERROR: %s", infolog);
    }

    // linking shaders
    glAttachShader(shader.id, vert_shader);
    glAttachShader(shader.id, frag_shader);
    glLinkProgram(shader.id);
    glGetProgramiv(shader.id, GL_LINK_STATUS, &success);
    if (!success) 
    {
        glGetProgramInfoLog(shader.id, 512, NULL, infolog);
        printf("SHADER LINKING ERROR: %s", infolog);
    }

    glDeleteShader(vert_shader);
    glDeleteShader(frag_shader);

    free((void*)vert_shader_src);
    free((void*)frag_shader_src);

    return shader;
}

char *shader_read_file(const char* file_path) 
{
    FILE *fp = fopen(file_path, "r");

    if (fp == NULL) 
    {
        printf("Shader File Load Error: %s", file_path);
    }
    
    char *string = malloc(1024);
    memset(string, 0, 1024 * sizeof(char));

    fread(string, 1 * sizeof(char), 1024, fp);

    printf("\nshaders: \n%s\n", string);

    fclose(fp);

    return string;
}