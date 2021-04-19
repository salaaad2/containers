#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "node.hpp"
#include "list_iterator.hpp"
#include "random_access_iterator.hpp"
#include "reverse_random_access_iterator.hpp"

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
            typedef reverse_random_access_iterator<value_type> reverse_iterator;
//
// constructors
// TODO: 2 more constructors
// TODO: delete print
            explicit list () {
                t_node * list;

                _first = list;
                _last = list;
            }

            explicit list (size_type n, const value_type& val = value_type()) {
                t_node * tmp;
                _first = new t_node;

                _first->prev = NULL;
                _first->next = NULL;
                _first->data = val;
                tmp = _first;
                _size = n;
                while (--n) {
                    tmp->next = new t_node;
                    tmp->next->prev = tmp;
                    tmp->next->next = NULL;
                    tmp->next->data = val;
                    tmp = tmp->next;
                }
                _last = tmp;
            }

            // template <class InputIterator>
            // list (InputIterator first, InputIterator last) {

            // }

            // list (const list& x) {
            //     *this = x;
            // }
//
// member functions
// TODO assign delete ???

            void assign(size_type n, const value_type& val) {
                t_node * tmp;

                if (_first != NULL)
                {
                    tmp = _first;
                    while (tmp->next != NULL)
                    {
                        delete tmp;
                        tmp = tmp->next;
                    }
                }
                _first = new t_node;
                _first->prev = NULL;
                _first->next = NULL;
                _first->data = val;
                tmp = _first;
                _size = n;
                while (--n) {
                    tmp->next = new t_node;
                    tmp->next->prev = tmp;
                    tmp->next->next = NULL;
                    tmp->next->data = val;
                    tmp = tmp->next;
                }
                _last = tmp;
            }


            iterator _insert (iterator position, size_type n, const value_type& val)
            {
                t_node * tmp = _first;
                t_node * nu;
                iterator it = begin();

                if (position == begin() && n == 1) {
                    push_front(val);
                    return (it);
                }
                else if (position == end() && n == 1) {
                    push_back(val);
                    return (it);
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
                _size += n;
                return it;
            }

            iterator insert (iterator position, const value_type& val) {
                return(_insert(position, 1, val));
            }

            void insert (iterator position, size_type n, const value_type& val) {
                _insert(position, n, val);
            }

            iterator erase(iterator position) {
                iterator it = begin();
                t_node * tmp = _first;

                if (position == begin()) {
                    pop_front();
                    std::cout << "qwe";
                    return (position);
                }
                else if (position == end()) {
                    pop_back();
                    return (position);
                }
                while (it != position) {
                    it++;
                    tmp = tmp->next;
                }
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
                return (position);
            }
            // iterator erase(iterator first, iterator last) {
            // }

// template <class InputIterator>
//     void insert (iterator position, InputIterator first, InputIterator last);


            void push_front(const value_type &val) {
                t_node * tmp;
                tmp = new t_node;

                tmp->data = val;
                tmp->next = _first;
                tmp->prev = NULL;

                _first->prev = tmp;
                _first = tmp;
                _size += 1;
            }

            void push_back(const value_type &val) {
                t_node *tmp;
                tmp = new t_node;

                tmp->data = val;
                tmp->next = NULL;
                tmp->prev = _last;

                _last->next = tmp;
                _last = tmp;
                _size += 1;
            }

            void pop_front() {
                if (_size > 0) {
                    _size -= 1;
                    _first = _first->next;
                    delete _first->prev;
                }
            }

            void pop_back() {
                if (_size > 0){
                    _size -= 1;
                    delete _last;
                    _last = _last->prev;
                }
            }
//
// capacity
//
            size_type size() {
                return (_size);
            }

            size_type empty() {
                return (_size == 0);
            }
//
// begin
// TODO: iterators

            iterator begin() {
                return (iterator(_first));
            }

            iterator end() {
                return (iterator(_last));
            }
//
// access
//
            reference front() {
                return (_first->data);
            }

            const_reference front() const {
                return (_first->data);
            }


            reference back() {
                return (_last->data);
            }

            const_reference back() const {
                return (_last->data);
            }

        private :
            t_node * _first;
            t_node * _last;
            size_type _size;
    };
}

#endif // LIST_H
