#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

template<typename ... Types> struct TupleA {};
TupleA<> t0;           // Types contains no arguments
TupleA<int> t1;        // Types contains one argument: int
TupleA<int, float> t2; // Types contains two arguments: int and float
//Tuple<0> error;       // error: 0 is not a type


template<class ... Types> 
void f(Types ... args) {}


// template<typename... Ts, typename U> 
// struct Invalid; // Error: Ts.. not at the end

template<typename ...Ts, typename U, typename=void>
void valid(U, Ts...) {}    // OK: can deduce U
// void valid(Ts..., U);  // Can't be used: Ts... is a non-deduced context in this position

template<class ...Us> void f2(Us... pargs) {}
template<class ...Ts> void g2(Ts... args) {
    f2(&args...); // “&args...” is a pack expansion
                 // “&args” is its pattern
}

template<typename...> struct Tuple {};
template<typename T1, typename T2> struct Pair {};
 
template<class ...Args1> struct zip {
    template<class ...Args2> struct with {
        typedef Tuple<Pair<Args1, Args2>...> type;
//        Pair<Args1, Args2>... is the pack expansion
//        Pair<Args1, Args2> is the pattern
    };
};


typedef zip<short, int>::with<unsigned short, unsigned>::type T1;
// Pair<Args1, Args2>... expands to
// Pair<short, unsigned short>, Pair<int, unsigned int> 
// T1 is Tuple<Pair<short, unsigned short>, Pair<int, unsigned>>
 
//typedef zip<short>::with<unsigned short, unsigned>::type T2;
// error: pack expansion contains parameter packs of different lengths




template<typename T> 
void g1(T x) {
    std::cout << x << " "; 
}


// do nothing

void f1() {}

template<typename T, typename... Tail> 
void f1(T head, Tail... tail)
{
    g1(head); 
    f1(tail...);
    // do something to head // try again with tail
}


int main(int argc, char* argv[]) {

    f();       // OK: args contains no arguments
    f(1);      // OK: args contains one argument: int
    f(2, 1.0); // OK: args contains two arguments: int and double

    valid(1.0, 1, 2, 3);      // OK: deduces U as double, Ts as {int,int,int}

    g2(1, 0.2, "a"); // Ts... args expand to int E1, double E2, const char* E3
                // &args... expands to &E1, &E2, &E3
                // Us... pargs expand to int* E1, double* E2, const char** E3


    std::cout << "first: "; 
    f1(1,2.2,"hello");
    std::cout << "\nsecond: ";
    f1(0.2,'c',"yuck!",0,1,2); 
    std::cout << "\n";

}