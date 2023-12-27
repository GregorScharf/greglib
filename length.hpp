#ifndef LENGTH_HPP
#define LENGTH_HPP

long length(const char* str){
        long i = 0;
        while((str != 0) && (str[i] != '\0')){
            i++;
        }
        return i+1;
    }

#endif