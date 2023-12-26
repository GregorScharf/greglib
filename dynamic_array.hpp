#include "copy.hpp"
#include "execptions.hpp"

#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

namespace greg{

// push_back may allocate more memory than needed to avoid allocating memory every time a new element is added
// otherwise it would be too slow for more than 1mio elements

// Dy_Array is a dynamic array that can be used to store any type of data which has compile time known size
template <typename T>
class Dy_Array{
    private:
    int allocator_size;
    int length;
    T* backup;
    void create_backup(){
        backup = new T[length];
        greg::copy(array, array + length, backup);
    }
    public:
    T* array;

    T* get_array(){
        return array;
    }
    
    int get_length(){
        return length;
    }
    int get_size(){
        return length * sizeof(T);
    }
    long get_allocated_size(){
        return allocator_size;
    }

    T& operator[](int index){
    if(index < 0 || index >= length){
        greg::out_of_range();
    }
        return array[index];
    }

    void set_value_at(int index, T value){
        if(index < 0 || index >= length){
            greg::out_of_range();
        }

        array[index] = value;
    }
    // TODO: figure faster way to do this
    void insert_sort(){
        for(int i = 0; i < length; i++){
            T sort_value = array[i];
            int j = i;
            while(j > 0 && array[j - 1] > sort_value){
                array[j] = array[j - 1];
                j--;
            }
            array[j] = sort_value;
        }
    }

    void remove_at(int index){
        if(index < 0 || index >= length){
            greg::out_of_range();
        }
        allocator_size -= sizeof(T);
        create_backup();
        delete[] array;
        array = new T[allocator_size];
        greg::copy(backup, backup + index, array);
        for(int i = index; i < length - 1; i++){
            array[i] = backup[i + 1];
        }
        length--;
        delete[] backup;
    }

    void slice(int index1, int index2){
        if(index1 < 0 || index1 >= length || index2 < 0 || index2 >= length){
            greg::out_of_range();
        }
        if(index1 > index2){
            greg::invalid_argument();
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
            greg::out_of_range();
        }
        T temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
    void clear(){
        allocator_size = 0;
        length = 0;
        delete[] array;
        array = nullptr;
    }

    Dy_Array(){
        allocator_size = 0;
        length = 0;
        array = nullptr;
    }
    
    // this was the most shizophrenic i've ever been while coding
    void push_back(T value){
    if(allocator_size == length) {
        allocator_size = (allocator_size == 0) ? 1 : allocator_size * 2;
        T* backup = new T[allocator_size];
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