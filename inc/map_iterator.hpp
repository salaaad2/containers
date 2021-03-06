#ifndef MAP_ITERATOR_H_
#define MAP_ITERATOR_H_

#include "map_node.hpp"

template <class T>
class map_iterator {
  public :
    typedef ft::m_node<T> t_node;
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
// Successor Algorithm
    map_iterator& operator++() {
      if (_ptr == NULL)
      {return *this;}

      if (_ptr->right != NULL) {
        _ptr = _ptr->right;
        while (_ptr->left != NULL) {
          _ptr = _ptr->left;
        }
      }
      else {
        t_node * tmp = _ptr->parent;
        while (tmp != NULL && _ptr == tmp->right) {
          _ptr = tmp;
          tmp = tmp->parent;
        }
        _ptr = tmp;
      }
      return *this;
    }

    map_iterator& operator--()
    {
      if (_ptr == NULL)
      {return *this;}

      if (_ptr->left != NULL) {
        _ptr = _ptr->left;
        while (_ptr->right != NULL) {
          _ptr = _ptr->right;
        }
      }
      else {
        t_node * tmp = _ptr->parent;
        while (tmp != NULL && _ptr == tmp->left) {
          _ptr = tmp;
          tmp = tmp->parent;
        }
        _ptr = tmp;
      }
      return *this;
    }

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
    { return &_ptr->data; }

    const T *operator->(void) const
    { return &_ptr->data; }


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

template <class T>
class reverse_map_iterator {
  public :
    typedef ft::m_node<T> t_node;
//
// constructors
//
    reverse_map_iterator() : _ptr(NULL) {}
    reverse_map_iterator(t_node *rhs) : _ptr(rhs) {}

    reverse_map_iterator(reverse_map_iterator *rhs) : _ptr(NULL)
    {*this = rhs;}

    reverse_map_iterator &operator=(const reverse_map_iterator &rhs)
    {
      _ptr = rhs._ptr;
      return (*this);
    }

    ~reverse_map_iterator() {}

//
// Prefix overloading
// Successor Algorithm
    reverse_map_iterator& operator++() {
      if (_ptr == NULL)
      {return *this;}

      if (_ptr->left != NULL) {
        _ptr = _ptr->left;
        while (_ptr->right != NULL) {
          _ptr = _ptr->right;
        }
      }
      else {
        t_node * tmp = _ptr->parent;
        while (tmp != NULL && _ptr == tmp->left) {
          _ptr = tmp;
          tmp = tmp->parent;
        }
        _ptr = tmp;
      }
      return *this;
    }

    reverse_map_iterator& operator--()
    {
      if (_ptr == NULL)
      {return *this;}

      if (_ptr->right != NULL) {
        _ptr = _ptr->right;
        while (_ptr->left != NULL) {
          _ptr = _ptr->left;
        }
      }
      else {
        t_node * tmp = _ptr->parent;
        while (tmp != NULL && _ptr == tmp->right) {
          _ptr = tmp;
          tmp = tmp->parent;
        }
        _ptr = tmp;
      }
      return *this;
    }

// TODO: double check
    reverse_map_iterator operator++(int)
    { reverse_map_iterator tmp = *this;
      ++(*this);
      return (tmp); }

    reverse_map_iterator operator--(int)
    { reverse_map_iterator tmp = *this;
      --(*this);
      return (tmp); }


    T &operator*()
    { return _ptr->data; }

    const T &operator*() const
    { return _ptr->data; }


    T *operator->(void)
    { return &_ptr->data; }

    const T *operator->(void) const
    { return &_ptr->data; }


//
// getters/setters
//

    void setPtr(t_node * ptr)
    { _ptr = ptr; }

    t_node * getPtr(void) const
    { return _ptr; }

    bool operator==(const reverse_map_iterator & rhs)
    { return (_ptr == rhs._ptr); }

    bool operator!=(const reverse_map_iterator & rhs)
    { return (_ptr != rhs._ptr); }

  private :
    t_node * _ptr;
};

#endif // MAP_ITERATOR_H_
