#ifndef RANDOM_ACCESS_ITERATOR_H_
#define RANDOM_ACCESS_ITERATOR_H_

#include "Iiterator.hpp"

template <class T>
class random_access_iterator {
    public :
// constructors
        random_access_iterator(T * ptr) : _ptr(ptr) {}

        random_access_iterator& operator++()
        {
            this->_ptr ++;
            return *this;
        }
// Prefix overloading
        random_access_iterator& operator--()
        {
            this->_ptr --;
            return *this;
        }

// Postfix overloading
        random_access_iterator& operator++(int)
        {
            this->_ptr ++;
            return *this;
        }
// Postfix overloading
        random_access_iterator& operator--(int)
        {
            this->_ptr --;
            return *this;
        }

        T& operator*()
        {
            return *this->_ptr;
        }

        bool operator==(const random_access_iterator& iter)
        {
            return this->_ptr == iter._ptr;
        }

        bool operator!=(const random_access_iterator& iter)
        {
            return this->_ptr != iter._ptr;
        }
    private :
        T * _ptr;
};

#endif // RANDOM_ACCESS_ITERATOR_H_
