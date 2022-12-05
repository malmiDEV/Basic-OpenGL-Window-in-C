#ifndef SHADER_H
#define SHADER_H


struct Shader {
    unsigned int id;
};  

struct Shader shader(const char* vertex_path, const char* frag_path);
char *shader_read_file(const char* file_path);

#endif