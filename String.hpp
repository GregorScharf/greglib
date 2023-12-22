#include "dynamic_array.hpp"
#include <stdexcept>
#include "range.hpp"
#include <cstdio>

#ifndef STRING_REWRITE_HPP
#define STRING_REWRITE_HPP

namespace greg{


class String{
    greg::Dy_Array<char> array;
    
    public:
    static long length(const char* str){
        long i = 0;
        while((str != NULL) && (str[i] != '\0')){
            i++;
        }
        return i+1;
    }
    String(){;
    }
    String(const char* str){
        for(long i = 0; i < String::length(str); i++){
            array.push_back(str[i]);
        }
    }
    void reassign(const char* str){
        array.clear();
        for(long i = 0; i < String::length(str); i++){
            array.push_back(str[i]);
        }
    }
    
    void append(const char* str){
        for(long i = 0; i < String::length(str); i++){
            array.push_back(str[i]);
        }
    }
    void change_char(long index, char value){
        if(index < 0 || index >= array.get_length()){
            throw std::out_of_range("Index out of range");
        }
        array[index] = value;
    }
    greg::Dy_Array<char> get_array(){
        return array;
    }
    long get_length(){
        return array.get_length();
    }
    long get_size(){
        return array.get_size();
    }
    void clear(){
        array.clear();
        array.push_back('\0');
    }
    void slice(long index1, long index2){
        if(index1 < 0 || index1 >= array.get_length() || index2 < 0 || index2 >= array.get_length()){
            throw std::out_of_range("Index out of range");
        }
        if(index1 > index2){
            throw std::invalid_argument("Index1 must be smaller than index2");
        }
        array.slice(index1, index2);
    }
    void print(){
        for(long i = 0; i < array.get_length(); i++){
            putchar(array[i]);
        }
        putchar('\n');
    }

    char operator[](long index){
        if(index < 0 || index >= array.get_length()){
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    const char* get_ptr(){
        return &array[0];
    }

    void operator=(const char* str){
        reassign(str);
    }
    void operator=(const String* str){
        array = str->array;
    }
    void operator=(const String str){
        array = str.array;
    }
    void operator+=(const char* str){
        append(str);
    }
    void operator+=(String str){
        for(long i = 0; i < str.get_length(); i++){
            array.push_back(str[i]);
        }
    }
    void operator+=(String* str){
        for(long i = 0; i < str->get_length(); i++){
            array.push_back((*str)[i]);
        }
    }
    void operator+=(const char c){
        append(&c);
    }
};

}
#endif 