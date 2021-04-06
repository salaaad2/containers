#ifndef RANDOM_ACCESS_ITERATOR_H_
#define RANDOM_ACCESS_ITERATOR_H_

#include "Iiterator.hpp"

template <class T>
class random_access_iterator {
    public :
        random_access_iterator& operator++()
        {
            this->ptr ++;
            return *this;
        }
// Prefix overloading
        random_access_iterator& operator--()
        {
            this->ptr --;
            return *this;
        }

// Postfix overloading
        random_access_iterator& operator++(int)
        {
            this->ptr ++;
            return *this;
        }
// Postfix overloading
        random_access_iterator& operator--(int)
        {
            this->ptr --;
            return *this;
        }

        T& operator*()
        {
            return *this->ptr;
        }

        bool operator==(const random_access_iterator& iter)
        {
            return this->ptr == iter.ptr;
        }

        bool operator!=(const random_access_iterator& iter)
        {
            return this->ptr != iter.ptr;
        }

        random_access_iterator begin()
        {
            return this->mBuffer;
        }


        random_access_iterator end()
        {
            return this->mBuffer + this->mSize;
        }
    private :
        T * ptr;
};

#endif // RANDOM_ACCESS_ITERATOR_H_
