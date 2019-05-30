#include <iostream>
#include <string>
#include <type_traits>



int main(int argc, char* argv[]) {

    std::integral_constant<int, 5> five;
    std::cout << five.value << std::endl;
    std::cout << five << std::endl;
    std::cout << five() << std::endl;
    std::cout << five.operator()() << std::endl;
    std::cout << five.operator int() << std::endl;

    // error
    //std::integral_constant<int, 5.1> five1;
    int five1 = 5.1;

    std::bool_constant<true> bTrue;
    std::bool_constant<false> bFalse;

    std::cout << bTrue << std::endl;
    std::cout << bTrue.value << std::endl;
    std::cout << bFalse << std::endl;
    std::cout << (bTrue == bFalse) << std::endl;
    std::cout << (bTrue != bFalse) << std::endl;

    std::negation<decltype(bTrue)> nTrue;
    std::negation<decltype(bFalse)> nFalse;
    std::cout << "nTrue: " << nTrue << std::endl;
    std::cout << "nFalse: " << nFalse << std::endl;

    std::conjunction<decltype(nTrue)> conjunction1;
    std::conjunction<decltype(bTrue)> conjunction2;
    std::conjunction<> conjunction3;
    std::cout << "conjunction1: " << conjunction1 << std::endl;
    std::cout << "conjunction2: " << conjunction2 << std::endl;
    std::cout << "conjunction3: " << conjunction3 << std::endl;

    std::disjunction<decltype(nTrue)> disjunction1;
    std::disjunction<decltype(bTrue)> disjunction2;
    std::disjunction<> disjunction3;
    std::cout << "disjunction1: " << disjunction1 << std::endl;
    std::cout << "disjunction2: " << disjunction2 << std::endl;
    std::cout << "disjunction3: " << disjunction3 << std::endl;


    typedef std::conditional<true, int, double>::type Type1;
    typedef std::conditional<false, int, double>::type Type2;
    typedef std::conditional<sizeof(int) >= sizeof(double), int, double>::type Type3;
 
    std::cout << typeid(Type1).name() << '\n';
    std::cout << typeid(Type2).name() << '\n';
    std::cout << typeid(Type3).name() << '\n';

    std::integral_constant<int, 5> fiveN;
    std::integral_constant<int, 6> six;
    // Non type parameter cannot be non integral
    //std::integral_constant<double, 5.2> five2;
    std::integral_constant<int, 0> zero;

    std::conjunction<decltype(zero), decltype(fiveN)> conjunction4;
    std::cout << "conjunction4: " << conjunction4 << std::endl;
    std::cout << "type(conjunction4): " << typeid(conjunction4).name() << std::endl;

    std::conjunction<decltype(six), decltype(fiveN)> conjunction5;
    std::cout << "conjunction5: " << conjunction5 << std::endl;
    std::cout << "type(conjunction5): " << typeid(conjunction5).name() << std::endl;


}