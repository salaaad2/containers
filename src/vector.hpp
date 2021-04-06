#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include <iostream>

namespace ft {
    template < class T> class vector {
        public :
            typedef T value_type;
            typedef size_t size_type;

            explicit vector () {
                // TODO
                _size = 0;
                _capacity = 8;
            }

            explicit vector (size_type n,
                             const value_type& val = value_type()) {
                // TODO allocate 8 16 32 64
                _size = n;
                _capacity = (n << 2);
                _elements = new value_type[_capacity];
                for (size_type i = 0; i < _size; i++) { _elements[i] = val; }
            }

            // template <class InputIterator>
            // vector (InputIterator first, InputIterator last) {
            //     // TODO
            // }

            // vector (const vector &x) {
            //     // TODO
            // }
            //

            size_type capacity (void) {
                return (this->_capacity);
            }

            size_type size (void) {
                return (this->_size);
            }

        private :
            size_type _size;
            size_type _capacity;
            value_type * _elements;
    };
}

#endif // FT_VECTOR_H
