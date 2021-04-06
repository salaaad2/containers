#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include <iostream>

namespace ft {
    template < class T, class Alloc = std::allocator<T> > class vector {
        private :
            size_t _size;
        public :
            typedef Alloc allocator_type;
            typedef T value_type;


            explicit vector (const allocator_type& alloc = allocator_type());
            vector (const vector &x);
    };
}

#endif // FT_VECTOR_H
