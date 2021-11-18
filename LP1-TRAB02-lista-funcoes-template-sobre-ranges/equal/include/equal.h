#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;
#include <iterator>
using std::distance;
#include <algorithm>
using std::sort;

namespace graal {

/*! 
 * TODO: documentação no estilo doxygen
 */
template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, Equal eq)
{
    while (first1 != last1){
        if(!eq(*first1,*first2))
            return false;
        first1++;
        first2++;
    }
    
    return true;
}

template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1,
           InputIt2 first2, InputIt2 last2,
           Equal eq )
{
   while (first1 != last1){
        if(!eq(*first1,*first2))
            return false;
        first1++;
        first2++;
    }
    
    return true;
}

}
#endif
