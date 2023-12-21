#include <vector>

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

namespace greg{


auto range(double a, double b){
    if (a-b<0)
    {
        return b-a;
    }
    else{
        return a-b;
    }
}

}
#endif