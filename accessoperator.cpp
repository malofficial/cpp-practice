// https://en.cppreference.com/w/cpp/language/operator_member_access#Built-in_member_access_operators

#include <iostream>
 
int f() { return 42; }

void f(int) {}
void f(double) {}
struct A { int i; };
struct B { void f() {} };


int main(int argc, char* argv[]) {
{
    {
        int a[4] = {1, 2, 3, 4};
        int* p = &a[2];
        std::cout << p[1] << p[-1] << 1[p] << (-1)[p] << '\n';
    }

    {
        int n = 1;
        int* pn = &n;
    
        int& r = *pn;  // lvalue can be bound to a reference
        int m = *pn;   // indirection + lvalue-to-rvalue conversion
    
        int (*fp)() = &f;
        int (&fr)() = *fp; // function lvalue can be bound to a reference 
    }
    {
        int n = 1;
        int* pn = &n; // pointer
        int* pn2 = &*pn; // pn2 == pn
        int A::* mp = &A::i; // pointer to data member
        void (B::*mpf)() = &B::f; // pointer to member function
    
        void (*pf)(int) = &f; // overload resolution due to initialization context
    //  auto pf2 = &f; // error: ambiguous overloaded function type
        auto pf2 = static_cast<void (*)(int)>(&f); // overload resolution due to cast
    }



}