#include "src/game.h"

int main(int argv, char* args[]) 
{
    Game game = {0};

    game_init(&game);
    game_run(&game);
    game_shutdown();

    return 0;
}