#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "random_access_iterator.hpp"
#include "reverse_random_access_iterator.hpp"

namespace ft {
    template <class T> class list {
        public :
            typedef T value_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef size_t size_type;
            typedef random_access_iterator<value_type> iterator;
            typedef reverse_random_access_iterator<value_type> reverse_iterator;
//
// constructors
// TODO: 2 more constructors
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

            void push_front(const value_type &val) {
                t_node * tmp;
                tmp = new t_node;

                _size += 1;
                tmp->data = val;
                tmp->next = _first;
                tmp->prev = NULL;
                _first = tmp;
            }

            void push_back(const value_type &val) {
                t_node *tmp;
                tmp = new t_node;

                _size += 1;
                tmp->data = val;
                tmp->next = NULL;
                tmp->prev = _last;
                _last = tmp;
            }

            void pop_front() {
                if (_size > 0) {
                    _size -= 1;
                    _first = _first->next;
                    delete _first;
                }
            }

            void pop_back() {
                if (_size > 0){
                    _size -= 1;
                    _last = _last->next;
                    delete _last;
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

            // iterator begin() const {
            //     return (_first);
            // }

            // iterator end() const {
            //     return (_last);
            // }
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
            typedef struct s_node {
                value_type data;
                s_node * next;
                s_node * prev;
            } t_node;
            t_node * _first;
            t_node * _last;
            size_type _size;
    };
}

#endif // LIST_H
