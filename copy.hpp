#ifndef COPY_HPP
#define COPY_HPP

namespace greg{

template<typename InputIterator, typename OutputIterator>
void copy(InputIterator first, InputIterator last, OutputIterator d_first)
{
    while (first != last) {
        *d_first++ = *first++;
    }
}
}

#endif