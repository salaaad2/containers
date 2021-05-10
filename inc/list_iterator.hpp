#ifndef LIST_ITERATOR_H
# define LIST_ITERATOR_H

# include <cstddef>
# include "list_node.hpp"

template<class T>
class list_iterator {

  public:
    typedef struct ft::l_node<T> t_node;
/*
 *-----------------------------CONSTRUCTORS--------------------------------------
 */
    list_iterator() : _pointer(NULL) {}
    list_iterator(t_node *rhs) : _pointer(rhs) {}
    list_iterator(const list_iterator *rhs) : _pointer(NULL)
    {
      *this = rhs;
    }
    list_iterator &operator=(const list_iterator &rhs)
    {
      _pointer = rhs._pointer;
      return (*this);
    }
    ~list_iterator() {}

    t_node *getPtr() const {return (_pointer);}
    void setPtr(t_node *current) { _pointer = current;}

/*
 *------------------------------COMPARISONS OPERATORS------------------------
 */

    bool operator==(const list_iterator &rhs) const {
      return (_pointer == rhs._pointer);
    }
    bool operator!=(const list_iterator &rhs) const {
      return (_pointer != rhs._pointer);
    }

/*
 * dereference operators
 */

    T &operator*(void) { return (_pointer->data); }
    const T &operator*(void) const { return (_pointer->data); }

    T *operator->(void) { return (_pointer); }
    const T *operator->(void) const { return (_pointer); }

    void operator=(const T &rhs) { _pointer = rhs._pointer; }

    /*
     * incrementation and decrementation operators
     */

    // prefix
    list_iterator &operator++() {
      _pointer = _pointer->next;
      return (*this);
    }
    // postfix
    list_iterator operator++(int) {
      list_iterator tmp = *this;
      this->operator++();
      return (tmp);
    }
    // prefix
    list_iterator &operator--() {
      _pointer = _pointer->prev;
      return (*this);
    }
    // postfix
    list_iterator operator--(int) {
      list_iterator tmp = *this;
      this->operator--();
      return (tmp);
    }
  private:
    t_node *_pointer;
};

template<class T> class reverse_list_iterator : public list_iterator<T> {

  public:
    typedef struct ft::l_node<T> t_node;
/*
 *-----------------------------CONSTRUCTORS--------------------------------------
 */
    reverse_list_iterator() : _pointer(NULL) {}
    reverse_list_iterator(t_node *rhs) : _pointer(rhs) {}
    reverse_list_iterator(const reverse_list_iterator *rhs) : _pointer(NULL)
    {
      *this = rhs;
    }
    reverse_list_iterator(const list_iterator<T> *rhs) : _pointer(NULL)
    {
      *this = rhs;
    }
    reverse_list_iterator &operator=(const reverse_list_iterator &rhs)
    {
      _pointer = rhs._pointer;
      return (*this);
    }
    reverse_list_iterator &operator=(const list_iterator<T> &rhs)
    {
      _pointer = rhs._pointer;
      return (*this);
    }
    ~reverse_list_iterator() {}

/*
 * dereference operators
 */

    T &operator*(void) { return (_pointer->data); }
    const T &operator*(void) const { return (_pointer->data); }

    T *operator->(void) { return (_pointer); }
    const T *operator->(void) const { return (_pointer); }

    void operator=(const T &rhs) { _pointer = rhs._pointer; }

    /*
     * incrementation and decrementation operators
     */

    // prefix
    reverse_list_iterator &operator++() {
      _pointer = _pointer->prev;
      return (*this);
    }
    // postfix
    reverse_list_iterator operator++(int) {
      reverse_list_iterator tmp = *this;
      this->operator++();
      return tmp;
    }
    // prefix
    reverse_list_iterator &operator--() {
      _pointer = _pointer->next;
      return (*this);
    }
    // postfix
    reverse_list_iterator operator--(int) {
      reverse_list_iterator tmp = *this;
      this->operator--();
      return (tmp);
    }

  private:
    t_node *_pointer;
};

#endif
