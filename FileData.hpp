#include <SDL2/SDL.h>
#include "String.hpp"
#include "file.hpp"
#include "type_conver.hpp"


#ifndef FILEDATA_HPP
#define FILEDATA_HPP

namespace greg{

// deprecated class, use File class and typeconversion functions instead

class FileData{
    public:
    int data_amount;
    File file;
    greg::String file_name;
    greg::String content;

    FileData(int arg_amount,const char* _name){    
        this->file_name = _name;
        file.open(file_name.get_charptr(), 0777);
        data_amount = arg_amount;
        file.close();
    }
    FileData(){
        data_amount = 0;
    }

    int Write(const char* str){
        file.open(file_name.get_ptr(), 0777);
        for (int i = 0; i < data_amount; i++){
            file.write(str);
        }
        file.close();
        return 0;
    }

    
    greg::String Read(){
        return file.read();
        

    }

    ~FileData(){
        if(!file.is_open()){
            file.close();
        }
    }
};

}
#endif