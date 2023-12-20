#include <cstdint>

#ifndef DYNAMIC_ARRAY_HPP
#define DYANMIC_ARRAY_HPP

namespace greg{


// Warning: this is not safe, it is meant for me as an excersize to learn how to free/delete in c++

// Dy_Array is a dynamic array that can be used to store any type of data which has compile time known size
template <typename T>
class Dy_Array{
    T* backup;
    static void copy(Dy_Array* self){
        self->backup = new T[self->length];
        for(int i = 0; i < self->length; i++){
            self->backup[i] = self->array[i];
        }
    }
    public:
    T* array;
    int size; // size of the entire array in bytes
    int length; // amount of elements in the array
    Dy_Array(){
        size = 0;
        length = 0;
        array = nullptr;
    }
    void push_back(T value){
        size += sizeof(T);
        Dy_Array::copy(this);
        array = new T[size];
        for(int i = 0; i < length; i++){
            array[i] = backup[i];
        }
        array[length] = value;
        length++;
        delete[] backup;
    }

};
}

#endif