#include "game.h"

void game_init(struct Game *game) 
{
    game->window = init_window(800, 600, "Game");
}

void game_run(struct Game *game) 
{
    render_init();
    while (!glfwWindowShouldClose(game->window)) 
    {
        render_begin();
        
        draw_quad();

        glfwSwapBuffers(game->window);
        glfwPollEvents();
    }
}

void game_shutdown() 
{
    window_close();
}
