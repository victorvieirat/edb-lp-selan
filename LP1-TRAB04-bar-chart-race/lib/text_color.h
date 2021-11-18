#ifndef COLOR_H
#define COLOR_H

#include <sstream>
using std::ostringstream;
#include <string>
using std::string;
#include <array>
using std::array;

namespace Color {

    // Alias
    typedef short value_t;

    // https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
    //=== Color attribute
    static constexpr short BLACK{ 30 };
    static constexpr short RED{ 31 };
    static constexpr short GREEN{ 32 };
    static constexpr short YELLOW{ 33 };
    static constexpr short BLUE{ 34 };
    static constexpr short MAGENTA{ 35 };
    static constexpr short CYAN{ 36 };
    static constexpr short WHITE{ 37 };
    static constexpr short BRIGHT_BLACK{ 90 };
    static constexpr short BRIGHT_RED{ 91 };
    static constexpr short BRIGHT_GREEN{ 92 };
    static constexpr short BRIGHT_YELLOW{ 93 };
    static constexpr short BRIGHT_BLUE{ 94 };
    static constexpr short BRIGHT_MAGENTA{ 95 };
    static constexpr short BRIGHT_CYAN{ 96 };
    static constexpr short BRIGHT_WHITE{ 97 };
    //=====Background color
    static constexpr short BG_BLACK{ 40 };
    static constexpr short BG_RED{ 41 };
    static constexpr short BG_GREEN{ 42 };
    static constexpr short BG_YELLOW{ 44 };
    static constexpr short BG_BLUE{ 44 };
    static constexpr short BG_MAGENTA{ 45 };
    static constexpr short BG_CYAN{ 46 };
    static constexpr short BG_WHITE{ 47 };
    static constexpr short BG_BRIGHT_BLACK{ 100 };
    static constexpr short BG_BRIGHT_RED{ 101 };
    static constexpr short BG_BRIGHT_GREEN{ 102 };
    static constexpr short BG_BRIGHT_YELLOW{ 103 };
    static constexpr short BG_BRIGHT_BLUE{ 104 };
    static constexpr short BG_BRIGHT_MAGENTA{ 105 };
    static constexpr short BG_BRIGHT_CYAN{ 106 };
    static constexpr short BG_BRIGHT_WHITE{ 107 };
    //=== Modificators.
    static constexpr short REGULAR{ 0 };
    static constexpr short BOLD{ 1 };
    static constexpr short UNDERLINE{ 4 };
    static constexpr short BLINK{ 5 };
    static constexpr short REVERSE{ 7 };

    static constexpr  array< value_t, 14>color_list{
        41, 42, 43,44, 45, 46, 47,
        101, 102, 103, 104, 105, 106, 107};

    inline string tcolor( const string & msg, short color=Color::WHITE, short modifier=Color::BOLD,  short background=Color::BG_BLACK)
    {
        ostringstream oss;
        oss << "\e[" << modifier << ";" << color << ";" << background << "m" << msg <<"\e[1;37;40m";
        return oss.str();
    }
}
#endif
