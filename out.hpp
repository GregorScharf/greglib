#include <unistd.h>
#include <sys/syscall.h>


#ifndef OUT_HPP
#define OUT_HPP

namespace greg{

long length(const char* str){
    long i = 0;
    while((str != NULL) && (str[i] != '\0')){
        i++;
    }
    return i+1;
}


void newline(){
    syscall(SYS_write, STDOUT_FILENO, "\n", 1);
}
int print(const char* str){
    syscall(SYS_write, STDOUT_FILENO, str, length(str));
    newline();
    return length(str);
}
int putchar(const char c){
    syscall(SYS_write, STDOUT_FILENO, &c, 1);
    return 1;
}

}

#endif