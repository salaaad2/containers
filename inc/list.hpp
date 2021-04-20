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
// TODO: 2 more constructors, delete 1 more node
            explicit list () :
                _first(NULL), _last(NULL)
            {
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

            //TODO: clear
            //
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
// TODO const & = assign delete ???


            void clear() {
                iterator tmp = begin();

                while (tmp != end()) {
                    erase(tmp);
                    tmp++;
                }
            }

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
// template <class InputIterator>
//     void insert (iterator position, InputIterator first, InputIterator last);
//     TODO: delete

            iterator erase(iterator position) {
                iterator it = begin();
                t_node * tmp = _first;

                if (position == begin()) {
                    pop_front();
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
                position++;
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
                return (position);
            }
            // iterator erase(iterator first, iterator last) {
            // }



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
                    delete _last;
                    _last = _last->prev;
                }
            }
//
// capacity
//
            void resize(size_type n, value_type val = value_type()) {
                size_type spos = 0;
                t_node * ptr = _first;
                t_node * tmp;

                if (n < size()) { // del n +
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
                else if (n > size()){ // add size - n vals
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

            size_type empty() {
                return (_first == NULL);
            }
//
// iterators
//

            iterator begin() {
                return (iterator(_first));
            }

            iterator end() {
                return (iterator(_last->next));
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
    };
}

#endif // LIST_H
