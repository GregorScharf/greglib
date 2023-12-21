#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

namespace greg{


// Warning: this is not safe, it is meant for me as an excersize to learn how to free/delete in c++

// Dy_Array is a dynamic array that can be used to store any type of data which has compile time known size
template <typename T>
class Dy_Array{
    private:
    int size;
    int length;
    T* backup;
    static void create_backup(Dy_Array* self){
        self->backup = new T[self->length];
        for(int i = 0; i < self->length; i++){
            self->backup[i] = self->array[i];
        }
    }
    public:
    T* array;
    
    int get_length(){
        return length;
    }
    int get_size(){
        return size;
    }

    T& operator[](int index){
        if(index < 0 || index >= length){
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    void set_value_at(int index, T value){
        if(index < 0 || index >= length){
            throw std::out_of_range("Index out of range");
        }
        array[index] = value;
    }

    void remove_at(int index){
        if(index < 0 || index >= length){
            throw std::out_of_range("Index out of range");
        }
        size -= sizeof(T);
        Dy_Array::create_backup(this);
        array = new T[size];
        for(int i = 0; i < index; i++){
            array[i] = backup[i];
        }
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
        size -= sizeof(T) * (index2 - index1);
        Dy_Array::create_backup(this);
        array = new T[size];
        for(int i = 0; i < index1; i++){
            array[i] = backup[i];
        }
        for(int i = index1; i < length - (index2 - index1); i++){
            array[i] = backup[i + (index2 - index1)];
        }
        length -= (index2 - index1);
        delete[] backup;
    }

    void swap(int index1, int index2){
        if(index1 < 0 || index1 >= length || index2 < 0 || index2 >= length){
            throw std::out_of_range("Index out of range");
        }
        T temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    Dy_Array(){
        size = 0;
        length = 0;
        array = nullptr;
    }
    void push_back(T value){
        size += sizeof(T);
        Dy_Array::create_backup(this);
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