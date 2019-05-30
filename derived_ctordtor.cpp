#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

class Base {
public:
    Base(int data) : basedata(data) {
        std::cout << "Base::ctor(): " << std::hex << this <<  std::endl;
     }

    Base(const Base& src) : basedata(src.basedata) {
        std::cout << "Base::Base(const Base&): " <<  this << std::endl;
    }

    void printdata() {
        std::cout << "basedata: " << basedata << "\t this: " << this  <<  std::endl;
    }
    
    ~Base() {
        std::cout << "~Base::dtor()" << this <<  std::endl;
    }

private:
    int basedata;
};

class Derived : public Base {
public:
    Derived(int data) : Base(data) { 
        std::cout << "Derived::ctor(): " << this <<  std::endl;
    }

    Derived(const Derived& d) : Base(d) {
        std::cout << "Derived::Derived(const Derived&): " << this <<  std::endl;
    }

    Derived& operator=(const Derived& rhs) {
        std::cout << "Derived& operator=(const Derived& rhs): " << this <<  std::endl;
        Base::operator=(rhs);
        return *this;
    }

    void printdata() {
        std::cout << "basedata:  this: " << this  <<  std::endl;
        Base::printdata();        
    }

    ~Derived() {
         std::cout << "~Derived::dtor(): " << this <<  std::endl;
    }
};

int main(int argc, char* argv[]) {

    Base b1{1};
    Derived d1{2};
    Derived d2 = d1;
    Derived d3 {3};
    d2 = d3;
    d2 = std::move(d3);
    d3.printdata();
    d2.printdata();
}
