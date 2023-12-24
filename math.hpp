#ifndef MATH_HPP
#define MATH_HPP

namespace greg{

double round(double value, int precision){
    if(precision == 0){
        return value;
    }
    else{
        if(precision < 0){
            precision *= -1;
            double factor = 1;
            for(int i = 0; i < precision; i++){
                factor *= 10;
            }
            return (int)(value/factor)*factor;
        }
        if(precision > 0){
            double factor = 1;
            for(int i = 0; i < precision; i++){
                factor *= 10;
            }
            return (int)(value*factor)/factor;
        }
    }
    return -1;

}
}

#endif