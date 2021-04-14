#ifndef RANDOM_ACCESS_ITERATOR_H_
#define RANDOM_ACCESS_ITERATOR_H_

#include "Iiterator.hpp"

template <class T>
class random_access_iterator {
    public :
//
// constructors
//
        random_access_iterator() : _ptr(NULL) {}
        random_access_iterator(T * ptr) : _ptr(ptr) {}

        random_access_iterator(random_access_iterator const & src)
        { *this = src;}

// Prefix overloading
        random_access_iterator& operator++()
        { this->_ptr++;
          return *this; }

        random_access_iterator& operator--()
        { this->_ptr--;
          return *this; }

//
// Postfix overloading
//
        random_access_iterator& operator++(int)
        { ++*this;
          return *this; }

        random_access_iterator& operator--(int)
        { --*this;
          return *this; }


        T operator*()
        { return *_ptr; }

        const T operator*() const
        { return *_ptr; }


        T operator[](int i)
        { return _ptr[i]; }

        const T operator[](int i) const
        { return _ptr[i]; }


        T operator->(void)
        { return *_ptr; }

        const T operator->(void) const
        { return *_ptr; }


        bool operator==(const random_access_iterator& iter) const
        { return this->_ptr == iter._ptr; }

        bool operator!=(const random_access_iterator& iter) const
        { return this->_ptr != iter._ptr; }
//
// Arithmetic overload
//
        random_access_iterator &operator+(int rhs)
                { random_access_iterator tmp = *this;
                        return tmp += rhs; }

        random_access_iterator &operator-(const random_access_iterator &rhs)
        { return this->_ptr - rhs._ptr; }

        random_access_iterator operator-(int rhs)
        { return this->_ptr - rhs; }

        random_access_iterator &operator+=(int rhs)
        { this->_ptr += rhs;
          return *this; }

        random_access_iterator &operator-=(int rhs)
        { this->_ptr -= rhs;
          return *this; }


        void setPtr(T * ptr)
        { this->_ptr = ptr; }

        void getPtr(void) const
        { return this->_ptr; }

        random_access_iterator const &operator=(random_access_iterator const & rhs)
        { this->_ptr = rhs._ptr;
          return *this; }

        random_access_iterator &operator=(random_access_iterator & rhs)
        { this->_ptr = rhs._ptr;
          return *this; }

    private :
        T * _ptr;
};

#endif // RANDOM_ACCESS_ITERATOR_H_
