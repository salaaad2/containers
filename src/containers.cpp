#include "containers.hpp"

int main(void) {
    std::cout << "cool args bro, take a look at them : " << std::endl;
    ft::stack<int> * mystack = new ft::stack<int>();

    mystack->push(1);
    mystack->push(2);
    mystack->push(3);
    mystack->push(4);
    std::cout << mystack->top() << std::endl;
    return (0);
}
