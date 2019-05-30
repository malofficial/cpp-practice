#include <iostream>
#include <string>
#include <typeinfo>

int main(int argc, char* argv[])    {
    //char * str = "Hello";
    const char *str = "Hello";
    char str2[] = "Hello";
    str2[1] = 'E';
    std::cout << str << " : " << sizeof(str) << std::endl;
    std::cout << str2 << " : " << sizeof(str2) << std::endl;
    std::cout << "sizeof(int)" << sizeof(int) << std::endl;
    std::cout << "sizeof(int*)" << sizeof(int*) << std::endl;
    static_assert(sizeof(int) >= 4, "Int is less than 4 bytes");
}
