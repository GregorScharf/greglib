#include <SDL2/SDL.h>
#include <fstream>
#include "String.hpp"
#include <cstdlib>


#ifndef FILEDATA_HPP
#define FILEDATA_HPP

namespace greg{


class FileData{
    public:
    int data_amount;
    std::ofstream file;
    greg::String name;
    greg::String content;
    FileData(int arg_amount,const char* file_name){    
        file.open(file_name);
        name.append(file_name);
        data_amount = arg_amount;
        file.close();
    }

    template<typename T>
    int Write(T *data){
        file.open(name.array);
        for (int i = 0; i < data_amount; i++){
            file << data[i] << "\n";
        }
        file.close();
        return 0;
    }

    
    greg::String Read(){
        FILE *file = fopen(name.array, "rb");
        if(file == nullptr){
            perror("Error opening file:");
            printf("%s \n", name.array);
        }

        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        rewind(file);
        content.array = new char[file_size +1];

        size_t read_size = fread(content.array, 1, file_size, file);

        if(read_size != file_size){
            perror("Error reading file");
            fclose(file);
            delete(content.array);
        }

        content.array[file_size] = '\0';
        content.set_length(greg::String::length(content.array)-1);
        fclose(file);
        return content;

    }

    ~FileData(){
        if(!file.is_open()){
            file.close();
        }
    }
};

}
#endif