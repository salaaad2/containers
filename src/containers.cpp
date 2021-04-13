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
   std::vector<int>::iterator trueit;

   std::cout << "print iterators"<< *itb << *ite << std::endl;
    ft::vector<int> cinvect(itb, ite);
    for (size_t i = 0; i < cinvect.size(); i++) {
        std::cout << "[" << cinvect[i] << "]"<< std::endl;
    }
    std::cout << "print iterators"<< *itb << *ite << std::endl;
    std::cout << unovect.size() << " " << unovect.capacity() << std::endl;
    std::cout << dosvect.size() << " " << dosvect.capacity() << std::endl;
    std::cout << trevect.size() << " " << trevect.capacity() << std::endl;
    std::cout << quavect.size() << " " << quavect.capacity() << std::endl;
    std::cout << cinvect.size() << " " << cinvect.capacity() << std::endl;
    std::cout << truevect.size() << " " << truevect.capacity() << std::endl;
    std::cout << "-========= insert tests =========-" << std::endl;
    std::cout << "true vector" << std::endl;
    trueit = truevect.begin();
    trueit++;
    truevect.insert(trueit, 3, 42);
    trueit = truevect.end();
    truevect.insert(trueit, 42);

    std::cout << "my vector" << std::endl;
    itb = cinvect.begin();
    itb++;
    cinvect.insert(itb, 3, 42);
    itb = cinvect.end();
    cinvect.insert(itb, 42);
    std::cout << "itb    after insert : "<< *itb << std::endl;
    std::cout << "trueit after insert : "<< *trueit << std::endl;
    std::cout << cinvect.size() << " " << cinvect.capacity() << std::endl;
    std::cout << truevect.size() << " " << truevect.capacity() << std::endl;
    for (size_t i = 0; i < cinvect.size(); i++) {
        std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
    }
    std::cout << "----\n" << std::endl;
    for (size_t i = 0; i < truevect.size(); i++) {
        std::cout << i << " [" << truevect[i] << "]"<< std::endl;
    }

    std::cout << "-========= erase/iter tests =========-" << std::endl;
    trueit = truevect.begin();
    itb    =  cinvect.begin();
    std::cout << "itb    before erase : "<< *itb << std::endl;
    std::cout << "trueit before erase : "<< *trueit << std::endl;
    trueit++;
    itb++;
    trueit = truevect.erase(trueit);
    itb =     cinvect.erase(itb);
    std::cout << "itb    after erase : "<< *itb << std::endl;
    std::cout << "trueit after erase : "<< *trueit << std::endl;
    trueit = truevect.erase(trueit);
    itb =     cinvect.erase(itb);
    ft::vector<int>::iterator asd = itb;
    asd += 3;
    std::cout << *asd << "\n";
    std::cout << *itb << "\n";
    cinvect.erase(itb, asd);
    truevect.erase(trueit, trueit + 3);
    for (size_t i = 0; i < cinvect.size(); i++) {
        std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
    }
    std::cout << "----\n" << std::endl;
    for (size_t i = 0; i < truevect.size(); i++) {
        std::cout << i << " [" << truevect[i] << "]"<< std::endl;
    }

    std::cout << "-========= erase @ end tests =========-" << std::endl;
    trueit = truevect.end();
    itb    =  cinvect.end();
    trueit--;
    itb--;
    trueit = truevect.erase(trueit);
    itb =     cinvect.erase(itb);
    for (size_t i = 0; i < cinvect.size(); i++) {
        std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
    }
    std::cout << "----\n" << std::endl;
    for (size_t i = 0; i < truevect.size(); i++) {
        std::cout << i << " [" << truevect[i] << "]"<< std::endl;
    }
    std::cout << "-========= push/pop _back tests =========-" << std::endl;
     truevect.pop_back();
      cinvect.pop_back();
     truevect.push_back(90);
      cinvect.push_back(90);
     truevect.pop_back();
      cinvect.pop_back();
    for (size_t i = 0; i < cinvect.size(); i++) {
        std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
    }
    std::cout << "----\n" << std::endl;
    for (size_t i = 0; i < truevect.size(); i++) {
        std::cout << i << " [" << truevect[i] << "]"<< std::endl;
    }
    std::cout << "-========= reserve tests =========-" << std::endl;
    ft::vector<int> foo;
   std::vector<int> bar;
    std::cout << foo.size() << " " << foo.capacity() << std::endl;
    std::cout << bar.size() << " " << bar.capacity() << std::endl;

    foo.reserve(100);
    for (size_t i = 0; i < 8; i++) {foo.push_back(21);}
    bar.reserve(100);
    for (size_t i = 0; i < 8; i++) {bar.push_back(21);}
    std::cout << foo.size() << " " << foo.capacity() << std::endl;
    std::cout << bar.size() << " " << bar.capacity() << std::endl;

    std::cout << "-========= clear tests =========-" << std::endl;
    for (size_t i = 0; i < foo.size(); i++) {
        std::cout << i << " [" << foo[i] << "]"<< std::endl;
    }
    std::cout << "----\n" << std::endl;
    for (size_t i = 0; i < bar.size(); i++) {
        std::cout << i << " [" << bar[i] << "]"<< std::endl;
    }
    foo.clear();
    bar.clear();
    std::cout << bar.size() << " " << bar.capacity() << std::endl;
    std::cout << foo.size() << " " << foo.capacity() << std::endl;
    for (size_t i = 0; i < foo.size(); i++) {
        std::cout << i << " [" << foo[i] << "]"<< std::endl;
    }
    std::cout << "----\n" << std::endl;
    for (size_t i = 0; i < bar.size(); i++) {
        std::cout << i << " [" << bar[i] << "]"<< std::endl;
    }
    std::cout << "-========= swap =========-" << std::endl;
    std::cout << "-cinvect :: --" << std::endl;
    for (size_t i = 0; i < cinvect.size(); i++) {
        std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
    }
    std::cout << "-swaptest :: --" << std::endl;
    ft::vector<int> swaptest(cinvect.begin(), cinvect.end());
    swaptest.insert(swaptest.end(), 12);
    swaptest.insert(swaptest.end(), 12);
    swaptest.insert(swaptest.end(), 12);
    for (size_t i = 0; i < swaptest.size(); i++) {
        std::cout << i << " [" << swaptest[i] << "]"<< std::endl;
    }
    swaptest.swap(cinvect);
    std::cout << "-post :: --" << std::endl;
    for (size_t i = 0; i < cinvect.size(); i++) {
        std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
    }
    std::cout << "----\n" << std::endl;
    for (size_t i = 0; i < swaptest.size(); i++) {
        std::cout << i << " [" << swaptest[i] << "]"<< std::endl;
    }
    // std::cout << "-========= erase =========-" << std::endl;
    // truevect.insert(truevect.end(), 12);
    //  cinvect.insert(cinvect.end(), 12);
    // for (size_t i = 0; i < cinvect.size(); i++) {
    //     std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
    // }
    // std::cout << "----\n" << std::endl;
    // for (size_t i = 0; i < truevect.size(); i++) {
    //     std::cout << i << " [" << truevect[i] << "]"<< std::endl;
    // }
    return (0);
}
