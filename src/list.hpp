#ifndef FT_LIST_H
#define FT_LIST_H

#include <iostream>
#include <list>

namespace ft {
    template <typename T, typename Alloc = std::allocator<T> >
    class list {
        private :
            struct _node {
                T _content;
                _node * _next;
            };
            _node * _list;
            size_t _size;
        public :
            // constructors / destructors
            list() { }

            list(size_t n, const T & value) : _size(0) {
                _list = new _node[n];

                while (_size < n) {
                    _list[_size]._content = value;
                    _list[_size]._next = (_size == (n - 1)) ? &_list[0] : &_list[_size + 1];
                    _size++;
                    std::cout << "add " << _list[_size - 1]._content << "at index " << _size << std::endl;
                }
            }

            ~list() { }

            // void pop (void) {
            //     if (_content[_size - 1] != NULL) {
            //         delete _content[_size - 1];
            //     }
            // }

            // member functions
            void print(void) {
                _node *ptr = _list[0];

                while (ptr->_next != NULL) {
                    std::cout << "list content : " << _list->_content << std::endl;
                }
            }

            int const & size(void) {
                return (this->_size);
            }
    };
}

#endif // FT_LIST_H
