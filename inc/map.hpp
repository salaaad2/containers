#ifndef MAP_H
#define MAP_H

#include <iostream>

#include <math.h>

#include "map_node.hpp"
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
            typedef reverse_map_iterator<value_type>         reverse_iterator;
            typedef const reverse_map_iterator<value_type>   reverse_const_iterator;
            typedef size_t                                   size_type;
            typedef m_node<value_type>                       t_node;
//
// constructor/destructors
//
            explicit map () :
                _size(0), _head(NULL) {}

            template <class InputIterator>
            map(InputIterator first, InputIterator last) : _size(0), _head(NULL) {
                insert(first, last);
            }

            map(const map & x) :
                _size(0), _head(NULL) {
                insert(x.begin(), x.end());
            }

            ~map() {
                _destroy(_head);
                _size = 0;
            }
//
// content modifiers
// TODO: erase
// debug prints :
// std::cout << "first comp : [" << (*itmp).first << "]" << "[" << val.first << "]" << std::endl;
// std::cout << val.first << " goes right" << std::endl;
// std::cout << val.first << " goes left" << std::endl;
// std::cout << "next comp : [" << (*itmp).first << "]" << "[" << val.first << "]" << std::endl;
// std::cout << "fast " << std::endl;

            std::pair<iterator, bool> insert (const_reference &val) {
                t_node * tn = _create_node(val);
                t_node * nu = _head;
                iterator itmp;
                key_compare comp;

                if (_size == 0) {
                    _head = tn;
                }
                else if (_key_dup(val) == 1) {
                    itmp = begin();
                    while ((*itmp).first != val.first) {
                        itmp++;
                    }
                    return std::pair<iterator, bool>(itmp, false);
                }
                else {
                    itmp = iterator(_head);
                    while (nu->right != tn &&
                           nu->left != tn) {
                        if (comp((*itmp).first, val.first) == 1) {
                            if (nu->right != NULL)
                            {nu = nu->right;}
                            else
                            {nu->right = tn;}
                        }
                        else {
                            if (nu->left != NULL)
                            {nu = nu->left;}
                            else
                            {nu->left = tn;}
                        }
                        itmp.setPtr(nu);
                    }
                }
                tn->parent = nu;
                itmp.setPtr(tn);
                _size++;
                return std::pair<iterator, bool>(itmp, true);
            }

            iterator insert (iterator position, const_reference &val) {
                t_node * n = position.getPtr();
                iterator itmp(n);
                key_compare comp;

                if (_size == 0) {
                    _head = _create_node(val);
                    return (itmp);
                }
                else if (_key_dup(val) == 1) {
                    while ((*itmp).first != val.first) {
                        itmp++;
                    }
                    return (itmp);
                }
                if (comp((*position).first, val.first) == 1) {
                    if (n->right == NULL) {
                        n->right = _create_node(val);
                        n->right->parent = n;
                        _size++;
                        return (iterator(n->right));
                    }
                }
                insert(val);
                return find(val.first);
            }

            template <class InputIterator>
            void insert (InputIterator first, InputIterator last) {
                InputIterator tmp = first;

                while (tmp != last) {
                    insert(*tmp);
                    tmp++;
                }
            }

            // TODO: erase
            void erase(iterator position) {
                t_node * t;
                t_node * tmp;
                t_node * d;

                t = position.getPtr();
                d = t;
                tmp = t->parent;
                if ((t->right != NULL && t->left == NULL) ||
                    (t->right == NULL && t->left != NULL)) {    // onechild
                    if (tmp->right == t) {                      // if right
                        tmp->right = (t->right == NULL) ? t->left : t->right;
                        t = (t->right == NULL) ? t->left : t->right;
                        t->parent = tmp;
                        delete d;
                    }
                    else {                                      // if left
                        tmp->left = (t->right == NULL) ? t->left : t->right;
                        t = (t->right == NULL) ? t->left : t->right;
                        t->parent = tmp;
                        delete d;
                    }
                }
                else if (t->right == NULL && t->left == NULL) { // leaf
                    if (tmp->right == t) {                      // if right
                        tmp->right = NULL;
                        delete d;
                    }
                    else {                                      // if left
                        tmp->left = NULL;
                        delete d;
                    }
                }
                else if (t->right != NULL && t->left != NULL) { // children
                    t_node * ch = _get_child(t);

                    ch->parent->left = NULL;
                    ch->parent->parent = ch;
                    ch->left = t->left;
                    ch->right = t->right;
                    ch->parent = t->parent;
                    delete d;
                }
            }

            void swap(map & x) {
                map tmp(x);

                x.clear();
                x.insert(begin(), end());
                this->clear();
                this->insert(tmp.begin(), tmp.end());
            }

            void clear() {
                _destroy(_head);
                _head = NULL;
                _size = 0;
            }

//
// capacity
//
            size_type max_size()
            {return (pow(2, sizeof(void *) * 8) / sizeof(ft::map<Key, T, Compare>) - 1);}

            size_type size () const {
                size_type s = 0;

                for (iterator it = begin(); it != end(); it++) {
                    s++;
                }
                return s;
            }

            bool empty () const {
                return (_head == NULL);
            }
