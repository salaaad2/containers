#ifndef LIST_H
# define LIST_H

# include <cstddef>
# include <iostream>
# include <math.h>
# include <stdexcept>
# include <typeinfo>

# include "list_iterator.hpp"
# include "list_node.hpp"

namespace ft {
    template <class T> class list {
        public:
            typedef size_t size_type;
            typedef T value_type;
            typedef value_type &reference;
            typedef const value_type &const_reference;
            typedef value_type *pointer;
            typedef const value_type *const_pointer;
            typedef std::ptrdiff_t difference_type;
            typedef list_iterator<value_type> iterator;
            typedef const list_iterator<value_type> const_iterator;
            typedef reverse_list_iterator<value_type> reverse_iterator;
            typedef const reverse_list_iterator<value_type>
            const_reverse_iterator;
            typedef struct l_node<T> t_node;

//
// constructors
//
            explicit list() : _size(0) {
                _end = new t_node;
                _end->data = value_type();
                _end->prev = _end;
                _end->next = _end;
                _begin = _end;
                _size = 0;
            }

            explicit list(size_type n, const value_type &val = value_type()) {
                init_list(n, val, std::true_type());
            }

            template <class InputIterator>
            list(InputIterator first, InputIterator last) {
                typedef typename std::is_integral<InputIterator>::type Integral;
                init_list(first, last, Integral());
            }

            list(const list &x) {
                _begin = new t_node;
                _begin->data = value_type();
                _begin->prev = _end;
                _end = new t_node;
                _end->data = value_type();
                _end->prev = _begin;
                _end->next = _begin;
                _begin->next = _end;
                *this = x;
            }

            ~list() {
                t_node *tmp;
                while (_begin != _end) {
                    tmp = _begin;
                    _begin = _begin->next;
                    delete tmp;
                }
                delete _end;
            }

            list &operator=(const list &x) {
                t_node *tmp;
                t_node *current;
                while (_begin != _end)
                {
                    tmp = _begin;
                    _begin = _begin->next;
                    delete tmp;
                }
                tmp = x._begin;
                _begin = new t_node;
                _begin->data = x._begin->data;
                _begin->prev = _end;
                _begin->next = _end;
                current = _begin;
                _end->next = _begin;
                tmp = tmp->next;
                while (tmp != x._end)
                {
                    current->next = new t_node;
                    current->next->next = _end;
                    current->next->data = tmp->data;
                    current->next->prev = current;
                    tmp = tmp->next;
                    current = current->next;
                }
                _end->prev = current;
                _size = x._size;
                return (*this);
            }
//
// iterators
//

            iterator begin()
            {return (iterator(_begin));}

            const_iterator begin() const
            {return (iterator(_begin));}


            iterator end()
            { return (iterator(_end)); }

            const_iterator end() const
            { return (iterator(_end)); }

            reverse_iterator rbegin()
            { return (reverse_iterator(_end->prev)); }

            const_reverse_iterator rbegin() const
            { return (reverse_iterator(_end->prev)); }


            reverse_iterator rend()
            { return (reverse_iterator(_begin)); }

            const_reverse_iterator rend() const
            { return (reverse_iterator(_begin)); }

//
// capacity
//
            bool empty() const
            { return ((_size == 0) ? true : false); }

            size_type size() const
            {return (_size);}

            size_type max_size() const
            {return (pow(2, sizeof(void *) * 8) / sizeof(ft::list<T>) - 1);}

            reference front()
            { return (_begin->data); }

            const_reference front() const
            { return (_begin->data); }

            reference back()
            { return (_end->data); }

            const_reference back() const
            { return (_end->data); }

//
// content modifiers
//
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last) {
                typedef typename std::is_integral<InputIterator>::type Integral;
                assign_func(first, last, Integral());
            }

            void assign(size_type n, const value_type &val) {
                assign_func(n, val, std::true_type());
            }

            void push_front(const value_type &val) {
                _begin->prev = new t_node;
                _begin->prev->data = val;
                _begin->prev->next = _begin;
                _begin->prev->prev = _end;
                _begin = _begin->prev;
                _end->next = _begin;
                _size++;
            }

            void pop_front() {
                _begin = _begin->next;
                delete _begin->prev;
                _begin->prev = _end;
                _end->next = _begin;
                _size--;
            }


            void push_back(const value_type &val) {
                _end->next = new t_node;
                _end->data = val;
                _end->next->prev = _end;
                _end->next->next = _begin;
                _end->next->data = value_type();
                _end = _end->next;
                _begin->prev = _end;
                _size++;
            }

