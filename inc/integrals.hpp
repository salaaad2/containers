#ifndef __INTEGRALS_H_
#define __INTEGRALS_H_

namespace ft
{
    template<bool B>
        struct bool_type {
        static const bool value = B;
    };

    typedef bool_type<true> true_type;
    typedef bool_type<false> false_type;

    template<typename T>
        struct is_integral : false_type {};

    template<typename T>
        struct is_integral<const T> : is_integral<T> {};

    template<typename T>
        struct is_integral<volatile T> : is_integral<T> {};

    template<>
        struct is_integral<int> : true_type {};

    template<>
        struct is_integral<long> : true_type {};
}

#endif // __INTEGRALS_H_
