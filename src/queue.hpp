#ifndef QUEUE_H
#define QUEUE_H

#include "vector.hpp"

namespace ft {
    template <class T, class Container = vector<T> > class queue {
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
            explicit queue (const container_type& ctnr = container_type()) {
                _cont = ctnr;
            }
//
// elements access
//

            void push (const value_type& val) {
                _cont.push_back(val);
            }

            void pop () {
                _cont._erase(_cont.begin(), 1);
            }

            value_type & back() {
                return (_cont.back());
            }

            const value_type & back() const  {
                return (_cont.back());
            }

            value_type & front() {
                return (_cont.front());
            }

            const value_type & front() const  {
                return (_cont.front());
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
bool operator== (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
{
    return (lhs._cont == rhs._cont);
}

template <class T, class Container>
bool operator!= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
{
    return (lhs._cont != rhs._cont);
}

template <class T, class Container>
bool operator<  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
{
    return (lhs._cont < rhs._cont);
}

template <class T, class Container>
bool operator<= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
{
    return (lhs._cont <= rhs._cont);
}

template <class T, class Container>
bool operator>  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
{
    return (lhs._cont > rhs._cont);
}

template <class T, class Container>
bool operator>= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
{
    return (lhs._cont >= rhs._cont);
}

#endif // QUEUE_H
