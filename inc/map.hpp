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
            typedef map_iterator<value_type>                 iterator;
            typedef const map_iterator<value_type>           const_iterator;
            typedef size_t                                   size_type;
            typedef s_node<value_type>                       t_node;
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

            std::pair<iterator, bool> insert (const_reference &val) {
                t_node * tn = _create_node(val);
                t_node * nu = _head;
                iterator itmp = begin();
                key_compare comp;

                if (_size == 0) {
                    _head = tn;
                }
                else if (_key_dup(val)) {
                    while ((*itmp).first != val.first) {
                        itmp++;
                    }
                    return std::pair<iterator, bool>(itmp, false);
                }
                else {
                    if ((comp(*itmp).first, val.first)) {
                        nu = nu->right;
                    }
                    else {
                        nu->left = tn;
                        tn->parent = nu;
                    }
                }
                itmp.setPtr(tn);
                return std::pair<iterator, bool>(itmp, true);
            }


            iterator begin() {
                return iterator(_head);
            }

            const_iterator begin() const {
                return const_iterator(_head);
            }

            iterator end() {
                iterator ite = begin();
                t_node * tmp = _head;

                while (tmp->right) {
                    tmp = tmp->right;
                    ite++;
                }
                ite.setPtr(tmp);
                return (ite);
            }

            t_node * _create_node(const_reference val) {
                t_node * tmp = new t_node(val);

                tmp->parent = NULL;
                tmp->left = NULL;
                tmp->right = NULL;
                return (tmp);
            }

            bool _key_dup(const_reference val) {
                iterator it = begin();

                while (it != end()) {
                    if ((*it).first == val.first)
                    {return (true);}
                    it++;
                }
                return (false);
            }

        private :
            size_type _size;
            t_node * _head;
    };
}

#endif // MAP_H
