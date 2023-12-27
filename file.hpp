#include <sys/syscall.h>
#include <unistd.h>
#include "out.hpp"
#include "execptions.hpp"
#include <sys/stat.h>
#include "String.hpp"
#include <fcntl.h>

#ifndef FILE_HPP
#define FILE_HPP


namespace greg{

class File{
    private:
    bool _open;
    int fd; // file descriptor
    long content_len;
    greg::String path;
    public:

    File(){
        fd = -1;
        _open = false;
        content_len = 0;
    }
    // only call once and only if you used the default constructor
    void set_path(const char* _path){
        path = _path;

    }
    void open(const char* _path, int mode){
        fd = syscall(SYS_open, _path, O_RDWR | O_CREAT, mode);
        if(fd == -1){
            greg::costum_error("File could not be opened \n");
        }
        _open = true;
    }
    void close(){
        syscall(SYS_close, fd);
        _open = false;
    }

    File(const char* path, int mode){
        fd = syscall(SYS_open, path, O_RDWR | O_CREAT, mode);
        _open = true;
        if(fd == -1){
            greg::costum_error("File could not be opened \n");
        }
        this->path = path;
        content_len = 0;
        close();
    }
    
    int write(const char* str){
        open(path.get_ptr(), 0777);
        content_len = greg::length(str);
        syscall(SYS_write, fd, str, content_len);
        if(fd == -1){
            greg::costum_error("File could not be written \n");
        }
        close();
        return 0;

    }

    const char* read(){
        open(path.get_ptr(), 0777);
        struct stat st;
        syscall(SYS_fstat, fd, &st);
        content_len = st.st_size-1;
        char* buffer = new char[content_len];
        syscall(SYS_lseek, fd, 0, SEEK_SET);
        int read_bytes = syscall(SYS_read, fd, buffer, content_len);
        if(read_bytes == -1){
            greg::costum_error("File could not be read \n");
        }
        close();
        return buffer;
    }

    bool is_open(){
        return _open;
    }

    int get_fd(){
        return fd;
    }

    ~File(){
        syscall(SYS_close, fd);
    }

};

}

#endif