//
// element access
//
            mapped_type & operator[](const key_type & k) {
                iterator tmp = find(k);

                return (*((this->insert(std::make_pair(k,mapped_type()))).first)).second;
            }
//
// operations
//
            iterator find(const key_type & k) {
                t_node *tmp = _head;
                iterator it(tmp);
                key_compare comp;

                if ((*it).first == k) {
                    return it;
                }
                while (it != end())
                {
                    if ((*it).first == k) {
                        return (it);
                    }
                    else if (comp((*it).first, k) == 1) {
                        tmp = tmp->right;
                    }
                    else {
                        tmp = tmp->left;
                    }
                    it.setPtr(tmp);
                }
                return (end());
            }

            const_iterator find(const key_type &k) const {
                return (const_iterator(find(k)));
            }

            size_type count (const key_type & k) {
                if (find(k) != end())
                {return (1);}
                else
                {return (0);}
            }

            iterator upper_bound (const key_type& k) {
                iterator it = begin();
                key_compare c;
                size_type s = 0;

                while (c(k, (*it).first) == 0) {
                    s++;
                    it++;
                }
                if (s != size())
                {return (it);}
                else
                {return (end());}
            }

            const_iterator upper_bound (const key_type& k) const {
                iterator it = begin();
                key_compare c;
                size_type s = 0;

                while (c((*it).first, k) == 1) {
                    s++;
                    it++;
                }
                if (s != size())
                {return (const_iterator(it.getPtr()));}
                else
                {return (end());}
            }


            iterator lower_bound (const key_type& k) {
                iterator it = begin();
                key_compare c;
                size_type s = 0;

                while (c((*it).first, k) == 1) {
                    s++;
                    it++;
                }
                if (s != size())
                {return (it);}
                else
                {return (end());}
            }

            const_iterator lower_bound (const key_type& k) const {
                iterator it = begin();
                key_compare c;
                size_type s = 0;

                while (c(k, (*it).first) == 0) {
                    s++;
                    it++;
                }
                if (s != size())
                {return (const_iterator(it.getPtr()));}
                else
                {return (end());}
            }
//
// observers
//
            // template <class Key, class T, class Compare>
            // class map<Key, T, Compare>::value_compare
            // {   // TODO: ????
            //     friend class map;
            //     protected:
            //         Compare comp;
            //         value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
            //     public:
            //         typedef bool result_type;
            //         typedef value_type first_argument_type;
            //         typedef value_type second_argument_type;
            //         bool operator() (const value_type& x, const value_type& y) const
            //         {
            //             return comp(x.first, y.first);
            //         }
            // }

            key_compare key_comp() const {
                key_compare kc;
                return (kc);
            }

            // value_compare value_comp() const {
            //     ley_compare kc;
            //     return (value_compare<key_type, value, key_compare>(kc));
            // }
//
// iterators
//

            iterator begin() {
                iterator ite;
                t_node * tmp = _head;

                if (_size == 0 || _head == NULL) {
                    return iterator(_head);
                }
                while (tmp->left != NULL) {
                    tmp = tmp->left;
                }
                ite.setPtr(tmp);
                return (ite);
            }

            const_iterator begin() const {
                t_node * tmp = _head;

                if (_size == 0 || _head == NULL) {
                    return (const_iterator(_head));
                }
                while (tmp->left != NULL) {
                    tmp = tmp->left;
                }
                return (const_iterator(tmp));
            }

            reverse_iterator rbegin() {
                iterator ite;
                t_node * tmp = _head;

                if (_size == 0 || _head == NULL) {
                    return (reverse_iterator(_head));
                }
                while (tmp->right != NULL) {
                    tmp = tmp->right;
                }
                ite.setPtr(tmp);
                return (reverse_iterator(ite.getPtr()));
            }

            reverse_iterator rend()
            {return (reverse_iterator(_head));}

            iterator end() {
                iterator ite;
                t_node * tmp = _head;

                if (_size == 0 || _head == NULL) {
                    return (iterator(_head));
                }
                while (tmp->right != NULL) {
                    tmp = tmp->right;
                }
                ite.setPtr(tmp->right);
                return (ite);
            }

            const_iterator end() const {
                t_node * tmp = _head;

                if (_size == 0 || _head == NULL) {
                    return (const_iterator(_head));
                }
                while (tmp->right != NULL) {
                    tmp = tmp->right;
                }
                return (const_iterator(tmp->right));
            }


        private :
            size_type _size;
            t_node * _head;

//
// private helper functions
//
            t_node * _create_node(const_reference val) {
                t_node * tmp = new t_node(val);

                tmp->parent = NULL;
                tmp->left = NULL;
                tmp->right = NULL;
                return (tmp);
            }

            bool _key_dup(const_reference val) {
                iterator it = begin();

                if ((*it).first == val.first)
                {return (true);}

                while (it != end()) {
                    if ((*it).first == val.first)
                    {return (true);}
                    it++;
                }
                return (false);
            }

            void _destroy(t_node * leaf) {
                if (leaf != NULL) {
                    _destroy(leaf->left);
                    _destroy(leaf->right);
                    delete leaf;
                }
            }

            t_node * _get_child(t_node * t) {
                t_node * next = t;

                next = next->right;
                while (next->left != NULL) {
                    next = next->left;
                }
                return (next);
            }
    };
}

#endif // MAP_H
