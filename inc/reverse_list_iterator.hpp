#ifndef REVERSE_LIST_ITERATOR_H_
#define REVERSE_LIST_ITERATOR_H_

#include "node.hpp"

template <class T>
class reverse_list_iterator {
  public :
    typedef ft::s_node<T> t_node;
//
// constructors
//
    reverse_list_iterator() : _ptr(NULL) {}
    reverse_list_iterator(t_node *rhs) : _ptr(rhs) {}

    reverse_list_iterator(reverse_list_iterator *rhs) : _ptr(NULL)
    {
      *this = rhs;
    }

    reverse_list_iterator &operator=(const reverse_list_iterator &rhs)
    {
      _ptr = rhs._ptr;
      return (*this);
    }

    ~reverse_list_iterator() {}

//
// Prefix overloading
//
    reverse_list_iterator& operator++()
    { _ptr = _ptr->prev;
      return *this; }

    reverse_list_iterator& operator--()
    { _ptr = _ptr->next;
      return *this; }
// TODO: double check
    reverse_list_iterator operator++(int)
    { reverse_list_iterator tmp = *this;
      --(*this);
      return (tmp); }

    reverse_list_iterator operator--(int)
    { reverse_list_iterator tmp = *this;
      ++(*this);
      return (tmp); }


    T &operator*()
    { return _ptr->data; }

    const T &operator*() const
    { return _ptr->data; }


    T *operator->(void)
    { return _ptr; }

    const T *operator->(void) const
    { return _ptr; }


//
// getters/setters
//

    void setPtr(t_node * ptr)
    { _ptr = ptr; }

    t_node * getPtr(void) const
    { return _ptr; }

    bool operator==(const reverse_list_iterator & rhs)
    { return (_ptr == rhs._ptr); }

    bool operator!=(const reverse_list_iterator & rhs)
    { return (_ptr != rhs._ptr); }

  private :
    t_node * _ptr;
};

#endif // REVERSE_LIST_ITERATOR_H_
