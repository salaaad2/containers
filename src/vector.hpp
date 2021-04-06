#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include <iostream>

#include "random_access_iterator.hpp"

namespace ft {
    template < class T> class vector {
        public :
            typedef T value_type;
            typedef size_t size_type;
            typedef random_access_iterator<value_type> iterator;

            explicit vector () {
                _size = 0;
                _capacity = 8;
                _elements = new value_type[_capacity];
                return ;
            }

            explicit vector (size_type n,
                             const value_type& val = value_type()) {
                fill_vect(n, val);
            }

            template <class InputIterator>
            vector (InputIterator first, InputIterator last) {
                fill_vect(first, last);
            }

            vector (const vector &x) {
                *this = x;
                return ;
            }

            vector & operator=(vector const & rhs) {
                _capacity = rhs.capacity();
                _size = rhs.size();
                _elements = new value_type[_size];
                for (size_type i = 0; i < _size; i++) {_elements[i] = rhs[i];}
                return *this;
            }

            value_type & operator[](size_type n) const
            { return (_elements[n]); }

            ~vector() {
                // TODO
            };

            size_type capacity (void) const
            { return (this->_capacity); }

            size_type size (void) const
            { return (this->_size); }

            iterator begin()
            { return _elements; }

            iterator end()
            { return _elements + (_size - 1); }

        private :
            size_type _size;
            size_type _capacity;
            value_type * _elements;

            void fill_vect (size_type n,
                    const value_type& val = value_type()) {
                _size = n;
                _capacity = 8;
                while (_capacity < _size)
                    _capacity *= 2;
                _elements = new value_type[_capacity];
                for (size_type i = 0; i < _size; i++) {
                    _elements[i] = val;
                }
                return ;
            }
// TODO finish what you started
            void fill_vect(iterator first, iterator last) {
                _size = 90;
                std::cout << _size << std::endl;
                _capacity = 8;
                while (_capacity < _size)
                    _capacity *= 2;
                _elements = new value_type[_capacity];
                size_type i = 0;
                while (first != last) {
                    _elements[i] = *first;
                    first++;
                    i++;
                }
            }
    };
}

#endif // FT_VECTOR_H
