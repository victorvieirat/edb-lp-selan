/*!
 * @file dataframe.cpp
 *
 * Implementation of the game data set used.
 */

#include "dataframe.h"

//====================[ GAME MANAGER METHODS ]========================//

//BEGIN : SET FUNCTIONS
bool DF::set_fps(int num){
    if(num > 24 || num < 1){
        cout << ">>> WARNING: FPS chosen by user is out of the range [1,24], the default 24 will be used.\n";
        return false;
    }else{
        fps = num;
        return true;
    }
}

bool DF::set_maxbar(int num){
    if(num > 15 || num < 1){
        cout << ">>> WARNING: Max Bax chosen by user is out of the range [1,15], the default 5 will be used.\n";
        return false;
    }else{
        max_bar = num;
        return true;
    }
}

bool DF::set_title(string input){
    if(input.size() == 0){
        return true;
    }else{
        title = input;
        return true;
    }   
}

bool DF::set_label(string input){
    if(input.size() == 0){
        return true;
    }else{
        label = input;
        return true;
    }   
}

bool DF::set_source(string input){
    if(input.size() == 0){
        return true;
    }else{
        source = input;
        return true;
    }   
}
//END : SET FUNCTIONS

//BEGIN : GET FUNCTIONS
int DF::get_fps(){ return fps;}

int DF::get_maxbar(){ return max_bar;}

int DF::get_nlayer(){ return Data.size();}

string DF::get_title(){ return title;}

string DF::get_label(){ return label;}

string DF::get_source(){ return source;}

int DF::get_maxsizebar(){ return largest_bar;}

int DF::get_uniquesize(){ return unique_category.size();}

int DF::get_uniqueindex(string input){
    for(Charts::cont a =0; a < unique_category.size();a++){
        if(unique_category[a].compare(input)==0)
            return a;
    }
    return 0;
}
/// END : GET FUNCTIONS


/// BEGIN : PRINT FUNCTIONS
void DF::print_top(int layer){
    for(int a=0; a< 30;a++){
        cout<<"\n";
    }
    cout << Color::tcolor("\n\n");
    for(int a=0; a< 20;a++){
        cout<<Color::tcolor(" ");
    }
    cout << Color::tcolor(title+"\n");
    for(int a=0; a< 30;a++){
        cout<<Color::tcolor(" ");
    }   
    cout << Color::tcolor("Time Stamp: "+ Data[layer].time_stamp);
    cout << "\n\n";
}

void DF::print_bottom(){
    cout << Color::tcolor(label );
    cout <<  "\n";
    cout << Color::tcolor(source+"\n");
    if(different_colors){
        for(Charts::cont a=0; a < unique_category.size(); a++){
            cout << Color::tcolor(" ",Color::BLUE,Color::BOLD,Color::color_list[a])<<  Color::tcolor(" "+unique_category[a] + "    ");
        }
    }
    cout << "\n\e[0m";
    for(int a=0; a< 5;a++){
        cout<<"\n";
    }

}
/// END : PRINT FUNCTIONS


bool DF::input_frame_info(std::vector<std::vector<std::vector<std::string>>> result){
    stringstream ss;
    Charts::numeric aux;
    Data.resize(result.size());
    cout <<">>> We have \"" << result.size() << "\" charts, the first with \"" << result[0].size() <<"\" bars.\n";
    for(Charts::cont Layer = 0;Layer < result.size(); Layer++){
        Data[Layer].Bar.resize(result[Layer].size());
        Data[Layer].time_stamp = result[Layer][0][0];
        //Add to the last row
        
        for(Charts::cont Row = 0;Row < result[Layer].size(); Row++){
            Charts::cont Index = result[Layer][Row].size();
            Data[Layer].Bar[Row].label = result[Layer][Row][1];
            Data[Layer].Bar[Row].category = result[Layer][Row][Index-1];
            add_unique(Data[Layer].Bar[Row].category);
            ss << result[Layer][Row][Index-2];
            ss >> aux;
            ss.clear();
            Data[Layer].Bar[Row].value = aux;
            if(aux > largest_bar){
                largest_bar =aux;
            }
            
            //Uses selection sort to put in right position   
            for(Charts::cont i = 1; i < Data[Layer].Bar.size(); i++){
                for(Charts::cont j = i; j > 0 && Data[Layer].Bar[j].value > Data[Layer].Bar[j-1].value; j--){
                        swap(Data[Layer].Bar[j],Data[Layer].Bar[j-1]);
                    }
            }
        }
    }
    if(int(Color::color_list.size()) < get_uniquesize())
        different_colors = false;
    return true;
}

std::vector<Charts::Bar_Info> DF::head(Charts::cont size, Charts::cont run){
    if(size > Data[run].Bar.size())
        size = Data[run].Bar.size();
    
    std::vector<Charts::Bar_Info> head = {Data[run].Bar.begin(), Data[run].Bar.begin() + size };
    return head;
}

void DF::add_unique(string input){
    bool is_unique = true;
    for(Charts::cont a=0; a < unique_category.size(); a++){
        if(unique_category[a] == input)
            is_unique = false;
    }
    if(is_unique)
        unique_category.push_back(input);
    return;
}
//======================[ game_manager.cpp ] ======================//
