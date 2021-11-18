/*!
 * This is a template code to demonstrate how to measure runtime of part of your code.
 * I'm using the chrono C++ library.
 * @date September 8th, 2020.
 * @author Selan
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include "searching.cpp"

int main( void )
{
    unsigned int min = 10000;
    unsigned int max = 100000000;

    std::ofstream BINIT("BINIT.txt" );
    
    int repeticoes = 30; 
    double soma = 0;

    while (min < max){
        std::vector<int>vetor(min);
        std::fill(vetor.begin(), vetor.end(), 0);

        soma = 0;

        for(int j = 0; j < repeticoes; j++){

            auto start = std::chrono::steady_clock::now();
            auto resultado = sa::bsearch( vetor.data(), &vetor.back(), -1 );

            std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();

            //Store the time difference between start and end
            // auto diff = end - start;
            std::chrono::duration<double, std::milli> diff = end - start;
            soma+= (diff).count();

        }
        
        soma = soma/repeticoes;
        BINIT << min << ","<< soma << std::endl;
        min+= 20000;

    }
 
    BINIT.close();
    std::ofstream BINREC( "BINREC.txt" );
    min = 10000;

    while (min < max){
        std::vector<int>vetor(min);
        std::fill(vetor.begin(), vetor.end(), 0);

        soma = 0;

        for(int j = 0; j < repeticoes; j++){

            auto start = std::chrono::steady_clock::now();

            auto resultado = sa::re_bsearch( vetor.data(), &vetor.back(), -1);

            std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
            //Store the time difference between start and end
            // auto diff = end - start;
            std::chrono::duration<double, std::milli> diff = end - start;
            soma+= (diff).count();

        }
        
        soma = soma/repeticoes;
        BINREC << soma << std::endl;
        min+= 20000;

    }   
    BINREC.close();
    std::ofstream LINIT( "LINIT.txt" );
    min = 10000;

    while (min < max){
        std::vector<int>vetor(min);
        std::fill(vetor.begin(), vetor.end(), 0);

        soma = 0;

        for(int j = 0; j < repeticoes; j++){

            auto start = std::chrono::steady_clock::now();

            auto resultado = sa::lsearch( vetor.data(), &vetor.back(), -1 );

            std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
            //Store the time difference between start and end
            // auto diff = end - start;
            std::chrono::duration<double, std::milli> diff = end - start;
            soma+= (diff).count();

        }
        soma = soma/repeticoes;
        LINIT << soma << std::endl;
        min+= 20000;

    }
    LINIT.close();
    

}
