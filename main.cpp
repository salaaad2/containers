#include <iostream>

#include "inc/list.hpp"
#include "inc/integrals.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    std::cout << ft::is_integral<int>::value << std::endl;
    std::cout << ft::is_integral<ft::list<int>::iterator>::value << std::endl;

    return 0;
}
