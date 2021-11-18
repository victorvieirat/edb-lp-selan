/*!
 * @file game_manager.cpp
 *
 * Implementation of the game manager class.
 */

#include "game_manager.h"


bool GameManager::validate( int argc, char * argv[] )
{ 
    if(argc == 1){
        cout << "Usage: bcr [<options>] <input_data_file>\n";
        cout << "   Bar Chart Race options:\n";
        cout << "       -b  <num> Max # of bars in a single char.\n";
        cout << "                 Valid range is [1,15]. Default values is 5.\n";
        cout << "       -f  <num> Animation speed in fps (frames per second).\n";
        cout << "                 Valid range is [1,24]. Default value is 24.\n";
        return false;
    }
    for(Charts::cont a=0;a<50;a++){ cout << "=";}
    cout <<"\n";
    cout << "     Welcome to the Bar Char Race, v1.0\n";
    cout << "    Copyright (C) 2021, Victor Vieira T.\n";
    for(Charts::cont a=0;a<50;a++){ cout << "=";}
    cout <<"\n";

    for(Charts::cont i=1; i < (argc-2); i++){
        if(strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "-F") == 0){
            i++;
            data.set_fps(atoi(argv[i]));
        }else if(strcmp(argv[i], "-b") == 0|| strcmp(argv[i], "-B") == 0){
            i++;
            data.set_maxbar(atoi(argv[i]));
        }
    }
    cout << ">>> Preparing to read input file \" "<< argv[argc-1]<<"\"...\n";
    
    if(!analyze_file(argv[argc-1]))
    { 
        cout << ">>> ERROR: something went wrong on reading the Input file.\n\n";
        return false;
    }
    
    return true;
}

void GameManager::confirmation(){
    string choice;
    cout << ">>>Animation speed is: " << data.get_fps() <<".\n";
    cout << ">>>Title: " << data.get_title() <<".\n";
    cout << ">>>Label is: " << data.get_label() <<".\n";
    cout << ">>>Source is: " << data.get_source() <<".\n";
    cout << ">>>Number of categories is: " << data.get_uniquesize() <<".\n";
    
    cout <<Color::tcolor(">>>CONFIGURATION: Your max bar size is :" +std::to_string(characters_bar)+ ", want to change this size ?[y/n]",Color::RED,Color::REGULAR,Color::BG_BLACK);
    cout << "\e[0m\n";
    getline (std::cin,choice);
    if(choice.compare("y")==0||choice.compare("y")==0){
        cout << ">>> Below there are 4 differents bar as reference, choose number of the biggest that fit in your terminal.\n";
        for(Charts::cont a=0; a< 4;a++){    
            for(Charts::cont b=0; b< 50+(a*50);b++){
                cout << Color::tcolor(" ",Color::BLUE,Color::BOLD,Color::BG_GREEN);
            }
            cout << "\e[0m  THE SIZE BAR IS: " <<50+(a*50) << "\n\n";
        }
         cout << ">>> Enter the size you want:";
         cin >> characters_bar;
         cin.ignore(1000,'\n');
    }
    
    cout << ">>>Press enter to begin the animation.\n";
    cin.ignore();
}

bool GameManager::quit_game(){
    if(num_run == data.get_nlayer())
        return true;
    else
        return false;
}

void GameManager::prepare_bars(){
    actual_frame.clear();
    actual_frame.resize(data.head(data.get_maxbar(), num_run).size());
    actual_frame = data.head(data.get_maxbar(), num_run);
}

void GameManager::update(){
    data.print_top(num_run);
    Charts::numeric tam,step = characters_bar/10;
    Charts::cont aux=1;

    bool different_color = true;
    if(int(Color::color_list.size()) < data.get_uniquesize()){
        different_color = false;
    }
    for(Charts::cont a=0; a< actual_frame.size();a++){
        tam = (actual_frame[a].value*characters_bar)/data.get_maxsizebar();
        for(int b=0; b< tam+3;b++){
            if(different_color)
                cout << Color::tcolor(" ",Color::BLUE,Color::BOLD,Color::color_list[data.get_uniqueindex(actual_frame[a].category)]);
            else
                cout << Color::tcolor(" ",Color::BLUE,Color::BOLD,Color::BG_BLUE);
        }
        cout << "   " << Color::tcolor(actual_frame[a].label, Color::BOLD) << "  " << Color::tcolor("["+std::to_string(actual_frame[a].value)+"]", Color::BOLD) << "\n\n";
    }
    cout << Color::tcolor("---",Color::WHITE,Color::BOLD);
    while(step*aux <=  characters_bar){
        for(Charts::cont b=0; b< step-1;b++){
            cout << Color::tcolor("-",Color::WHITE,Color::BOLD); 
        }
        cout << Color::tcolor("|",Color::WHITE,Color::BOLD); 
        aux++;
    }
    cout <<"\n";
    aux=1;
    int size = 0;
    while(step*aux <=  characters_bar){
        for(Charts::cont b=size; b< step;b++){
            cout<<" ";
        }
        cout << Color::tcolor(std::to_string((data.get_maxsizebar()/10)*aux),Color::WHITE,Color::BOLD); 
        size = std::to_string((data.get_maxsizebar()/10)*aux).size();
        aux++;
    }
    cout << "\n\n";
    data.print_bottom();
    timing(data.get_fps());
    num_run++;
}

void GameManager::bye(){
    cout << "Hope you have enjoyed the Bart Chart Race\n";
}

bool GameManager::analyze_file(char *argv)
{ 
    string filename(argv), temp;
    Charts::cont aux;
    stringstream ss;
    std::vector<std::vector<std::vector<std::string>>> result; 

    cout << ">>> Processing data, please wait.\n";
    //Try to open the file
    ifstream input_file(filename);
    if (!input_file.is_open()) { return false;} 
    //Get title
    if(!getline(input_file, temp)) { return false;}
    data.set_title(temp);
    //Get Label
    if(!getline(input_file, temp)) { return false;}
    data.set_label(temp);
    //Get Source
    if(!getline(input_file, temp)) { return false;}
    data.set_source(temp);


    while(getline(input_file, temp)){
        if(is_number(temp)){
            result.resize(result.size()+1);
            ss.clear();
            ss << temp;
            ss >> aux;
            result[result.size()-1].resize(aux);
            for(Charts::cont i =0; i < aux; i++){
                getline(input_file, temp);
                stringstream s_stream(temp);
                while(s_stream.good()){
                    string substr;
                    getline(s_stream, substr, ','); //get first string delimited by comma
                    result[result.size()-1][i].push_back(substr);
                }
            } 
        }
    }
    data.input_frame_info(result);
    return true;
}

//======================[ game_manager.cpp ] ======================//
