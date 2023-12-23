#include <stdexcept>
#include "copy.hpp"

#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

namespace greg{

// may allocate more memory than needed (increases the speed of push_back())
// push_back() is comparable to std::vector in terms of performance (in the same order of magnitude)


// Dy_Array is a dynamic array that can be used to store any type of data which has compile time known size
template <typename T>
class Dy_Array{
    private:
    int size;
    int length;
    T* backup;
    void create_backup(){
        backup = new T[length];
        greg::copy(array, array + length, backup);
    }
    public:
    T* array;
    
    int get_length(){
        return length;
    }
    int get_size(){
        return length * sizeof(T);
    }

    T& operator[](int index){
    if(index < 0 || index >= length){
        throw std::out_of_range("Index out of range");}
        return array[index];
    }

    void set_value_at(int index, T value){
        if(index < 0 || index >= length){
            throw std::out_of_range("Index out of range");}
        array[index] = value;
    }

    void remove_at(int index){
        if(index < 0 || index >= length){
            throw std::out_of_range("Index out of range");
        }
        size -= sizeof(T);
        create_backup();
        delete[] array;
        array = new T[size];
        greg::copy(backup, backup + index, array);
        for(int i = index; i < length - 1; i++){
            array[i] = backup[i + 1];
        }
        length--;
        delete[] backup;
    }

    void slice(int index1, int index2){
        if(index1 < 0 || index1 >= length || index2 < 0 || index2 >= length){
        throw std::out_of_range("Index out of range");
        }
        if(index1 > index2){
            throw std::invalid_argument("Index1 must be smaller than index2");
        }
        int size1 = index1 * sizeof(T);
        int size2 = (length - index2) * sizeof(T);
        T* array1 = new T[size1];

        T* array2 = new T[size2];
        greg::copy(array, array + index1, array1);
        greg::copy(array + index2, array + length, array2);
        delete[] array;
        array = new T[size1 + size2];
        greg::copy(array1, array1 + size1, array);
        greg::copy(array2, array2 + size2, array+index1);
        length -= index2 - index1;
    }

    void swap(int index1, int index2){
        if(index1 < 0 || index1 >= length || index2 < 0 || index2 >= length){
            throw std::out_of_range("Index out of range");
        }
        T temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
    void clear(){
        size = 0;
        length = 0;
        delete[] array;
        array = nullptr;
    }

    Dy_Array(){
        size = 0;
        length = 0;
        array = nullptr;
    }
    //
    void push_back(T value){
    if (size == length) {
        size = (size == 0) ? 1 : size * 2;
        T* backup = new T[size];
        greg::copy(array, array + length, backup);
        delete[] array;
        array = backup;
    }
    array[length] = value;
    ++length;
    }
};
}

#endif