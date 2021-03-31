#include "containers.hpp"

int main(void) {
    std::cout << "cool args bro, take a look at them : " << std::endl;
    int value = 15;

    ft::list<int, std::allocator<int> > qwe(2, value);

    qwe.print();
    return (0);
}
