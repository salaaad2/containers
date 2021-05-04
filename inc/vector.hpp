#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <iostream>
# include <type_traits>

# include <math.h>

# include "random_access_iterator.hpp"

namespace ft {
    template <class T> class vector {
        public :
            typedef T value_type;
            typedef size_t size_type;
            typedef random_access_iterator<value_type> iterator;
            typedef const random_access_iterator<value_type> const_iterator;
            typedef reverse_random_access_iterator<value_type> reverse_iterator;
            typedef const reverse_random_access_iterator<value_type> const_reverse_iterator;
//
// constructor/destructor
//
            explicit vector() :
                _elements(NULL), _size(0), _capacity(0) {
                return ;
            }

            explicit vector(size_type n,
                             const value_type& val = value_type()) : _elements(NULL), _size(0), _capacity(0){
                fill_vect(n, val, std::true_type());
            }

            template <class InputIterator>
            vector(InputIterator first,
                    InputIterator last) :
                    _elements(NULL), _size(0), _capacity(0){
                typedef typename std::is_integral<InputIterator>::type Integral;

                fill_vect(first, last, Integral());
            }

            vector(const vector &x) :
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

            vector & operator=(vector const & x) {
                _capacity = x.capacity();
                _size = x.size();
                _elements = new value_type[_size];

                for (size_type i = 0; i < _size; i++)
                {_elements[i] = x[i];}
                return *this;
            }
//
// capacity
//
            size_type capacity (void) const
            { return (this->_capacity); }

            size_type max_size (void) const
            { return (pow(2, sizeof(void *) * 8) / sizeof(ft::vector<T>) - 1);}

            size_type size (void) const
            { return (this->_size); }

            bool empty (void) const
            { return (this->_size == 0); }

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

//
// iterators
//
            iterator begin()
            { return iterator(_elements); }

            iterator end()
            { return iterator(_elements + _size); }

            const_iterator begin() const
            { return const_iterator(_elements); }

            const_iterator end() const
            { return const_iterator(_elements + _size); }

            reverse_iterator rbegin()
            { return reverse_iterator(end() - 1); }

            reverse_iterator rend()
            { return reverse_iterator(begin() - 1); }

            const_reverse_iterator rbegin() const
            { return const_reverse_iterator(end() - 1); }

            const_reverse_iterator rend() const
            { return const_reverse_iterator(begin() - 1); }


//
// element access
//
            value_type const & operator[](size_type n) const
            {return (_elements[n]); }

            value_type & operator[](size_type n)
            { return (_elements[n]); }
            value_type const & at(size_type n) const
            { if (n > _size)
              { throw std::out_of_range("out of range"); }
              return (_elements[n]); }

            value_type & at(size_type n)
            { if (n > _size)
              { throw std::out_of_range("out of range"); }
              return (_elements[n]); }

            value_type & front()
            {return (_elements[0]); }

            value_type const & front() const
            {return (_elements[0]); }

            value_type & back()
            {return (_elements[_size - 1]); }

            value_type const & back() const
            {return (_elements[_size - 1]); }


//
// modifiers
//
            void swap(vector & x) {
                std::swap(_elements, x._elements);
                std::swap(_size, x._size);
                std::swap(_capacity, x._capacity);
                std::swap(_it, x._it);
            }


            template <class InputIterator>
            void assign (InputIterator first,
                         InputIterator last) {
                typedef typename std::is_integral<InputIterator>::type Integral;

                _size = 0;
                _capacity = 0;
                fill_vect(first, last, Integral());
            }

            void assign(size_type n,
                        const value_type & val) {
                _size = 0;
                _capacity = 0;
                delete [] _elements;
                fill_vect(n, val, std::true_type());
            }

            void resize(size_type n,
                        value_type val = value_type()) {
                size_type tmp = 0;

                if (n < _size) {
                    for (tmp = _size; tmp > n; tmp--) {
                        _elements[tmp] = val;
                        _size--;
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
                        _size++;
                    }
                    _elements = tmpel;
                    _it.setPtr(_elements);
                }
            }


            iterator insert(iterator position,
                             const value_type &val = value_type()) {
                _insert_dispatch(position, 1, val, std::true_type());
                return (_it);
            }

            void insert(iterator position,
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
                iterator tmp = end();

                _insert(tmp, 1, val);
            }

            void pop_back() {
                _erase(end(), 1);
            }


        private :
//
// attributes
//
            iterator _it;
            value_type * _elements;
            size_type _size;
            size_type _capacity;
//
// constructor helpers
//
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

            void _insert(iterator & position,
                         size_type n,
                         const value_type val) {
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
                    if (_capacity == 0) {
                        _capacity = 8;
                    }
                    while (_capacity < (_size + n)) {
                        _capacity *= 2;
                    }
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
                if (spos == _size)
                {_it.setPtr(_elements + _size);}
                else
                {_it.setPtr(_elements);}
                delete [] copy; // lol
                _size += n;
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

    };
}

//
// comparison operators
//

template <class T>
bool operator==(const ft::vector<T>& lhs,
                const ft::vector<T>& rhs)
{
    if (lhs.size() != rhs.size())
    {return (false);}

    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] != rhs[i]) { return false; }
    }
    return true;
}

template <class T>
bool operator!=(const ft::vector<T>& lhs,
                const ft::vector<T>& rhs)
{
    return (!(lhs == rhs));
}

template <class T>
bool operator<(const ft::vector<T> & lhs,
               const ft::vector<T> & rhs)
{
    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] > rhs[i]) { return false; }
    }
    return true;
}

template <class T>
bool operator<=(const ft::vector<T>& lhs,
                const ft::vector<T>& rhs)
{
    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] > rhs[i]) { return false; }
    }
    return true;
}

template <class T>
bool operator>(const ft::vector<T>& lhs,
               const ft::vector<T>& rhs)
{
    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] < rhs[i]) { return false; }
    }
    return true;
}

template <class T>
bool operator>= (const ft::vector<T>& lhs,
                 const ft::vector<T>& rhs)
{
    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] < rhs[i]) { return false; }
    }
    return true;
}

#endif // FT_VECTOR_H
