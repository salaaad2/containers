#include "containers.hpp"

#include <vector>

int main(void) {
    size_t qwe = 9;

    std::vector<int> truevect (100, 2);
    ft::vector<int> svect;

    ft::vector<int> unovect;
    ft::vector<int> dosvect(qwe, 200);
    ft::vector<int> trevect(100, 2);
    ft::vector<int> quavect(trevect);

    ft::vector<int>::iterator itb = trevect.begin();
    ft::vector<int>::iterator ite = trevect.end();

    ft::vector<int> cinvect(itb, ite);
    std::cout << *itb << *ite << std::endl;
    std::cout << unovect.size() << " " << unovect.capacity() << std::endl;
    std::cout << dosvect.size() << " " << dosvect.capacity() << std::endl;
    std::cout << trevect.size() << " " << trevect.capacity() << std::endl;
    std::cout << quavect.size() << " " << quavect.capacity() << std::endl;
    std::cout << cinvect.size() << " " << cinvect.capacity() << std::endl;

    try {
        truevect.at(10000) = 12;
        cinvect[100] = 12;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    for (size_t i = 0; i < cinvect.size(); i++) {
        std::cout << "[" << cinvect[i] << "]"<< std::endl;
    }

    return (0);
}
