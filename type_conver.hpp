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

const char* to_charptr(long value){
    greg::Dy_Array<int> digits;
    digits = long_to_digits(value);
    greg::Dy_Array<char> chars;
    for(int i = 0; i < digits.get_length(); i++){
        chars.push_back(digits[i] + 48);
    }
    return chars.get_array();

    
}


}





#endif