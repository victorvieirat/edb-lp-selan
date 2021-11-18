 /**
 * @file common.h
 * @author Victor Vieira T. (victorvieira.rn@gmail.com)
 * @brief Libraries used in the project
 * @version 0.1
 * @date 2021-08-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <sstream> // For the stringstream.
using std::ostringstream;
using std::stringstream;

#include <random>
using std::random_device;
using std::mt19937;

#include <string>
using std::string;
using std::stoul;
using std::stoi;
#include <string.h> //strcmp

#include <exception>
using std::invalid_argument;
using std::out_of_range;

#include <sstream>  

#include <fstream> 
using std::ifstream;

#include <algorithm>
using std::swap;
#include <cctype> 


#include <thread>

#include "text_color.h"

namespace Charts
{
    using cont = unsigned short int; //<! data type for a keno hit.
    using numeric = long long int;
    enum GameState{
        OK = 0,
        ERROR_VALIDATION =1
    };
    struct Bar_Info{   
        string label;   
        string category;
        numeric value;
    };   
    struct Frame{
        string time_stamp;
        std::vector<Bar_Info> Bar; 
    };
    
};
/**
 * @brief Check if string is a positive integer
 * 
 * @param s String to test if is number
 * @return true Is number
 * @return false Is not number
 */
bool is_number(const std::string& s);
/**
 * @brief Given a fps waits the time.
 * 
 * @param fps frame per second
 */
void timing(Charts::cont fps);
