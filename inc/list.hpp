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
               t_node *list = new t_node[n];
               t_node *tmp = list;
               size_type i = 0;

               _first = &list[0];
               _last = &list[n];
               while (tmp != _last) {
                   list[i].data = val;
                   list[i].next = &list[i + 1];
                   list[i].prev = &list[i - 1];
                   tmp++;
                  std::cout << "data "<< list[i].data<< "i " << i << std::endl;
                   i++;
               }
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
