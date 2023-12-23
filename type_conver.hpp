#ifndef TYPE_CONVER_HPP
#define TYPE_CONVER_HPP

const char* to_charptr(long value){
    char* str = new char[sizeof(value)*8];
    if(value < 0){
        str[0] = '-';
        value *= -1;
    }
    

    
    return str;
}


#endif