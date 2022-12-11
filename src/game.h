#ifndef GAME_H
#define GAME_H

#define BACKGROUND 0x386B5C

#include "window.h"
#include "gfx.h"
#include "global.h"

typedef struct 
{
    GLFWwindow *window;

} Game;

void game_init(Game *game);
void game_run(Game *game);
void game_shutdown();

#endif