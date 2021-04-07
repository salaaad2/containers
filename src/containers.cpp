#include "containers.hpp"

#include <vector>

int main(void) {
    size_t qwe = 8;

    ft::vector<int> svect;

    ft::vector<int> unovect;
    ft::vector<int> dosvect(qwe, 200);
   std::vector<int> truevect (8, 2);
    ft::vector<int> trevect(8, 2);
    ft::vector<int> quavect(trevect);

    ft::vector<int>::iterator itb = trevect.begin();
    ft::vector<int>::iterator ite = trevect.end();
    std::vector<int>::iterator  trueit;

    std::cout << "print iterators"<< *itb << *ite << std::endl;
    ft::vector<int> cinvect(itb, ite);
    std::cout << "print iterators"<< *itb << *ite << std::endl;
    std::cout << unovect.size() << " " << unovect.capacity() << std::endl;
    std::cout << dosvect.size() << " " << dosvect.capacity() << std::endl;
    std::cout << trevect.size() << " " << trevect.capacity() << std::endl;
    std::cout << quavect.size() << " " << quavect.capacity() << std::endl;
    std::cout << cinvect.size() << " " << cinvect.capacity() << std::endl;
    std::cout << truevect.size() << " " << truevect.capacity() << std::endl;

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

    std::cout << "second print" << std::endl;
    std::cout << "print iterators"<< *itb << *ite << std::endl;

    itb = cinvect.begin();
    cinvect.insert(itb, 42);
    std::cout << cinvect.size() << " " << cinvect.capacity() << std::endl;

    for (size_t i = 0; i < truevect.size(); i++) {
        std::cout << "[" << cinvect[i] << "]"<< std::endl;
    }


    trueit = truevect.begin();
    truevect.insert(trueit, 42);
    std::cout << truevect.size() << " " << truevect.capacity() << std::endl;
    for (size_t i = 0; i < truevect.size(); i++) {
        std::cout << "[" << cinvect[i] << "]"<< std::endl;
    }

    return (0);
}
