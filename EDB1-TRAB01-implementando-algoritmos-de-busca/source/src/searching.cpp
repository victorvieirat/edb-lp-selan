/*!
 * \file searching.cpp
 * Binary search, Linear search, Upper bound, lower bound implementation for an array of integers.
 * \author Selan R. dos Santos
 * \date June 17th, 2021.
 */

#include "searching.h"

namespace sa {

    /*!
     * Performs a **linear search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lsearch( value_type * first, value_type * last, value_type value )
    {   
        for(int * i = first; i < last; i++){
            if((*i) == value) return i;
        }
        return last; // STUB
    }

    /*!
     * Performs a **binary search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * bsearch( value_type * first, value_type * last, value_type value )
    {
        // TODO
        unsigned short int mid;
        int *t_last = last;
        while(first != t_last){
            mid = (t_last-first)/2;
            if(*(first + mid) == value)
                return (first + mid);
            else if(*(first + mid) > value)
                t_last = first + mid;
            else
               first += mid + 1;

        }
        return last; // STUB
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _not less_  than (i.e. greater or equal to) `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lbound( value_type * first, value_type * last, value_type value )
    {
        // TODO
        unsigned short int mid;
        int *t_last = last;
        while(first != t_last){
            mid = (t_last-first)/2;
            if(*(first + mid) >= value)
                t_last = first + mid;
            else
               first += mid + 1;
        }
        return first; // STUB
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _greater_  than `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * ubound( value_type * first, value_type * last, value_type value )
    {
         // TODO
        unsigned short int mid;
        int *t_last = last;
        while(first != t_last){
            mid = (t_last-first)/2;
            if(*(first + mid) > value)
                t_last = first + mid;
            else
               first += mid + 1;
        }
        return first; // STUB
    }

   value_type * re_bsearch( value_type * first, value_type * last, value_type value )
    {
        // TODO
        unsigned short int mid;
        int *temp;
    
        mid = (last-first)/2;
        
        if(*(first + mid) == value)
            return (first + mid);
        else if(first == last)
            return last;
        else if(*(first + mid) > value){
            temp = re_bsearch(first, (first + mid), value);
            if((first + mid) == temp) return last;
        }else{
            temp = re_bsearch((first+mid+1), last, value);
            if(last == temp) return last;
        }
    
        return temp; // STUB
    }
}

