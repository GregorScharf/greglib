#include <sys/syscall.h>
#include <unistd.h>
#include <fcntl.h>
#include "out.hpp"
#include "String.hpp"


#ifndef IN_HPP
#define IN_HPP

namespace greg{

    greg::String read_line(){
        greg::String line;
        const int buffer_size = 1024;
        char buffer[buffer_size];
        int length = syscall(SYS_read, 0, buffer, buffer_size);
        if(length == -1){
            greg::costum_error("Error while reading from the Std Input file descriptor");
        }
        if(buffer[length] != '\0'){
            greg::costum_error("Buffer overflow");
        }
        buffer[length] = '\0';
        line = buffer;
        return line;
    }
}

#endif 