#include "containers.hpp"

int main(void) {
    std::cout << "cool args bro, take a look at them : " << std::endl;
    size_t qwe = 9;

    ft::vector<int> unovect;
    ft::vector<int> dosvect(qwe, 200);
    ft::vector<int> trevect(100, 200);
    ft::vector<int> quavect(trevect);

    std::vector<int> svect;


    std::cout << unovect.size() << " " << unovect.capacity() << std::endl;
    std::cout << dosvect.size() << " " << dosvect.capacity() << std::endl;
    std::cout << trevect.size() << " " << trevect.capacity() << std::endl;
    std::cout << quavect.size() << " " << quavect.capacity() << std::endl;
    return (0);
}
