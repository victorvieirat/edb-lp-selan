#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;
#include <iterator>
using std::distance;
#include <algorithm>
using std::sort;
using std::swap;

namespace graal {

template<class ForwardIt>
ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last)
{   
    int pos1 = 0, pos2 = 0, n_pos =0, orig_first = 0;

    //Encontra posição do valor n_first
    while(first != last){    
        if(*(first + n_pos) == *n_first)
            break;
        n_pos++;
    }
    //Repete n_pos vezes
    for(int a =0; a < n_pos; a++){
        pos1 = orig_first;
        //Pula cada elemento para a esquerda 1 vez
        for(int b =0; b < last-first; b++){
            pos2 = pos1-1;
    
            if(pos2 < 0) pos2 = last-(first+1);
            else if(pos2 >last-(first+1)) pos2 =0;
            if(pos1 < 0) pos1 = last-(first+1);
            else if(pos1 >last-(first+1)) pos1 =0;

            swap(*(first+pos1),*(first+pos2));
            pos1++;
        }
        orig_first--;
        if(orig_first < 0) orig_first = last-(first+1);
    }
   return last;
}

}
#endif
