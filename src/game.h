#ifndef GAME_H
#define GAME_H

#define BACKGROUND 0x386B5C

#include "window.h"
#include "gfx.h"
#include "render.h"

struct Game 
{
    struct GLFWwindow *window;
};

void game_init(struct Game *game);
void game_run(struct Game *game);
void game_shutdown();

#endif