#ifndef RANDOM_ACCESS_ITERATOR_H_
#define RANDOM_ACCESS_ITERATOR_H_

////////////////////////////////////
// REGULAR RANDOM ACCESS ITERATOR //
////////////////////////////////////
template <class T>
class random_access_iterator {
    public :
        typedef std::ptrdiff_t difference_type;
//
// constructors
//
        random_access_iterator() : _ptr(NULL) {}
        random_access_iterator(T * ptr) : _ptr(ptr) {}

        random_access_iterator(random_access_iterator const & src)
        { *this = src;}

        random_access_iterator &operator=(const random_access_iterator & rhs)
        { _ptr = rhs._ptr;
          return *this; }

//
// Prefix overloading
//
        random_access_iterator& operator++()
        { _ptr++;
          return *this; }

        random_access_iterator& operator--()
        { _ptr--;
          return *this; }

//
// Postfix overloading
//
        random_access_iterator operator++(int)
        { random_access_iterator tmp = *this;
          ++(*this);
          return (tmp); }

        random_access_iterator operator--(int)
        { random_access_iterator tmp = *this;
          --(*this);
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


        bool operator==(const random_access_iterator& iter) const
        { return (_ptr == iter._ptr); }

        bool operator!=(const random_access_iterator& iter) const
        { return (_ptr != iter._ptr); }

        bool operator<(const random_access_iterator& iter) const
        { return (_ptr < iter._ptr); }

        bool operator>(const random_access_iterator& iter) const
        { return (_ptr > iter._ptr); }

        bool operator<=(const random_access_iterator& iter) const
        { return (_ptr <= iter._ptr); }

        bool operator>=(const random_access_iterator& iter) const
        { return (_ptr >= iter._ptr); }

//
// Arithmetic overload
//
        random_access_iterator operator+(int rhs)
        { random_access_iterator tmp = *this;
          return tmp += rhs; }

        random_access_iterator operator-(int rhs)
        { return _ptr - rhs; }

        difference_type operator-(const random_access_iterator &rhs)
        { return _ptr - rhs._ptr; }



        random_access_iterator &operator+=(int rhs)
        { _ptr += rhs;
          return *this; }

        random_access_iterator &operator-=(int rhs)
        { _ptr -= rhs;
          return *this; }


        void setPtr(T * ptr)
        { _ptr = ptr; }

        T * getPtr(void) const
        { return _ptr; }

    private :
        T * _ptr;
};
////////////////////////////////////
// REVERSE RANDOM ACCESS ITERATOR //
////////////////////////////////////

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
        { *this = src; }

        reverse_random_access_iterator &operator=(const random_access_iterator<T> & rhs)
        { _ptr = rhs.getPtr();
          return *this; }

// Prefix overloading
        reverse_random_access_iterator& operator++()
        { _ptr--;
          return *this; }

        reverse_random_access_iterator& operator--()
        { _ptr++;
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
        { return (*(this->_ptr - i)); }

        const T &operator[](int i) const
        { return (*(this->_ptr - i)); }


        T *operator->(void)
        { return _ptr; }

        const T *operator->(void) const
        { return _ptr; }


        bool operator==(const reverse_random_access_iterator& iter) const
        { return (_ptr == iter._ptr); }

        bool operator!=(const reverse_random_access_iterator& iter) const
        { return (_ptr != iter._ptr); }

        bool operator<(const reverse_random_access_iterator& iter) const
        { return (_ptr < iter._ptr); }

        bool operator>(const reverse_random_access_iterator& iter) const
        { return (_ptr > iter._ptr); }

        bool operator<=(const reverse_random_access_iterator& iter) const
        { return (_ptr <= iter._ptr); }

        bool operator>=(const reverse_random_access_iterator& iter) const
        { return (_ptr >= iter._ptr); }

//
// Arithmetic overload
//
        reverse_random_access_iterator operator+(int rhs)
        { return (reverse_random_access_iterator(_ptr - rhs)); }

        reverse_random_access_iterator operator-(int rhs)
        { return (reverse_random_access_iterator(_ptr + rhs)); }

        difference_type operator-(const reverse_random_access_iterator &rhs)
        { return _ptr + rhs._ptr; }


        reverse_random_access_iterator &operator+=(int rhs)
        { _ptr -= rhs;
          return *this; }

        reverse_random_access_iterator &operator-=(int rhs)
        { _ptr += rhs;
          return *this; }


        void setPtr(T * ptr)
        { _ptr = ptr; }

        void getPtr(void) const
        { return _ptr; }


    private :
        T * _ptr;
};

#endif // RANDOM_ACCESS_ITERATOR_H_