            void pop_back() {
                _end = _end->prev;
                delete _end->next;
                _end->next = _begin;
                _end->data = value_type();
                _size--;
            }

            iterator insert(iterator position, const value_type &val) {
                t_node *new_node = new t_node;
                t_node *pos = position.getPtr();
                t_node *prev = pos->prev;
                new_node->data = val;
                new_node->next = pos;
                new_node->prev = prev;
                prev->next = new_node;
                pos->prev = new_node;
                _size++;
                if (pos == _begin)
                    _begin = new_node;
                return (iterator(new_node));
            }

            void insert(iterator position, size_type n, const value_type &val) {
                insert_func(position, n, val, std::true_type());
            }

            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last) {
                typedef typename std::is_integral<InputIterator>::type Integral;
                insert_func(position, first, last, Integral());
            }

            iterator erase(iterator position) {
                t_node *current = position.getPtr();
                iterator ret;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                ret.setPtr(current->next);
                if (_begin == current)
                {
                    _begin = current->next;
                    _begin->prev = _end;
                }
                delete current;
                _size--;
                return (ret);
            }

            iterator erase(iterator first, iterator last) {
                t_node *current = first.getPtr();
                t_node *tmp;
                iterator ret;
                while (first != last) {
                    tmp = current;
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    if (_begin == current)
                    {
                        _begin = current->next;
                        _begin->prev = _end;
                    }
                    current = current->next;
                    first++;
                    delete tmp;
                    _size--;
                }
                ret.setPtr(current);
                return (ret);
            }

            void swap(list &x) {
                t_node *tmp;
                size_type tmp_size;
                tmp = _begin;
                _begin = x._begin;
                x._begin = tmp;
                tmp = _end;
                _end = x._end;
                x._end = tmp;
                tmp_size = _size;
                _size = x._size;
                x._size = tmp_size;
            }

            void resize(size_type n, value_type val = value_type()) {
                if (n > _size)
                    while (n > _size)
                        push_back(val);
                else if (n < _size)
                    while (n < _size)
                        pop_back();
            }
            void clear() {
                t_node *tmp;
                while (_begin != _end) {
                    tmp = _begin;
                    _begin = _begin->next;
                    delete tmp;
                }
                _end->next = _end;
                _end->prev = _end;
                _begin = _end;
                _size = 0;
            }

