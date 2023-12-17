#include <iostream>

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

namespace greg{


auto range(double a, double b){
    if (a-b<0)
    {
        return b-a;
    }
    else{
        return a-b;
    }
}


// specifically made to work together with FileData.hpp 
template <typename T>
auto* char_to_num(const char* str){
    long length = greg::String::length(str);
    int data_amount = 0;
    for(int i = 0; i < length; i++){
        if(str[i] == '\n'){
            data_amount++;
        }
        else{
            str[i] 
        }
    }
    T result[data_amount];
    for(){

    }
}

}
#endif