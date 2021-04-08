#ifndef RANDOM_ACCESS_ITERATOR_H_
#define RANDOM_ACCESS_ITERATOR_H_

#include "Iiterator.hpp"

template <class T>
class random_access_iterator {
    public :
// constructors
        random_access_iterator() : _ptr(NULL) {}
        random_access_iterator(T * ptr) : _ptr(ptr) {}

// Prefix overloading
        random_access_iterator& operator++()
        { this->_ptr ++;
          return *this; }

        random_access_iterator& operator--()
        { this->_ptr --;
          return *this; }

// Postfix overloading
        virtual random_access_iterator& operator++(int)
        { ++*this;
          return *this; }

        random_access_iterator& operator--(int)
        { --*this;
          return *this; }

        T& operator*() const
        { return *this->_ptr; }

        bool operator==(const random_access_iterator& iter) const
        { return this->_ptr == iter._ptr; }

        bool operator!=(const random_access_iterator& iter) const
        { return this->_ptr != iter._ptr; }
// Arithmetic overload
        random_access_iterator &operator+(const random_access_iterator &rhs)
        { return this->_ptr + rhs._ptr; }

        random_access_iterator &operator+(int rhs)
        { return this->_ptr + rhs; }

        random_access_iterator &operator-(const random_access_iterator &rhs)
        { return this->_ptr - rhs._ptr; }

        random_access_iterator &operator-(int rhs)
        { return this->_ptr - rhs; }

        random_access_iterator &operator+=(int rhs)
        { this->_ptr += rhs;
          return *this; }

        random_access_iterator &operator-=(int rhs)
        { this->_ptr -= rhs;
          return *this; }

        void setPtr(T * ptr)
        { this->_ptr = ptr; }

    private :
        T * _ptr;
};

#endif // RANDOM_ACCESS_ITERATOR_H_
