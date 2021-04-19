#ifndef LIST_ITERATOR_H_
#define LIST_ITERATOR_H_

#include "node.hpp"

template <class T>
class list_iterator {
  public :
    typedef ft::s_node<T> t_node;
//
// constructors
//
    list_iterator() : _ptr(NULL) {}
    list_iterator(t_node *rhs) : _ptr(rhs) {}

    list_iterator(list_iterator *rhs) : _ptr(NULL)
    {
      *this = rhs;
    }

    list_iterator &operator=(const list_iterator &rhs)
    {
      _ptr = rhs._ptr;
      return (*this);
    }

    ~list_iterator() {}

//
// Prefix overloading
//
    list_iterator& operator++()
    { _ptr = _ptr->next;
      return *this; }

    list_iterator& operator--()
    { _ptr = _ptr->prev;
      return *this; }
// TODO: ceux-ci
    list_iterator operator++(int)
    { list_iterator tmp = *this;
      ++(*this);
      return (tmp); }

    list_iterator operator--(int)
    { list_iterator tmp = *this;
      --(*this);
      return (tmp); }


    T &operator*()
    { return _ptr->data; }

    const T &operator*() const
    { return _ptr->data; }


    T *operator->(void)
    { return _ptr; }

    const T *operator->(void) const
    { return _ptr; }

    void operator=(const T & rhs)
    { *_ptr = rhs; }

//
// getters/setters
//

    void setPtr(t_node * ptr)
    { _ptr = ptr; }

    t_node * getPtr(void) const
    { return _ptr; }

  private :
    t_node * _ptr;
};

#endif // LIST_ITERATOR_H_
