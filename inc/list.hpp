#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <type_traits>

#include <math.h>

#include "node.hpp"
#include "list_iterator.hpp"
#include "reverse_list_iterator.hpp"
#include "random_access_iterator.hpp"

namespace ft {
    template <class T> class list {
        public :
            typedef T value_type;
            typedef s_node<value_type> t_node;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef size_t size_type;
            typedef list_iterator<value_type> iterator;
            typedef const list_iterator<value_type> const_iterator;
            typedef reverse_list_iterator<value_type> reverse_iterator;
            typedef const reverse_list_iterator<value_type> const_reverse_iterator;

//
// constructors
// TODO: delete 1 more node ???

            explicit list () :
                _first(NULL), _last(NULL)
            {
                _last = new t_node;
                _last->data = value_type();
                _last->prev = _last;
                _last->next = _last;
                _first = _last;
            }

            explicit list (size_type n, const value_type& val = value_type()) {
                t_node * tmp;
                _first = new t_node;
                _last = new t_node;

                _first->prev = _last;
                _first->next = _last;
                _first->data = val;

                _last->next = _first;
                _last->prev = _first;
                _last->data = value_type();

                tmp = _first;
                while (--n) {
                    tmp->next = new t_node;
                    tmp->next->prev = tmp;
                    tmp->next->next = NULL;
                    tmp->next->data = val;
                    tmp = tmp->next;
                }
                _last = tmp;
            }

            // TODO: MacOS
            // template <class InputIterator>
            // list(InputIterator first,
            //         InputIterator last) :
            //         _first(NULL), _last(NULL) {
            //     typedef typename std::is_integral<InputIterator>::type Integral;

            //     insert(first, last, Integral());
            // }

            list (const list & x) : _first(NULL), _last(NULL) {
                *this = x;
                return ;
            }

            list    & operator=(const list &x) {
                iterator tmp = x.begin();

                clear();
                while (tmp != x.end()) {
                    push_back(*tmp);
                    tmp++;
                }
            }

            ~list() {
                t_node * tmp = _first;

                while (tmp != _last) {
                    tmp = tmp->next;
                    delete tmp->prev;
                }
            }
//
// modifier functions
//TODO: fix splice


            void clear() {
                iterator tmp = begin();

                while (tmp != end()) {
                    erase(tmp);
                    tmp++;
                }
            }

            void assign(size_type n, const value_type& val) {
                t_node * tmp;
                t_node * ptr = _first;

                if (_first != NULL)
                {
                    while (ptr != NULL)
                    {
                        tmp = ptr;
                        ptr = ptr->next;
                        delete tmp;
                    }
                }
                _first = new t_node;
                _first->prev = NULL;
                _first->next = NULL;
                _first->data = val;
                tmp = _first;
                while (--n) {
                    tmp->next = new t_node;
                    tmp->next->prev = tmp;
                    tmp->next->next = NULL;
                    tmp->next->data = val;
                    tmp = tmp->next;
                }
                _last = tmp;
            }

            void remove (const value_type & val) {
                iterator tmp = begin();
                iterator s;

                if (empty())
                {return ;}

                while (tmp != end()) {
                    if (*tmp == val) {
                        _erase(tmp);
                        tmp = begin();
                    }
                    tmp++;
                }
            }

            template <class Predicate>
            void remove_if(Predicate pred) {
                iterator tmp = begin();
                iterator s;

                if (empty()) return ;

                while (tmp != end()) {
                    if (pred(*tmp)) {
                        _erase(tmp);
                        tmp = begin();
                    }
                    tmp++;
                }
            }

            void unique() {
                iterator tmp = begin();
                value_type rm = *tmp;

                if ((empty()) ||
                    (size() == 1))
                {return ;}

                while (tmp != end()) {
                    rm = *tmp;
                    tmp++;
                    while (tmp != end() && *tmp == rm) {
                        tmp = _erase(tmp);
                    }
                }
            }


            template <class BinaryPredicate>
            void unique (BinaryPredicate binary_pred) {
                iterator tmp = begin();
                value_type rm = *tmp;

                if ((empty()) ||
                    (size() == 1))
                {return ;}

                while (tmp != end()) {
                    rm = *tmp;
                    tmp++;
                    while (tmp != end() && binary_pred(rm, *tmp)) {
                        tmp = _erase(tmp);
                    }
                }
            }
//   void reverse();

            void splice (iterator position, list& x) {
                t_node * tmp = _first;
                t_node * xtmp = x._first;
                iterator itmp = begin();

                while (itmp != position && tmp != NULL) {
                    tmp = tmp->next;
                    itmp++;
                }
                x._last->next = tmp->next;
                tmp->next = xtmp;
                xtmp->prev = tmp;
                x._first = NULL;
                x._last = NULL;
                //std::cout <<  << std::endl;

            }

            iterator _insert (iterator position, size_type n, const value_type& val)
            {
                t_node * tmp = _first;
                t_node * nu;
                iterator it = begin();

                if (position == begin()) {
                    push_front(val);
                    if (n == 1)
                        return (it);
                    n--;
                }
                else if (position == end()) {
                    push_back(val);
                    if (n == 1)
                        return (it);
                    n--;
                }
                while (it != position) {
                    tmp = tmp->next;
                    it++;
                }
                while (n > 0)
                {
                    nu = new t_node;
                    nu->data = val;
                    nu->next = tmp;
                    nu->prev = tmp->prev;

                    tmp->prev->next = nu;
                    tmp->prev = nu;
                    n--;
                }
                return it;
            }

            void _insert_dispatch(iterator position,
                             size_type n,
                             const value_type &val,
                             std::true_type) {
                _insert(position, n, val);
            }

            template<class InputIterator>
            void _insert_dispatch(iterator position,
                                    InputIterator first,
                                    InputIterator last,
                                  std::false_type) {
                InputIterator tmp = first;

                while (tmp != last) {
                    _insert(position, 1, *tmp);
                    tmp++;
                    position++;
                }
            }

            iterator insert(iterator position,
                             const value_type &val = value_type()) {
                return (_insert_dispatch(position, 1, val, std::true_type()));

            }

            void insert(iterator position,
                             size_type n,
                             const value_type &val = value_type()) {
                _insert_dispatch(position, n, val, std::true_type());
            }

            template <class InputIterator>
            void insert(iterator position,
                        InputIterator first,
                        InputIterator last) {
                typedef typename std::is_integral<InputIterator>::type Integral;

                _insert_dispatch(position, first, last, Integral());
            }

            iterator _erase(iterator position) {
                iterator it = begin();
                t_node * tmp = _first;

                if (position == begin()) {
                    pop_front();
                    return (begin());
                }
                else if (position == end()) {
                    pop_back();
                    return (position);
                }
                while (it != position) {
                    it++;
                    tmp = tmp->next;
                }
                position++;
                if (tmp != _last)
                {
                    tmp->prev->next = tmp->next;
                    tmp->next->prev = tmp->prev;
                    delete tmp;
                }
                else {
                    pop_back();
                    return (end());
                }
                return (position);
            }

            iterator erase(iterator position) {
                return (_erase(position));
            }

            iterator erase(iterator first, iterator last) {
                iterator tmp = first;

                while (tmp != last) {
                    _erase(tmp);
                    tmp++;
                }
                return (tmp);
            }

            void sort() { // bubble sort
                t_node * s = _first;
                t_node * tmp = _first;
                value_type td;

                while (s != NULL) {
                    if (s->data < tmp->data) {
                        td = s->data;
                        s->data = tmp->data;
                        tmp->data = td;
                        s = _first;
                    }
                    tmp = s;
                    s = s->next;
                }
            }

            template <class Compare>
            void sort(Compare comp) { // bubble sort
                t_node * s = _first;
                t_node * tmp = _first;
                value_type td;

                while (s != NULL) {
                    if (comp(s->data, tmp->data)) {
                        td = s->data;
                        s->data = tmp->data;
                        tmp->data = td;
                        s = _first;
                    }
                    tmp = s;
                    s = s->next;
                }
            }


            void push_front(const value_type &val) {
                t_node * tmp;
                tmp = new t_node;

                tmp->data = val;
                tmp->next = _first;
                tmp->prev = NULL;

                _first->prev = tmp;
                _first = tmp;
            }

            void push_back(const value_type &val) {
                t_node *tmp;
                tmp = new t_node;

                tmp->data = val;
                tmp->next = NULL;
                tmp->prev = _last;

                _last->next = tmp;
                _last = tmp;
            }

            void pop_front() {
                if (size()) {
                    _first = _first->next;
                    delete _first->prev;
                }
            }

            void pop_back() {
                if (size()){
                    _last = _last->prev;
                    delete _last->next;
                }
            }
//
// capacity
//
            void resize(size_type n, value_type val = value_type()) {
                size_type spos = 0;
                t_node * ptr = _first;
                t_node * tmp;

                if (n < size()) {
                    while (spos < (n - 1)) {
                        ptr = ptr->next;
                        spos++;
                    }
                    _last = ptr;
                    ptr = ptr->next;
                    while (ptr != NULL) {
                        tmp = ptr;
                        ptr = ptr->next;
                        delete tmp;
                    }
                    _last->next = NULL;
                    return ;
                }
                else if (n > size()){
                    while (ptr != _last) {
                        ptr = ptr->next;
                        spos++;
                    }
                    n -= size();
                    while (n) {
                        ptr->next = new t_node;
                        ptr->next->prev = ptr;
                        ptr->next->next = NULL;
                        ptr->next->data = val;
                        ptr = ptr->next;
                        n--;
                    }
                    _last = ptr;
                    return ;
                }
            }

            size_type size() {
                iterator tmp = begin();
                size_type size = 0;

                while (tmp != end()) {
                    size++;
                    tmp++;
                }
                return (size);
            }

            size_type empty()
            {return (_first == NULL);}

            size_type max_size()
            {return (pow(2, sizeof(void *) * 8) / sizeof(ft::list<T>) - 1);}
//
// iterators
// TODO: last elem

            iterator begin()
            {return (iterator(_first));}

            const_iterator begin() const
            {return (const_iterator(_first));}

            iterator end()
            {return (iterator(_last->next));}

            const_iterator end() const
            {return (const_iterator(_last->next));}

            reverse_iterator rend()
            {return reverse_iterator(_first);}

            const_reverse_iterator rend() const
            {return const_reverse_iterator(_first);}

            reverse_iterator rbegin()
            {return reverse_iterator(_last);}

            const_reverse_iterator rbegin() const
            {return const_reverse_iterator(_last);}


//
// access
//
            reference front()
            {return (_first->data);}

            const_reference front() const
            {return (_first->data);}


            reference back()
            {return (_last->data);}

            const_reference back() const
            {return (_last->data);}

        private :
            t_node * _first;
            t_node * _last;
    };
}

#endif // LIST_H
