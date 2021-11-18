


/**
 * @file dataframe.h
 * @author Victor Vieira .T (victorvieira.rn@gmail.com)
 * @brief This class contain all the informations to make the bars;
 * @version 0.1
 * @date 2021-08-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../lib/common.h"


/// This the main class that represents the game manager.
class DF {
    //== Public methods
    public:
    
    //Set functions
    bool set_fps(int num); //Set the fps of the game (-f parameter of command line)
    bool set_maxbar(int num); //Set the number max of bars (-b parameter of command line)
    bool set_title(string input); //Set the title
    bool set_label(string input); //Set the label
    bool set_source(string input); //Set the source
    //Get funcionts
    int get_fps(); //Get the fps
    int get_maxbar(); //Get the number max of bars
    int get_nlayer(); //Get the number of Time Stamps
    string get_title(); //Get the title
    string get_label(); //Get the label
    string get_source(); //Get the source
    int get_maxsizebar(); //Get the Biggest valeu in all dataframe
    int get_uniquesize(); //Get the number of unique categories
    int get_uniqueindex(string input); //Get the index of givan the category name
    
    /**
     * @brief Print the top of one the chart
     * @param layer The time stamp number
     */
    void print_top(int layer);
    /**
     * @brief Print the bottom of a chart
     */
    void print_bottom();
    /**
     * @brief Recieves a 3D vector of string with pure from the file
     * and collect the information that will be used.
     * 
     * @param result The 3D vector with info with from file with no treatment
     * @return true Everything went ok
     * @return false something went wrong
     */
    bool input_frame_info(std::vector<std::vector<std::vector<std::string>>> result);
    std::vector<Charts::Bar_Info> head(Charts::cont size, Charts::cont run);

    //== Aux methods
    private:
    std::vector<Charts::Frame> Data; //All information that will be used
    std::vector<string> unique_category; //nique categories names.
    int fps = 24;          // Attribute
    int max_bar = 5;       // Attribute
    //This variable give a information if is necessary to all bars must be equal
    bool different_colors= true; 
    Charts::numeric largest_bar =0; //The biggest valeu on all dataframe
    string title = "UNTITLED", source = "UNTITLED", label = "UNTITLED";
    /**
     * @brief Recieve a name of categry and, if it's unique, it's added on unique_category
     * 
     * @param input Name of possible new category
     */
    void add_unique(string input);

};
#endif
