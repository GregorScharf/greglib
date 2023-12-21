#include "range.hpp"
#include <cstdint>
#include <cstdio>
#include <stdexcept>
#include "dynamic_array.hpp"

#ifndef STRING_HPP
#define STRING_HPP

namespace greg
{


// Warning: this is not safe, it is meant for me as an excersize to learn how to free/delete in c++ 

class String{
    char *backup;
    long len;
    char *array;

    // creates backup for reassignment;
    static void copy(String* self){
        self->backup = new char[self->len];
        for(long i = 0; i <= self->len; i++){
            self->backup[i] = self->array[i];
        }
    }
    public:
    

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

    void reassign(const char* str){
        len = String::length(str);
        String::copy(this);
        delete(array);
        array = new char[len];
        for(long i = 0; i <= len; i++){
            array[i] = str[i];
        }
        delete(backup);
    }

    void change_char(int index, char c){
        if (index < 0 || index > len)
        {
            std::invalid_argument("Index out of range\n");
        }
        array[index] = c;
    }

    void operator=(const char* str){
        reassign(str);
    }
    void operator=(const String* str){
        reassign(str->array);
    }
    void operator=(const String str){
        reassign(str.array);
    }
    void operator+=(const char* str){
        append(str);
    }
    void operator+=(const String& str){
        append(str.array);
    }
    void operator+=(const String* str){
        append(str->array);
    }
    void operator+=(const char c){
        append(&c);
    }

    char operator[](int index){
        if (index < 0 || index > len)
        {
            std::invalid_argument("Index out of range\n");
        }
        return array[index];
        
    }

    long get_length(){
        return len;
    }

    void print(){
        for(long i = 0; i < len; i++){
            putchar(array[i]);
        }
    }

    const char* get_array(){
        return array;
    }

    void append(const char* added_str){
        long added_len = String::length(added_str);
        String::copy(this);
        delete(array);
        array = new char[len+added_len];
        for(long i = 0; i <= len; i++){
            array[i] = backup[i];
        }
        for(long i = 0; i <= added_len; i++){
            array[len+i] = added_str[i];
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
};

}
#endif