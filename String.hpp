#include "dynamic_array.hpp"
#include "out.hpp"
#include "type_conver.hpp"

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
    void append(const char c){
        array.push_back(c);
    }
    void change_char(long index, char value){
        if(index < 0 || index >= array.get_length()){
            greg::out_of_range();
        }
        array[index] = value;
    }
    const char* get_charptr(){
        return array.get_array();
    }
    long get_length(){
        return array.get_length();
    }
    void clear(){
        array.clear();
        array.push_back('\0');
    }
    void slice(long index1, long index2){
        if(index1 < 0 || index1 >= array.get_length() || index2 < 0 || index2 >= array.get_length()){
            greg::out_of_range();
        }
        if(index1 > index2){
            greg::invalid_argument();
        }
        array.slice(index1, index2);
    }
    void print(){
        for(long i = 0; i < array.get_length(); i++){
            greg::putchar(array[i]);
        }
        greg::putchar('\n');
    }

    char operator[](long index){
        if(index < 0 || index >= array.get_length()){
            greg::out_of_range();
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
        array[array.get_length()-1] = c;
    }
};

}
#endif 