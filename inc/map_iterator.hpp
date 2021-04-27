#ifndef MAP_ITERATOR_H_
#define MAP_ITERATOR_H_

#include "MapNode.hpp"

template <class T>
class map_iterator {
  public :
    typedef ft::s_node<T> t_node;
//
// constructors
//
    map_iterator() : _ptr(NULL) {}
    map_iterator(t_node *rhs) : _ptr(rhs) {}

    map_iterator(map_iterator *rhs) : _ptr(NULL)
    {*this = rhs;}

    map_iterator &operator=(const map_iterator &rhs)
    {
      _ptr = rhs._ptr;
      return (*this);
    }

    ~map_iterator() {}

//
// Prefix overloading
// TODO: successor algorithm
    map_iterator& operator++()
    {
      if (_ptr == NULL) {return *this;}
      if (_ptr->right != NULL) {
        _ptr = _ptr->right;
        while (_ptr->left != NULL) {
          _ptr = _ptr->left;
        }
        return *this;
      }
      else if (_ptr->right == NULL) {
        t_node * tmp = _ptr->parent;
        while (tmp != NULL && _ptr == tmp->right) {
          _ptr = tmp;
          tmp = tmp->parent;
        }
        _ptr = tmp;
        return *this;
      }


      return *this; }

    map_iterator& operator--()
    { _ptr = _ptr->left;
      return *this; }

// TODO: double check
    map_iterator operator++(int)
    { map_iterator tmp = *this;
      ++(*this);
      return (tmp); }

    map_iterator operator--(int)
    { map_iterator tmp = *this;
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


//
// getters/setters
//

    void setPtr(t_node * ptr)
    { _ptr = ptr; }

    t_node * getPtr(void) const
    { return _ptr; }

    bool operator==(const map_iterator & rhs)
    { return (_ptr == rhs._ptr); }

    bool operator!=(const map_iterator & rhs)
    { return (_ptr != rhs._ptr); }

  private :
    t_node * _ptr;
};

#endif // MAP_ITERATOR_H_
