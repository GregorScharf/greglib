#ifndef COPY_HPP
#define COPY_HPP

namespace greg{

template<typename InputIt, typename OutputIt>
void copy(InputIt first, InputIt last, OutputIt d_first)
{
    while (first != last) {
        *d_first++ = *first++;
    }
}
}

#endif