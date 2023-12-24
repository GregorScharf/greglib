#include "dynamic_array.hpp"

#ifndef TYPE_CONVER_HPP
#define TYPE_CONVER_HPP

// TODO: add support for floats and doubles

namespace greg{

greg::Dy_Array<int> long_to_digits(long value) {
    greg::Dy_Array<int> digits;
    bool is_negative = value < 0;
    if(is_negative){
        value *= -1;
    }

    do {
        digits.push_back(value % 10);
        value /= 10;
    } while (value != 0);

    if (is_negative) {
        for (int i = 0; i < digits.get_length(); i++) {
            digits[i] *= -1;
        }
    }

    greg::Dy_Array<int> result; // reverse digits
    for (int i = digits.get_length() - 1; i >= 0; i--) {
        result.push_back(digits[i]);
    }

    return result;
}
char* long_to_char(long value){
    greg::Dy_Array<int> digits;
    digits = long_to_digits(value);
    char* result;
    result = new char[digits.get_length()+2];
    for(int i = 0; i < digits.get_length(); i++){
        result[i] = (digits[i] + 48);
    }
    result[digits.get_length()] = '\0';
    return result;
}
}





#endif