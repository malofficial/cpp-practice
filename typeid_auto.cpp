#include <iostream>
#include <string>
#include <typeinfo>

int main(int argc, char* argv[])    {

    int i = {7};
    int j{7};
    auto k = {9};
    auto l{10};
    //auto m {10, 11};
    int v[]{1,2};
    auto d{2.3};
    //auto v2[]{3,4};
    std::cout << typeid(i).name() << std::endl;
    std::cout << typeid(j).name() << std::endl;
    std::cout << typeid(k).name() << std::endl;
    std::cout << typeid(l).name() << std::endl;
    std::cout << typeid(++l).name() << std::endl;
    std::cout << typeid(l++).name() << std::endl;
    std::cout << typeid(v).name() << std::endl;
    std::cout << typeid(d).name() << std::endl;
    const auto ptr = &++i;
    auto ptr2 = &++l;
    std::cout << typeid(ptr).name() << std::endl;
    std::cout << typeid(ptr2).name() << std::endl;
    std::cout << typeid(ptr2-ptr).name() << std::endl;
    ptrdiff_t pdiff = ptr2 - ptr;
    std::cout << typeid(pdiff).name() << std::endl;
    //std::cout << typeid(m).name() << std::endl;
}
