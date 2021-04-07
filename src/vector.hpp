#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include <iostream>

#include "random_access_iterator.hpp"

namespace ft {
    template <class T> class vector {
        public :
// typedefs
            typedef T value_type;
            typedef size_t size_type;
            typedef random_access_iterator<value_type> iterator;

// constructors TODO destructor
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

            ~vector() { };

// operators
            vector & operator=(vector const & x) {
                _capacity = x.capacity();
                _size = x.size();
                _elements = new value_type[_size];
                for (size_type i = 0; i < _size; i++) {_elements[i] = x[i];}
                return *this;
            }

            value_type const & operator[](size_type n) const
            { if (n > _size)
              { throw out_of_range(); }
              return (_elements[n]); }

            value_type & operator[](size_type n)
            { if (n > _size)
              { throw out_of_range(); }
              return (_elements[n]); }

// member functions TODO: insert remove etc
            value_type const & at(size_type n) const
            { if (n > _size)
              { throw out_of_range(); }
              return (_elements[n]); }

            value_type & at(size_type n)
            { if (n > _size)
              { throw out_of_range(); }
              return (_elements[n]); }

            size_type capacity (void) const
            { return (this->_capacity); }

            size_type size (void) const
            { return (this->_size); }

// iterators
            iterator begin()
            { return _elements; }

            iterator end()
            { return _elements + (_size - 1); }

// exceptions TODO out of range is explicit. get back on that one
            class out_of_range : public std::exception {
                public :
                    virtual const char * what() const throw() {
                        return ("ft::vector: out of range");
                    }
            };

        private :
// attributes
            size_type _size;
            size_type _capacity;
            value_type * _elements;
// stuff TODO finish what you started. maybe add versatility for insert ?
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

            void fill_vect(iterator first, iterator last) {
                iterator tmp = first;

                while (tmp != last) {
                    _size++;
                    tmp++;
                }
                _size += 1;
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
