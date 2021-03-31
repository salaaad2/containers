#include "containers.hpp"

int main(void) {
    std::cout << "cool args bro, take a look at them : " << std::endl;
    int value = 15;

    ft::list mylist(2, value);

    mylist.print();
    return (0);
}
