#include "dynamic_array.hpp"

#ifndef TYPE_CONVER_HPP
#define TYPE_CONVER_HPP

// warning: float to char* is not accurate as it pushes the floating point apraximation value to become bigger than should it be
    // example: 123.456 becomes 123.4560012
    // avoid by using double_to_char() instead

// for int to char*, use long_to_char() instead, works the same way

// Todo: add support for negative numbers

namespace greg{

greg::Dy_Array<int> double_to_digits(double value){
    greg::Dy_Array<int> digits;
    bool is_negative = value < 0;
    if(is_negative){
        value *= -1;
    }
    int int_part = (int)value;
    double decimal_part = value - int_part;
    greg::Dy_Array<int> int_digits;
    do {
        int_digits.push_back(int_part % 10);
        int_part /= 10;
    } while (int_part != 0);

    for(int i = int_digits.get_length() - 1; i >= 0; i--){
        digits.push_back(int_digits[i]);
    }

    digits.push_back(-2); // decimal point

    // push the decimal part
    for(int i = 0; i < 15; i++){
        decimal_part *= 10;
        digits.push_back((int)decimal_part);
        decimal_part -= (int)decimal_part;
    }

    if (is_negative) {
        for (int i = 0; i < digits.get_length(); i++) {
            digits[i] *= -1;
        }
    }
    return digits;
}

greg::Dy_Array<int> float_to_digits(float value){
    greg::Dy_Array<int> digits;
    bool is_negative = value < 0;
    if(is_negative){
        value *= -1;
    }
    int int_part = (int)value;
    float decimal_part = value - int_part;
    greg::Dy_Array<int> int_digits;
    do {
        int_digits.push_back(int_part % 10);
        int_part /= 10;
    } while (int_part != 0);

    for(int i = int_digits.get_length() - 1; i >= 0; i--){
        digits.push_back(int_digits[i]);
    }

    digits.push_back(-2); // decimal point

    // push the decimal part
    for(int i = 0; i < 7; i++){
        decimal_part *= 10;
        digits.push_back((int)decimal_part);
        decimal_part -= (int)decimal_part;
    }

    if (is_negative) {
        for (int i = 0; i < digits.get_length(); i++) {
            digits[i] *= -1;
        }
    }

    return digits;
}

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
    result = new char[digits.get_length()+1];
    for(int i = 0; i < digits.get_length(); i++){
        result[i] = (digits[i] + 48);
    }
    result[digits.get_length()] = '\0';
    return result;
}

char* double_to_char(double value){
    greg::Dy_Array<int> digits;
    digits = double_to_digits(value);
    char* result;
    result = new char[digits.get_length()+1];
    for(int i = 0; i < digits.get_length(); i++){
        result[i] = (digits[i] + 48);
    }
    result[digits.get_length()] = '\0';
    return result;
}

char* float_to_char(float value){
    greg::Dy_Array<int> digits;
    digits = float_to_digits(value);
    char* result;
    result = new char[digits.get_length()+1];
    for(int i = 0; i < digits.get_length(); i++){
        result[i] = (digits[i] + 48);
    }
    result[digits.get_length()] = '\0';
    return result;
}

}






#endif