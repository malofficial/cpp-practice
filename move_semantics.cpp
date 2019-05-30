#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

class Vector : public std::vector<double> { 
public :
    Vector(std::initializer_list<double> il) : std::vector<double>(il) {}
    // Vector() = delete;
    Vector(const Vector& rhs) : std::vector<double>(rhs) {}
    // Vector& operator=(const Vector&) = delete;

    
    
};


int main(int argc, char* argv[]) {

    Vector myVec1 {1,2,3,4,5};
    Vector myVec2{myVec1};
    //Vector myVec3;

    //myVec3 = myVec1;
    //myVec2 = myVec1;
    myVec2 = std::move(myVec1);

    for(const auto& x: myVec1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    myVec1[0] = 10;

    for(const auto& x: myVec2) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}