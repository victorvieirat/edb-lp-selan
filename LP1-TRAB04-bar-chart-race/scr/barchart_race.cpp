#include "game_manager.h"
/**
 * @brief This program runs the game Bar Chart Race
 * 
 * @param argc The number of arguments on command line;
 * @param argv Argumentos passed on comand line
 */
int main( int argc, char * argv[] ){
    GameManager game;

    if(!game.validate( argc, argv )){
        return EXIT_SUCCESS;
    }
    game.confirmation();
    while(!game.quit_game()) 
    {
        game.prepare_bars();
        game.update();
    }
    game.bye();
    
    return EXIT_SUCCESS;
}
