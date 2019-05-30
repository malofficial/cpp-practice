#include <type_traits>
#include <iostream>
#include <string>

// https://stackoverflow.com/questions/3082113/calculating-factorial-using-template-meta-programming

template <int N = 1, typename T = void>
struct Factorial 
{
    enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0> 
{
    enum { value = 1 };
};

template<typename Integer, 
 std::enable_if_t<std::is_integral<Integer>::value, int> Num = 12>
void fact2(Integer&& n) {
    std::cout << typeid(Integer).name() << "::" << n << std::endl;
    std::cout << typeid(Num).name() << "::" << Num <<  std::endl;
}


template<typename Integer, 
 std::enable_if_t<std::is_integral<Integer>::value || std::is_floating_point<Integer>::value, int> Num = 12>
void fact3(Integer&& n) {
    std::cout << typeid(Integer).name() << "::" << n << std::endl;
    std::cout << typeid(Num).name() << "::" << Num <<  std::endl;
}


struct T {
    enum { int_t,float_t } m_type;
    template <typename Integer,
              typename std::enable_if_t<std::is_integral<Integer>::value, int> = 0
    >
    T(Integer) : m_type(int_t) {}
 
    template <typename Floating,
              typename std::enable_if_t<std::is_floating_point<Floating>::value, int> = 0
    >
    T(Floating) : m_type(float_t) {} // OK
};


constexpr int fact(const int N) {
    return ((N == 1) ? 1 : N* fact(N-1));
}

// Factorial<4>::value == 24
// Factorial<0>::value == 1
void foo()
{
    int x = Factorial<4>::value; // == 24
    int y = Factorial<0>::value; // == 1
}


int main(int argc, char* argv[]) {
    int x = Factorial<4>::value; // == 24
    std::cout << x << std::endl;
    int y = Factorial<0>::value; // == 1
    std::cout << y << std::endl;

    std::cout << Factorial<>::value << std::endl;
    std::cout << fact(4) << std::endl;

    fact2(10) ;
    fact2(true) ;
    fact2('a') ;
    fact2<decltype('a'),100>('a') ;
    fact2<bool,100>('B') ;

    // error
    // fact2(11.);
    
    fact3(11.);
    fact3<decltype(11.),100>(11.) ;

}