#ifndef FT_STACK_H
#define FT_STACK_H

#include <iostream>

namespace ft {
    template <typename T>
    class stack {
        private :
            T * _content;
            int _size;
        public :
            // constructors / destructors
            stack() {
                std::cout << "constructor" << std::endl;
                _content = new T();
                _size = int();
                _content[0] = T();
            }

            ~stack() {
                if (_content != NULL) {
                    delete [] _content;
                }
            }

            // member functions
            void push (T & val) {
                T * tmp;
                int i;

                tmp = new T[_size + 1];
                for (i = 0; i < _size; i++) {
                    tmp[i] = _content[i];
                }
                tmp[i] = val;
                _size++;
                _content = tmp;
            }

            T & top (void) const {
                return (_content[_size - 1]);
            }

            int const & size(void) {
                return (this->_size);
            }
    };
}

#endif // FT_STACK_H
