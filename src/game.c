#include "game.h"

void game_init(Game *game) 
{
    game->window = init_window(800, 600, "Game");
    
    render_init();
    glfwSetInputMode(game->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    camera_init(game->window);
}

void game_run(Game *game) 
{
    while (!glfwWindowShouldClose(game->window)) 
    {
        render_begin();
        
        camera_move(game->window);
        draw_quad();

        glfwSwapBuffers(game->window);
        glfwPollEvents();
    }
}

void game_shutdown() 
{
    window_close();
}
