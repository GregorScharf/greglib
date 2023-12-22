#include "String.hpp"
#include "dynamic_array.hpp"

#ifndef CHAR_TO_NUM_HPP
#define CHAR_TO_NUM_HPP

namespace greg{

template <typename T>
void char_to_num(const char* str, T* result){

long length = greg::String::length(str);
int data_amount = 0;

for(int i = 0; i < length; i++){
    if(str[i] == '\n'){
        data_amount++;
    }
}

greg::Dy_Array<long> nums[data_amount];
int count = 0;
for(int i = 0; i < length-1; i++){
    if(str[i] == '\n'){
        count++;
    }
    else{
        nums[count].push_back(str[i]-48);

    }
}

for(int i = 0; i < data_amount; i++){
    for(int j = 0; j < nums[i].get_length() ; j++){
        for(int k = nums[i].get_length()-1; k > j; k--){
            nums[i][j] *= 10;
        }
    }
}

for(int i = 0; i < data_amount; i++){
    result[i] = 0;
}
for(int i = 0; i < data_amount; i++){
    for(int j = 0; j < nums[i].get_length(); j++){
        result[i] += nums[i][j];
    }
}

}
}
#endif