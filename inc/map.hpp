#ifndef MAP_H
#define MAP_H

#include <iostream>

#include "MapNode.hpp"
#include "map_iterator.hpp"

namespace ft {
    template < class Key,
               class T,
               class Compare = std::less<Key>
               > class map {
        public :
//
// typedefs
//
            typedef std::pair<const Key, T>                  value_type;
            typedef Key                                      key_type;
            typedef T                                        mapped_type;
            typedef Compare                                  key_compare;
            typedef value_type&                              reference;
            typedef const value_type&                        const_reference;
            typedef value_type*                              pointer;
            typedef const value_type*                        const_pointer;
            typedef map_iterator<value_type>       iterator;
            typedef const map_iterator<value_type> const_iterator;
            typedef size_t                                   size_type;
            typedef s_node<value_type>             t_node;
//
// constructor/destructors
//
            explicit map () : _size(0), _head(NULL) {}

            template <class InputIterator>
            map(InputIterator first, InputIterator last) : _size(0), _head(NULL) {
                (void)first;
                (void)last;
            }

            ~map() {
                // clear();
            }
//
// content modifiers
//

            std::pair<iterator, bool> insert (const value_type &val) {
                t_node * tn = _create_node(val);
                iterator itmp;
                key_compare comp;

                (void)tn;
                return std::pair<iterator, bool>(itmp, true);
            }


            iterator begin() {
                return iterator(_head);
            }

            const_iterator begin() const {
                return const_iterator(_head);
            }

            t_node * _create_node(const value_type &val) {
                t_node * tmp = new t_node(val);

                tmp->parent = NULL;
                tmp->left = NULL;
                tmp->right = NULL;
                return (tmp);
            }

        private :
            size_type _size;
            t_node * _head;
    };
}

#endif // MAP_H
