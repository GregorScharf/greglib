#include "out.hpp"

#ifndef EXECPTIONS_HPP
#define EXECPTIONS_HPP

namespace greg{

// these are basically just print functions, but who cares

void process_ended(){
    syscall(SYS_write, STDOUT_FILENO, "Process ended \n", 15);
}

void invalid_argument(){
    syscall(SYS_write, STDOUT_FILENO, "Argument passed does not match parameter to given function \n", 61);
    process_ended();
    syscall(SYS_exit, 1);
}
void out_of_range(){
    syscall(SYS_write, STDOUT_FILENO, "Index out of range \n", 21);
    process_ended();
    syscall(SYS_exit, 1);
}
void invalid_type(){
    syscall(SYS_write, STDOUT_FILENO, "Invalid type \n", 14);
    process_ended();
    syscall(SYS_exit, 1);
}

void costum_error(const char* error){
    syscall(SYS_write, STDOUT_FILENO, error, greg::length(error));
    process_ended();
    syscall(SYS_exit, 1);
    }
}

#endif