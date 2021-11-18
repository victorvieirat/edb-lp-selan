#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

/**
 * @file game_manager.h
 * @author Victor Vieira .T (victorvieira.rn@gmail.com)
 * @brief This class is responsable to do the main actions of the game.
 * @version 0.1
 * @date 2021-08-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "dataframe.h"


/// This the main class/struct that represents the game manager.
class GameManager{
    /// Game state machine
    


    //== Public methods
    public:
    /**
     * @brief This functions validate the command line arguments, and call the function 
     *  analyze_file;
     * @param argc Number of arguments.
     * @param argv Arguments passed by command line.
     * @return true Success.
     * @return false Something went wrong.
     */
    bool validate(int argc, char *argv[]);
    /**
     * @brief Show informations collected and wait for user confirmation.
     */
    void confirmation();
    /**
     * @brief Compare if the Time Stamp total is equal to current Time Stamp , to check if the game is at end.
     * 
     * @return true The Time Stamp is the last, end game.
     * @return false There is more Time Stamp, continue game.
     */
    bool quit_game();
    /**
     * @brief At each Time Stamp the GameManager copy one time stamp to print another variable
     * this function clears the temporary Time Stamp and copies another one.
     */
    void prepare_bars();
    /**
     * @brief Print the bars and call another methods of dataframe to print the header and bottom.
     */
    void update();
    /**
     * @brief Bye message.
     */
    void bye();
    DF data;
    std::vector<Charts::Bar_Info> actual_frame;

    //== Aux methods
    private:
    /**
     * @brief This function open the file and collect all information 
     * passing to the dataframe class.
     * @param path file location
     * @return true success
     * @return false If something went wrong
     */
    bool analyze_file(char * path);
    Charts::cont num_run = 0;
    int characters_bar = 150;
};
#endif