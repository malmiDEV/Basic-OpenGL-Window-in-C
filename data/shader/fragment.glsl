#version 330 core

out vec4 FragColor;

in vec2 tex_c;

uniform sampler2D ourtex;

void main()
{
    FragColor = texture(ourtex, tex_c);
} 

