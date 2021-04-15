#ifndef STACK_H
#define STACK_H

#include "vector.hpp"

namespace ft {
    template <class T, class Container = vector<T> > class stack {
        public :
//
// typedefs
//
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;
//
// init
//
            explicit stack (const container_type& ctnr = container_type()) {
                _cont = ctnr;
            }
//
// elements access
//

            void push (const value_type& val) {
                _cont.push_back(val);
            }

            void pop () {
                _cont.pop_back();
            }

            value_type & top() {
                return (_cont.back());
            }

            const value_type & top() const  {
                return (_cont.back());
            }
//
// capacity
//
            bool empty() {
                return (_cont.empty());
            }

            size_type size() {
                return (_cont.size());
            }

        private :
            vector<value_type> _cont;
    };
}

//
// operator overloading
//
template <class T, class Container>
bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs._cont == rhs._cont);
}

template <class T, class Container>
bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs._cont != rhs._cont);
}

template <class T, class Container>
bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs._cont < rhs._cont);
}

template <class T, class Container>
bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs._cont <= rhs._cont);
}

template <class T, class Container>
bool operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs._cont > rhs._cont);
}

template <class T, class Container>
bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs._cont >= rhs._cont);
}

#endif // STACK_H
