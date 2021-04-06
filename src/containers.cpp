#include "containers.hpp"

int main(void) {
    std::cout << "cool args bro, take a look at them : " << std::endl;

    ft::vector<int> unovect;
    ft::vector<int> dosvect(9, 200);

    std::vector<int> svect;


    std::cout << unovect.size() << unovect.capacity() << std::endl;
    std::cout << dosvect.size() << dosvect.capacity() << std::endl;
    return (0);
}
