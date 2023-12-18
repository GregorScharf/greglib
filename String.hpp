#include <iostream>
#include "functions.hpp"

#ifndef STRING_HPP
#define STRING_HPP

namespace greg
{


// Warning: this is not safe, it is meant for me as an excersize to learn how to free/delete in c++ 

class String{
    char *backup;
    long len;

    // creates backup for reassignment;
    static void copy(String* self){
        self->backup = new char[self->len];
        for(long i = 0; i <= self->len; i++){
            self->backup[i] = self->array[i];
        }
    }
    public:
    char *array;

    static long length(const char* str){
        long i = 0;
        while((str != NULL) && (str[i] != '\0')){
            i++;
        }
        return i+1;
    }
    
    String(){
        len = 0;
        array = new char[len];
        array[0] = ('\0');
    }
    String(const char* str){
        len = String::length(str);
        array = new char[len];
        for(long i = 0; i <= len; i++){
            array[i] = str[i];
        }
    }

    long get_length(){
        return len;
    }
    // this only sets the length, IT DOES NOT REALLOC
    long set_length(long x){
        len = x;
        return len;
    }

    void print(){
        for(long i = 0; i < len; i++){
            putchar(array[i]);
        }
    }

    void append(const char* add){
        long added_len = String::length(add);
        String::copy(this);
        delete(array);
        array = new char[len+added_len];
        for(long i = 0; i <= len; i++){
            array[i] = backup[i];
        }
        for(long i = 0; i <= added_len; i++){
            array[len+i] = add[i];
        }
        len += added_len;
        delete(backup);

    }


    int slice(int start, int end){
        if(start < 0){
            throw std::invalid_argument("Starting index below 0 not allowed\n");
            return -1;
        }
        if(end > len){
            throw std::invalid_argument("Ending index larger than string length not allowed\n");
            return -1;
        }
        for(long i = start-1; i < len; i++){
            array[i] = array[i+static_cast<int>(range(start, end))];
        }
        len -= range(start, end);
        return len;

    }
    
    ~String(){
        if(!array){
            delete(array);
        }
    }
};

template <typename T>
auto char_to_num(const char* str){

long length = greg::String::length(str);
int data_amount = 0;

std::vector<int> cutting_positions;
for(int i = 0; i < length; i++){
    if(str[i] == '\n'){
        data_amount++;
        cutting_positions.push_back(i);
    }
}
std::vector<char> array[data_amount];

for(int i = 0; i < data_amount; i++){
    if(i == 0){
        for(int j = 0; j < cutting_positions[i]; j++){
            array[i].push_back(' ');
        }
    }
    else{
        for(int j = 0; j < cutting_positions[i] - cutting_positions[i-1] -1; j++){
            array[i].push_back(' ');
        }     
    }
}


return 0;
}


}
#endif