//
// operations
//

            void splice(iterator position, list &x) {
                t_node *pos = position.getPtr();
                t_node *current = pos->prev;

                current->next = x._begin;
                x._begin->prev = current;

                x._end->prev->next = pos;
                pos->prev = x._end->prev;

                if (pos == _begin)
                    _begin = current->next;
                _size += x._size;
                x._size = 0;
                x._end->next = x._end;
                x._end->prev = x._end;
                x._begin = x._end;
            }

            void splice(iterator position, list &x, iterator i) {
                t_node *current = position.getPtr();
                t_node *current_x = i.getPtr();
                t_node *tmp_prev = current->prev;
                if (x._begin == current_x)
                {
                    x._begin = x._begin->next;
                    x._begin->prev = x._end;
                    x._end->next = x._begin;
                }
                current_x->prev->next = current_x->next;
                current_x->next->prev = current_x->prev;
                current->prev = current_x;
                current_x->next = current;
                current_x->prev = tmp_prev;
                tmp_prev->next = current_x;
                x._size--;
                _size++;
                if (position == _begin)
                    _begin = current->prev;
            }

            void splice(iterator position, list &x, iterator first, iterator last) {
                iterator tmp;
                while (first != last)
                {
                    tmp = first;
                    tmp++;
                    splice(position, x, first);
                    first = tmp;
                }
            }

            void remove(const value_type &val) {
                t_node *current = _begin;
                t_node *tmp;
                while (current != _end) {
                    if (current->data == val) {
                        tmp = current->next;
                        erase(iterator(current));
                        current = tmp;
                        continue;
                    }
                    current = current->next;
                }
            }

            template <class Predicate> void remove_if(Predicate pred) {
                t_node *current = _begin;
                t_node *tmp;
                while (current != _end) {
                    if (pred(current->data) == true) {
                        tmp = current->next;
                        erase(iterator(current));
                        current = tmp;
                        continue;
                    }
                    current = current->next;
                }
            }


            void sort()
            {
                t_node *current = _begin->next;
                t_node *tmp;
                while (current != _end)
                {
                    if (current->data < current->prev->data)
                    {
                        current->next->prev = current->prev;
                        current->prev->next = current->next;
                        tmp = current->prev->prev;
                        current->prev->prev = current;
                        current->next = current->prev;
                        current->prev = tmp;
                        tmp->next = current;
                        if (current->next == _begin)
                            _begin = current;
                        current = _begin;
                    }
                    current = current->next;
                }
            }

            template <class Compare>
            void sort (Compare comp)
            {
                t_node *current = _begin->next;
                t_node *tmp;
                while (current != _end)
                {
                    if (comp(current->data, current->prev->data))
                    {
                        current->next->prev = current->prev;
                        current->prev->next = current->next;
                        tmp = current->prev->prev;
                        current->prev->prev = current;
                        current->next = current->prev;
                        current->prev = tmp;
                        tmp->next = current;
                        if (current->next == _begin)
                            _begin = current;
                        current = _begin;
                    }
                    current = current->next;
                }
            }

            void reverse()
            {
                t_node *current = _end->prev;
                t_node *tmp_next;
                t_node *tmp_prev;
                while (current != _end)
                {
                    tmp_next = current->next;
                    tmp_prev = current->prev;;
                    current->next = current->prev;
                    current->prev = current->next;
                    current = tmp_prev;
                }
                tmp_next = _end->next;
                tmp_prev = _end->prev;
                _end->next = tmp_prev;
                _end->prev = tmp_next;
                _end->data = tmp_prev->data;
                _end = _begin->next;
                _begin = tmp_prev;

            }

            void merge (list& x)
            {
                t_node *current = _end->prev;
                t_node *current_x = x._begin;
                while (current_x != x._end)
                {
                    push_back(current_x->data);
                    current_x = current_x->next;
                    current = current->next;
                }
                x.clear();
                current->next = _end;
                _end->prev = current;
            }

            template <class Compare>
            void merge (list& x, Compare comp)
            {
                t_node *current = _end->prev;
                t_node *current_x = x._begin;
                while (current_x != x._end)
                {
                    push_back(current_x->data);
                    current_x = current_x->next;
                    current = current->next;
                }
                x.clear();
                current->next = _end;
                _end->prev = current;
                sort(comp);
            }

            void unique()
            {
                t_node *current = _begin->next;
                t_node *first;
                t_node *last;
                while (current != _end)
                {
                    if (current->prev->data == current->data)
                    {
                        first = current;
                        while (current->next != _end && current->data == current->prev->data)
                            current = current->next;
                        last = current;
                        current = current->next;
                        erase(iterator(first), iterator(last));
                        continue;
                    }
                    current = current->next;
                }
            }

            template <class BinaryPredicate>
            void unique (BinaryPredicate binary_pred)
            {
                t_node *current = _begin->next;
                t_node *first;
                t_node *last;
                while (current != _end)
                {
                    if (binary_pred(current->data, current->prev->data) == true)
                    {
                        first = current;
                        while (current->next != _end && binary_pred(current->data, current->prev->data) == true)
                            current = current->next;
                        if (current->next != _end)
                            current = current->next;
                        last = current;
                        current = current->next;
                        erase(iterator(first), iterator(last));
                        continue;
                    }
                    current = current->next;
                }      }

        private:
            t_node *_begin;
            t_node *_end;
            size_type _size;

