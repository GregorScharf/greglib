#include "String.hpp"
#include "dynamic_array.hpp"


#ifndef CHAR_TO_NUM_HPP
#define CHAR_TO_NUM_HPP

namespace greg{



// This function converts a string of numbers into an array of numbers.
// when there is a new line, it will put all numbers after the new line into a new number.
// Example:
// char* str = "123\n456\n789\n";
// int nums[3];
// char_to_num(str, nums);
// for(int i = 0; i < 3; i++){
//     print(nums[i]);
// }
// Output:
// 123
// 456
// 789
// 
// This function is useful when you want to read a file that contains numbers.
// segfaults will occur if the array which result is pointing to is not big enough.

template <typename T>
greg::Dy_Array<T> char_to_num(const char* str){

long length = greg::length(str);
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
    else if(47 < str[i] && str[i] < 58){
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
T* result = new T[data_amount];

for(int i = 0; i < data_amount; i++){
    result[i] = 0;
}
for(int i = 0; i < data_amount; i++){
    for(int j = 0; j < nums[i].get_length(); j++){
        result[i] += nums[i][j];
    }
}

greg::Dy_Array<T> result_array;
for(int i = 0; i < data_amount; i++){
    result_array.push_back(result[i]);
}
return result_array;
}
}
#endif
