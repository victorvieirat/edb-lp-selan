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

/*! 
 * TODO: documentação no estilo doxygen
 */
template<class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{   
    while(first != last){    
        if(!p(*first)){
            for(ForwardIt temp = first; temp < (last-1); temp++)
                swap(*temp, *(temp+1));
            last--;
        }else
            first++;
    }
    return last;
}

}
#endif
