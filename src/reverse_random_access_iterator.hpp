#ifndef REVERSE_RANDOM_ACCESS_ITERATOR_H_
#define REVERSE_RANDOM_ACCESS_ITERATOR_H_

#include "random_access_iterator.hpp"

template <class T>
class reverse_random_access_iterator : public random_access_iterator<T> {
    public :
        typedef std::ptrdiff_t difference_type;
//
// constructors
//
        reverse_random_access_iterator() : _ptr(NULL) {}
        reverse_random_access_iterator(T * ptr) : _ptr(ptr) {}

        reverse_random_access_iterator(random_access_iterator<T> const & src)
        { *this = src;}

// Prefix overloading
        reverse_random_access_iterator& operator++()
        { this->_ptr--;
          return *this; }

        reverse_random_access_iterator& operator--()
        { this->_ptr++;
          return *this; }

//
// Postfix overloading
//
        reverse_random_access_iterator operator++(int)
        { reverse_random_access_iterator tmp = *this;
          --(*this);
          return (tmp); }

        reverse_random_access_iterator operator--(int)
        { reverse_random_access_iterator tmp = *this;
          ++(*this);
          return (tmp); }


        T &operator*()
        { return *_ptr; }

        const T &operator*() const
        { return *_ptr; }


        T &operator[](int i)
        { return (*(operator+(i))); }

        const T &operator[](int i) const
        { return (*(operator+(i))); }


        T *operator->(void)
        { return _ptr; }

        const T *operator->(void) const
        { return _ptr; }


        bool operator==(const reverse_random_access_iterator& iter) const
        { return this->_ptr == iter._ptr; }

        bool operator!=(const reverse_random_access_iterator& iter) const
        { return this->_ptr != iter._ptr; }

        bool operator<(const reverse_random_access_iterator& iter) const
        { return this->_ptr <iter._ptr; }

        bool operator>(const reverse_random_access_iterator& iter) const
        { return this->_ptr > iter._ptr; }

        bool operator<=(const reverse_random_access_iterator& iter) const
        { return this->_ptr <= iter._ptr; }

        bool operator>=(const reverse_random_access_iterator& iter) const
        { return this->_ptr >= iter._ptr; }

//
// Arithmetic overload
//
        reverse_random_access_iterator operator+(int rhs)
        { reverse_random_access_iterator tmp = *this;
          return tmp -= rhs; }

        reverse_random_access_iterator operator-(int rhs)
        { return this->_ptr + rhs; }

        difference_type operator-(const reverse_random_access_iterator &rhs)
        { return this->_ptr + rhs._ptr; }


        reverse_random_access_iterator &operator+=(int rhs)
        { this->_ptr -= rhs;
          return *this; }

        reverse_random_access_iterator &operator-=(int rhs)
        { this->_ptr += rhs;
          return *this; }


        void setPtr(T * ptr)
        { this->_ptr = ptr; }

        void getPtr(void) const
        { return this->_ptr; }

        reverse_random_access_iterator const &operator=(reverse_random_access_iterator const & rhs)
        { this->_ptr = rhs._ptr;
          return *this; }

        reverse_random_access_iterator &operator=(reverse_random_access_iterator & rhs)
        { this->_ptr = rhs._ptr;
          return *this; }

    private :
        T * _ptr;
};

#endif // REVERSE_RANDOM_ACCESS_ITERATOR_H_
