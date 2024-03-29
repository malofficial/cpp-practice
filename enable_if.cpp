#include <type_traits>
#include <iostream>
#include <string>

// https://en.cppreference.com/w/cpp/types/enable_if

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


namespace detail { struct inplace_t{}; }
void* operator new(std::size_t, void* p, detail::inplace_t) {
    return p;
}
 
// #1, enabled via the return type
template<class T,class... Args>
typename std::enable_if<std::is_trivially_constructible<T,Args&&...>::value>::type 
    construct(T* t,Args&&... args) 
{
    std::cout << "constructing trivially constructible T\n";
}
 
// #2
template<class T, class... Args>
std::enable_if_t<!std::is_trivially_constructible<T,Args&&...>::value> //Using helper type
    construct(T* t,Args&&... args) 
{
    std::cout << "constructing non-trivially constructible T\n";
    new(t, detail::inplace_t{}) T(args...);
}
 
// #3, enabled via a parameter
template<class T>
void destroy(
    T* t, 
    typename std::enable_if<
        std::is_trivially_destructible<T>::value
    >::type* = 0
){
    std::cout << "destroying trivially destructible T\n";
}
 
// #4, enabled via a template parameter
template<class T,
         typename std::enable_if<
             !std::is_trivially_destructible<T>{} &&
             (std::is_class<T>{} || std::is_union<T>{}),
            int>::type = 0>
void destroy(T* t)
{
    std::cout << "destroying non-trivially destructible T\n";
    t->~T();
}
 
// #5, enabled via a template parameter
template<class T,
	typename = std::enable_if_t<std::is_array<T>::value> >
void destroy(T* t) // note, function signature is unmodified
{
    for(std::size_t i = 0; i < std::extent<T>::value; ++i) {
        destroy((*t)[i]);
    }
}
/*
template<class T,
	typename = std::enable_if_t<std::is_void<T>::value> >
void destroy(T* t){} // error: has the same signature with #5
*/
 
// the partial specialization of A is enabled via a template parameter
template<class T, class Enable = void>
class A {}; // primary template
 
template<class T>
class A<T, typename std::enable_if<std::is_floating_point<T>::value>::type> {
}; // specialization for floating point types
 
int main()
{
    std::aligned_union_t<0,int,std::string> u;
 
    construct(reinterpret_cast<int*>(&u));
    destroy(reinterpret_cast<int*>(&u));
 
    construct(reinterpret_cast<std::string*>(&u),"Hello");
    destroy(reinterpret_cast<std::string*>(&u));
 
    A<int> a1; // OK, matches the primary template
    A<double> a2; // OK, matches the partial specialization
}