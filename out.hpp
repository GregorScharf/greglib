#include <unistd.h>
#include <sys/syscall.h>
#include "type_conver.hpp"


#ifndef OUT_HPP
#define OUT_HPP

namespace greg{

void newline(){
    syscall(SYS_write, STDOUT_FILENO, "\n", 1);
}
int print(const char* str){
    syscall(SYS_write, STDOUT_FILENO, str, length(str));
    newline();
    return length(str);
}
int print(int num){
    char* str = long_to_char(num);
    syscall(SYS_write, STDOUT_FILENO, str, length(str));
    newline();
    return length(str);
}

int print(double num){
    char* str = double_to_char(num);
    syscall(SYS_write, STDOUT_FILENO, str, length(str));
    newline();
    return length(str);
}

int print(float num){
    char* str = float_to_char(num);
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