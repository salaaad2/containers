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
                T * _next;
            };
            _node * _list;
            int _size;
        public :
            // constructors / destructors
            list() { }

            list(size_t n, const T & value) {
                size_t i = 0;
                _list = new _node[n];

                while (i < n) {
                    _list[i]._content = value;
                    _list[i]._next = (i == (n - 1)) ? &_list[0] : &_list[i + 1];
                    _size++;
                }
            }

            ~list() {
                if (_content != NULL) {
                    delete [] _content;
                }
            }

            // void pop (void) {
            //     if (_content[_size - 1] != NULL) {
            //         delete _content[_size - 1];
            //     }
            // }

            // member functions
            void print(void) {
                while (_list->next != &_list[0]) {
                    std::cout << "list content : " << _list->_content << std::endl;
                }
            }

            int const & size(void) {
                return (this->_size);
            }
    };
}

#endif // FT_LIST_H

#endif // LIST_H
