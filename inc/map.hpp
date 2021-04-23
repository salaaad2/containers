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
            typedef map_iterator<key_type, value_type>       iterator;
            typedef const map_iterator<key_type, value_type> const_iterator;
            typedef size_t                                   size_type;
            typedef s_node<key_type, value_type>             t_node;
//
// constructor/destructors
//
            explicit map (const key_compare & compt = key_compare()) {
                _head = NULL;
                _compt = compt;
            }

            iterator insert (iterator position, const value_type &val) {
                iterator tmp = begin();

                while (tmp != position) {
                    tmp++;
                }
                if (key_compare(val, *tmp))
                    tmp->right->data = val;
                else
                    tmp->left->data = val;

            }

            iterator begin() {
                return iterator(_head);
            }

            const_iterator begin() const {
                return const_iterator(_head);
            }

        private :
            t_node * _head;
            key_compare _compt;
    };
}

#endif // MAP_H
