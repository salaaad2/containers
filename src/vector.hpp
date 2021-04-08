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

            ~vector() {
                if (_elements)
                {
                    delete [] _elements;
                }
            };

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
// resize & insert interlinked. cells. interlinked
// swap : std::swap
            void resize(size_type n, value_type val = value_type()) {
                size_type tmp = 0;

                if (n < _size) {
                    for (tmp = _size; tmp > n; tmp--) {
                        _elements[tmp] = val;
                    }
                }
                else if (n > _capacity || n > _size) {
                    while (_capacity < n) {
                        _capacity *= 2;
                    }
                    value_type * tmpel = new value_type[_capacity];
                    for (tmp = 0; tmp < size(); tmp++) {
                        tmpel[tmp] = _elements[tmp];
                    }
                    for (; tmp < n; tmp++) {
                        tmpel[tmp] = val;
                    }
                    delete [] _elements;
                    _elements = tmpel;
                }
            }
// todo one from these two
            void insert (iterator position, size_type n, const value_type &val) {
                iterator tmp = begin();
                size_type spos = 0;

                while (tmp != position) {
                    tmp++;
                    spos++;
                }
                spos += (spos == 0) ? 0 : 1;
                if ((_size + n) >= _capacity) {
                    resize(_capacity * 2);
                }
                value_type * tmpel = new value_type[_capacity];
                for (size_type i = 0; i < size(); i++) {
                    tmpel[i] = _elements[i];

                }
                std::cout << "[spos]" << spos << std::endl;
                for (size_type i = spos; i < n; i++) {
                    tmpel[i] = val;
                }
                size_type j = spos;
                for (size_type i = spos + n; i < (size() + n); i++) {
                    tmpel[i] = _elements[j];
                    j++;
                }
                _elements = tmpel;
                _size += n;
            }

            iterator insert (iterator position, const value_type &val) {
                iterator tmp = begin();
                size_type spos = 0;

                while (tmp != position) {
                    tmp++;
                    spos++;
                }
                spos += (spos == 0) ? 0 : 1;
                if (_size >= _capacity) {
                    resize(_capacity * 2);
                }
// copy, then push everything after [pos]
                value_type * tmpel = new value_type[_capacity];
                for (size_type i = 0; i < size(); i++) {
                    tmpel[i] = _elements[i];
                }
                for (size_type i = spos + 1; i < (size() + 1); i++) {
                    tmpel[i] = _elements[i - 1];
                }
                tmpel[spos] = val;
                _elements = tmpel;
                _size++;
                return (position++);
            }

            value_type const & at(size_type n) const
            { if (n > _size)
              { throw out_of_range(); }
              return (_elements[n]); }

            value_type & at(size_type n)
            { if (n > _size)
              { throw out_of_range(); }
              return (_elements[n]); }

            value_type & front()
            {return (_elements[0]); }

            value_type & back()
            {return (_elements[_size]); }

            value_type * & data()
            {return (_elements); }

            value_type const & front() const
            {return (_elements[0]); }

            value_type const & back() const
            {return (_elements[_size]); }

            value_type const * & data() const
            {return (_elements); }

            size_type capacity (void) const
            { return (this->_capacity); }

            size_type size (void) const
            { return (this->_size); }

// iterators
            iterator begin()
            { return _elements; }

            iterator end()
            { return _elements + (_size - 1); }

// exceptions TODO true out of range is explicit. get back on that one
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
                _elements[i] = *first;
            }
    };
}

#endif // FT_VECTOR_H