//
// helpers / dispatchers

            void init_list(size_type n, const value_type val, std::true_type)  {
                if (n) {
                    t_node *current;
                    _size = n;
                    _begin = new t_node;
                    _end = new t_node;
                    _begin->data = val;
                    _begin->next = _end;
                    _begin->prev = _end;
                    _end->data = value_type();
                    _end->prev = _begin;
                    _end->next = _begin;
                    n--;
                    current = _begin;
                    while (n) {
                        current->next = new t_node;
                        current->next->data = val;
                        current->next->prev = current;
                        current->next->next = _end;
                        current = current->next;
                        _end->prev = current;
                        n--;
                    }
                }
            }

            template <class InputIterator>
            void init_list(InputIterator first, InputIterator last, std::false_type) {
                t_node *current;
                _size = 1;
                _begin = new t_node;
                _end = new t_node;
                _begin->data = *first;
                _begin->next = _end;
                _begin->prev = _end;
                _end->data = value_type();
                _end->prev = _begin;
                _end->next = _begin;
                first++;
                current = _begin;
                while (first != last) {
                    current->next = new t_node;
                    current->next->data = *first;
                    current->next->prev = current;
                    current->next->next = _end;
                    current = current->next;
                    _end->prev = current;
                    first++;
                    _size++;
                }
            }

            void assign_func(size_type n, const value_type val, std::true_type) {
                clear();
                while (n)
                {
                    push_back(val);
                    n--;
                }
            }

            template <class InputIterator>
            void assign_func(InputIterator first, InputIterator last, std::false_type) {
                list<T> new_list;
                while (first != last)
                {
                    new_list.push_back(*first);
                    first++;
                }
                *this = new_list;
            }

            void insert_func(iterator position, size_type n, const value_type val, std::true_type) {
                if (position != begin())
                {
                    t_node *current = position.getPtr();
                    current = current->prev;
                    while (n) {
                        current->next = new t_node;
                        current->next->data = val;
                        current->next->prev = current;
                        current = current->next;
                        n--;
                        _size++;
                    }
                    current->next = position.getPtr();
                    position.getPtr()->prev = current;
                }
                else {
                    while (n) {
                        push_front(val);
                        n--;
                    }
                }
            }

            template <class InputIterator>
            void insert_func(iterator position, InputIterator first, InputIterator last, std::false_type) {
                if (position != begin())
                {
                    t_node *current = position.getPtr();
                    current = current->prev;
                    while (first != last) {
                        current->next = new t_node;
                        current->next->data = *first;
                        current->next->prev = current;
                        current = current->next;
                        first++;
                        _size++;
                    }
                    current->next = position.getPtr();
                    position.getPtr()->prev = current;
                }
                else {
                    while (last-- != first) {
                        push_front(*last);
                    }
                }
            }

            template <class T1>
            friend  bool operator== (const list<T1>& lhs, const list<T1>& rhs);
            template <class T1>
            friend  bool operator!= (const list<T1>& lhs, const list<T1>& rhs);
            template <class T1>
            friend  bool operator<  (const list<T1>& lhs, const list<T1>& rhs);
            template <class T1>
            friend  bool operator<= (const list<T1>& lhs, const list<T1>& rhs);
            template <class T1>
            friend  bool operator>  (const list<T1>& lhs, const list<T1>& rhs);
            template <class T1>
            friend  bool operator>= (const list<T1>& lhs, const list<T1>& rhs);

    };

//
// non member overloads
//

    template <class T>
    void swap(list<T> &l1, list<T> &l2)
    {
        l1.swap(l2);
    }

    template <class T>
    bool operator== (const list<T>& lhs, const list<T>& rhs)
    {
        list_iterator<T> lhs_current = lhs._begin;
        list_iterator<T> rhs_current = rhs._begin;
        if (lhs.size() == rhs.size())
        {
            while (lhs_current != lhs._end)
            {
                if (*lhs_current != *rhs_current)
                    return (false);
                lhs_current++;
                rhs_current++;
            }
            return (true);
        }
        return (false);
    }
    template <class T>
    bool operator!= (const list<T>& lhs, const list<T>& rhs)
    {
        if ((lhs == rhs) == true)
            return (false);
        else
            return (true);
    }
    template <class T>
    bool operator<  (const list<T>& lhs, const list<T>& rhs)
    {
        list_iterator<T> lhs_current = lhs._begin;
        list_iterator<T> rhs_current = rhs._begin;

        if (lhs.size() < rhs.size())
            return (true);
        else if (lhs.size() > rhs.size())
            return (false);
        while (lhs_current != lhs._end)
        {
            if (*lhs_current < *rhs_current)
                return (true);
            lhs_current++;
            rhs_current++;
        }
        return (false);
    }
    template <class T>
    bool operator<= (const list<T>& lhs, const list<T>& rhs)
    {
        list_iterator<T> lhs_current = lhs._begin;
        list_iterator<T> rhs_current = rhs._begin;

        if (lhs.size() > rhs.size())
            return (false);
        while (lhs_current != lhs._end)
        {
            if (*lhs_current > *rhs_current)
                return (false);
            lhs_current++;
            rhs_current++;
        }
        return (true);
    }
    template <class T>
    bool operator>  (const list<T>& lhs, const list<T>& rhs)
    {
        if ((lhs <= rhs) == false)
            return (true);
        return (false);
    }
    template <class T>
    bool operator>= (const list<T>& lhs, const list<T>& rhs)
    {
        if ((lhs < rhs) == false)
            return (true);
        return(false);
    }
} // namespace ft

#endif
