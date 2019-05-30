#include <iostream>
#include <string>
#include <type_traits>

void overloaded( int const &arg ) { 
    std::cout << "by lvalue\n"; 
    std::cout << std::is_lvalue_reference<decltype(arg)>{} << std::endl;
    }
void overloaded( int && arg ) { std::cout << "by rvalue\n"; }
 
template< typename t >
/* "t &&" with "t" being template param is special, and  adjusts "t" to be
   (for example) "int &" or non-ref "int" so std::forward knows what to do. */
void forwarding( t && arg ) {

    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::boolalpha << std::is_lvalue_reference<decltype(arg)>{} << std::endl;
    std::cout << typeid(std::is_lvalue_reference<decltype(arg)>{}).name() << std::endl;
    std::cout << std::boolalpha << std::is_lvalue_reference_v<decltype(arg)> << std::endl;
    std::cout << typeid(std::is_lvalue_reference_v<decltype(arg)>).name() << std::endl;

    std::cout << std::is_reference<decltype(arg)>{} << std::endl;
    std::cout << std::is_rvalue_reference<decltype(arg)>{} << std::endl;

    std::cout << "via std::forward: ";
    overloaded( std::forward< t >( arg ) );
    std::cout << "via std::move: ";
    overloaded( std::move( arg ) ); // conceptually this would invalidate arg
    std::cout << "by simple passing: ";
    overloaded( arg );
}
 
int main(int argc, char* argv[]) {
    std::cout << "initial caller passes rvalue:\n";
    forwarding( 5 );
    std::cout << "initial caller passes lvalue:\n";
    int x = 5;
    forwarding( x );
    forwarding( std::move(x) );
}