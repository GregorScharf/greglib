##        GregLib      ##

An "Attempt" at writing a working standard library in C++

This accommodates all of the bad practices i have gotten used to while learning C++.

Only works in Linux at the moment. Windows support may never be added.

The SDL Directory contains a few wrappers and prewritten code, so i don't have to rewrite it when i need it.

all.hpp is a simple header to glue everything together.

dynamic_array.hpp contains a class for dynamically sized arrays similar to std::vector.

String.hpp is a wrapper around a dynamic array to make strings easier/safer to work with

files.hpp allows you to write char* into files and read them from the file

copy.hpp contains a function for copying arrays into other arrays at high performance

char_to_num.hpp is a function that was made to work together with Filedata.hpp, to convert the String from the format in which it was read to numbers


