#include <SDL2/SDL.h>
#include <fstream>
#include "String.hpp"
#include <cstdlib>


#ifndef FILEDATA_HPP
#define FILEDATA_HPP

namespace greg{


// todo: figure out how to make this work without the need of <fstream> and <cstdlib>
// hopefully there is a way to do this with syscalls, else im fucked

class FileData{
    public:
    int data_amount;
    std::ofstream file;
    greg::String file_name;
    greg::String content;
    FileData(int arg_amount,const char* _name){    
        file.open(_name);
        file_name.append(_name);
        data_amount = arg_amount;
        file.close();
    }
    FileData(){
        data_amount = 0;
    }

    template<typename T>
    int Write(T *data){
        file.open(file_name.get_ptr(), std::ios::out);
        for (int i = 0; i < data_amount; i++){
            file << data[i] << "\n";
        }
        file.close();
        return 0;
    }

    
    greg::String Read(){
        FILE *file = fopen(file_name.get_ptr(), "rb");
        if(file == nullptr){
            perror("Error opening file:");
            printf("%s \n", file_name.get_ptr());
        }

        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        rewind(file);

        char *buffer = new char[file_size+1];
        size_t read_size = fread(buffer, 1, file_size, file);
        buffer[file_size] = '\0';

        if(read_size != file_size){
            perror("Error reading file");
            fclose(file);
        }
        content.reassign(buffer);

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