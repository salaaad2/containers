#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "random_access_iterator.hpp"
#include "reverse_random_access_iterator.hpp"

namespace ft {
    template <class T> class list {
        public :
            typedef T value_type;
            typedef size_t size_type;
            typedef random_access_iterator<value_type> iterator;
            typedef reverse_random_access_iterator<value_type> reverse_iterator;

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

        private :
            typedef struct s_node {
                value_type data;
                s_node * next;
                s_node * prev;
            } t_node;
            t_node * _first;
            t_node * _last;
    };
}

#endif // LIST_H
