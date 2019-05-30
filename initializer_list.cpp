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


class Container {
public:
    virtual double& operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
};



class Vector_container : public Container { // Vector_container implements Container
    std::vector<double> v;
public:
    Vector_container(int s) : v(s) { }
    Vector_container(std::initializer_list<double> il) : v{il} { }
    ~Vector_container() {}
    double& operator[](int i) { return v[i]; }
    int size() const { return v.size(); }
};

int main(int argc, char* argv[]) {
    std::cout << "Hello World" << std::endl;

    Vector_container v {1,2};
    std::cout << "Hello World2" << std::endl;
}
