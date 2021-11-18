#include "common.h"

bool is_number(const std::string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void timing(Charts::cont fps){
    // This code pauses `duration` milliseconds between frames.
    // Convert fps to milliseconds.
    std::chrono::milliseconds  duration{ 1000/fps };
    std::this_thread::sleep_for( duration );

}