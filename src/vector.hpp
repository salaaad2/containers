#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include <iostream>
#include <type_traits>

#include <math.h>

#include "random_access_iterator.hpp"
#include "reverse_random_access_iterator.hpp"

namespace ft {
    template <class T> class vector {
        public :
// typedefs
            typedef T value_type;
            typedef size_t size_type;
            typedef random_access_iterator<value_type> iterator;
            typedef reverse_random_access_iterator<value_type> reverse_iterator;
// TODO: reverse it typedef/implementation

// TODO: good destructor
            explicit vector () :
                _elements(NULL), _size(0), _capacity(0) {
                return ;
            }

            explicit vector (size_type n,
                             const value_type& val = value_type()) {
                fill_vect(n, val, std::true_type());
            }

            template <class InputIterator>
            vector (InputIterator first,
                    InputIterator last) :
            _elements(NULL), _size(0), _capacity(0){
                typedef typename std::is_integral<InputIterator>::type Integral;

                fill_vect(first, last, Integral());
            }

            vector (const vector &x) :
                _elements(NULL), _size(0), _capacity(0) {
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

// member functions TODO: insert / resize better conditions
            void swap (vector & x) {
                std::swap(_elements, x._elements);
                std::swap(_size, x._size);
                std::swap(_capacity, x._capacity);
                std::swap(_it, x._it);
            }

            void reserve(size_type n) {
                size_type tmp;
                if (n > _capacity) {
                    _capacity = n;
                    value_type * tmpel = new value_type[_capacity];
                    for (tmp = 0; tmp < size(); tmp++) {
                        tmpel[tmp] = _elements[tmp];
                    }
                    delete [] _elements;
                    _elements = tmpel;
                    _capacity = n;
                }
            }

            void resize(size_type n,
                        value_type val = value_type()) {
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
                    _it.setPtr(_elements);
                }
            }

            template <class InputIterator>
            void assign (InputIterator first, InputIterator last) {
                typedef typename std::is_integral<InputIterator>::type Integral;

                fill_vect(first, last, Integral());
            }

            void assign(size_type n,
                        const value_type & val) {
                delete [] _elements;
                fill_vect(n, val, std::true_type());
            }

            void _insert(iterator & position,
                         size_type n,
                         const value_type val = value_type()) {
                iterator tmp = begin();
                size_type spos = 0;
                size_type olds = size();
                value_type * tmpel;
                value_type * copy = new value_type[_capacity];

                while (tmp != position) {
                    tmp++;
                    spos++;
                }
                if ((_size + n) > _capacity) {
                    resize(_capacity * 2);
                    tmpel = new value_type[_capacity];
                }
                else
                    tmpel = _elements;
                for (size_type i = 0; i < size(); i++) {
                    tmpel[i] = _elements[i];
                    copy[i] = _elements[i];
                }
                for (size_type i = spos; i < (spos + n); i++) {
                    tmpel[i] = val;
                }
                size_type j = spos;
                for (size_type i = spos + n; j < (olds); i++) {
                    tmpel[i] = copy[j];
                    j++;
                }
                if (_elements != tmpel)
                {
                    delete [] _elements;
                    _elements = tmpel;
                }
                _size += n;
                _it.setPtr(_elements);
                position = _it;
            }

            iterator insert (iterator position,
                             const value_type &val = value_type()) {
                _insert_dispatch(position, 1, val, std::true_type());
                return (position);
            }

            void insert (iterator position,
                             size_type n,
                             const value_type &val = value_type()) {
                _insert_dispatch(position, n, val, std::true_type());
            }

            template <class InputIterator>
            void insert(iterator position,
                        InputIterator first,
                        InputIterator last) {
                typedef typename std::is_integral<InputIterator>::type Integral;

                _insert_dispatch(position, first, last, Integral());
            }

            void _insert_dispatch(iterator position,
                             size_type n,
                             const value_type &val,
                             std::true_type) {
                _insert(position, n, val);
            }

            template<class InputIterator>
            void _insert_dispatch(iterator position,
                                    InputIterator first,
                                    InputIterator last,
                                  std::false_type) {
                InputIterator tmp = first;

                while (tmp != last) {
                    _insert(position, 1, *tmp);
                    tmp++;
                    position++;
                }
            }

            iterator _erase(iterator position,
                            size_type n) {
                iterator tmp = begin();
                size_type spos = 0;
                size_type j = 0;

                while (tmp != position) {
                    tmp++;
                    spos++;
                }
                size_type i = 0;
                while (i < size()) {
                    if (j != spos)
                    {
                        _elements[i] = _elements[j];
                        j++;
                        i++;
                    }
                    else
                    {
                        j += n;
                    }
                }
                _size -= n;
                _it.setPtr(_elements);
                return (position);
            }

            iterator erase (iterator first,
                            iterator last) {
                iterator tmp = first;
                size_type n = 0;

                while (tmp != last) {
                    tmp++;
                    n++;
                }
                return(_erase(first, n));
            }

            iterator erase (iterator position) {
                return (_erase(position, 1));
            }

            void clear() {
                for (size_type i = 0; i < size(); i++) {
                    _elements[i] = ~_elements[i];
                }
                _size = 0;
            }

            void push_back(const value_type & val = value_type()) {
                insert(end(), val);
            }

            void pop_back() {
                _erase(end(), 1);
            }

// accessors
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

            value_type const & front() const
            {return (_elements[0]); }

            value_type const & back() const
            {return (_elements[_size]); }

            value_type const * & data() const
            {return (_elements); }

            size_type capacity (void) const
            { return (this->_capacity); }

            size_type max_size (void) const
            { return (pow(2, sizeof(void *) * 8) / sizeof(ft::vector<T>) - 1);}

            size_type size (void) const
            { return (this->_size); }

            bool empty (void) const
            { return (this->_size == 0); }

// iterators
            iterator begin()
            { return _elements; }

            iterator end()
            { return _elements + _size; }


            reverse_iterator rbegin()
            { return reverse_iterator(end() - 1); }

            reverse_iterator rend()
            { return reverse_iterator(begin() - 1); }

// exceptions TODO true out of range is explicit. get back on that one
            class out_of_range : public std::exception {
                public :
                    virtual const char * what() const throw() {
                        return ("ft::vector: out of range");
                    }
            };

        private :
// attributes
            iterator _it;
            value_type * _elements;
            size_type _size;
            size_type _capacity;
// constructor helpers
            void fill_vect (size_type n,
                            const value_type & val,
                            std::true_type) {
                _size = n;
                _capacity = 8;
                while (_capacity < _size)
                    _capacity *= 2;
                _elements = new value_type[_capacity];
                for (size_type i = 0; i < _size; i++) {
                    _elements[i] = val;
                }
                _it.setPtr(_elements);
            }

            template<class InputIterator>
            void fill_vect(InputIterator first,
                           InputIterator last,
                           std::false_type) {
                 InputIterator tmp = first;

                 while (tmp != last) {
                     _size++;
                     tmp++;
                 }
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
                 _it.setPtr(_elements);
            }
    };
}

template <class T>
bool operator==(const ft::vector<T>& lhs, const ft::vector<T>& rhs)
{
    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] != rhs[i]) { return false; }
    }
    return true;
}

template <class T>
  bool operator!=(const ft::vector<T>& lhs, const ft::vector<T>& rhs)
{
    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] == rhs[i]) { return false; }
    }
    return true;
}

template <class T>
bool operator<(const ft::vector<T>& lhs, const ft::vector<T>& rhs)
{
    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] >= rhs[i]) { return false; }
    }
    return true;
}

template <class T>
bool operator<=(const ft::vector<T>& lhs, const ft::vector<T>& rhs)
{
    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] > rhs[i]) { return false; }
    }
    return true;
}

template <class T>
bool operator>(const ft::vector<T>& lhs, const ft::vector<T>& rhs)
{
    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] <= rhs[i]) { return false; }
    }
    return true;
}

template <class T>
bool operator>= (const ft::vector<T>& lhs, const ft::vector<T>& rhs)
{
    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] < rhs[i]) { return false; }
    }
    return true;
}

#endif // FT_VECTOR_H
