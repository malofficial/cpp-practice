#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <thread>
#include <array>

enum class Traffic { red, yellow, green};
enum  Warning { red, green, yellow};



Traffic& operator++(Traffic& tf)    {
    switch (tf) 
    {
    case Traffic::red:      return tf = Traffic::yellow;
    case Traffic::green:    return tf = Traffic::red;
    case Traffic::yellow:   return tf = Traffic::green;
    default:
        break;
    }
}

Traffic operator++(Traffic& tf, int i)   {
    std::cout << "i=" << i << std::endl;
    return ++tf;
}

int main (int argc, char* argv[]) {

    if(int i = 1) {
        std::cout << "Inside sizeof(short): " << sizeof(short) << " sizeof(int):" << sizeof(i) << std::endl;
    }

    Traffic tf = Traffic::red;
    std::cout << static_cast<int>(tf) << std::endl;
    std::cout << static_cast<int>(++tf) << std::endl;
    std::cout << static_cast<int>(tf++) << std::endl;
}