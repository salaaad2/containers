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

    std::cout << "my vector" << std::endl;
    itb = cinvect.begin();
    itb++;
    cinvect.insert(itb, 1, 42);
    itb = cinvect.end();
    // std::cout << "add value n times" << spos << n << val << std::endl;
    cinvect.insert(itb, 42);
    for (size_t i = 0; i < cinvect.size(); i++) {
        std::cout << "[" << cinvect[i] << "]"<< std::endl;
    }

   //  std::cout << "-========= important tests =========-" << std::endl;
   //  trueit = truevect.begin();
   //  truevect.insert(trueit, 1, 42);
   //  trueit = truevect.end();
   //  truevect.insert(trueit, 42);
   //  std::cout << "itb    after insert : "<< *itb << std::endl;
   //  std::cout << "trueit after insert : "<< *trueit << std::endl;
   //  std::cout << cinvect.size() << " " << cinvect.capacity() << std::endl;
   //  std::cout << truevect.size() << " " << truevect.capacity() << std::endl;

   //  trueit = truevect.begin();
   //  itb    =  cinvect.begin();
   //  std::cout << "itb    before erase : "<< *itb << std::endl;
   //  std::cout << "trueit before erase : "<< *trueit << std::endl;
   //  truevect.erase(trueit);
   //   cinvect.erase(itb);
   //  std::cout << "itb    after erase : "<< *itb << std::endl;
   //  std::cout << "trueit after erase : "<< *trueit << std::endl;
   //  trueit = truevect.begin();
   //  itb    = cinvect.begin();
   //  truevect.erase(trueit);
   //  cinvect.erase(itb);
   //  std::cout << truevect.size() << " " << truevect.capacity() << std::endl;
   //  std::cout << cinvect.size() << " " << cinvect.capacity() << std::endl;
   //  for (size_t i = 0; i < cinvect.size(); i++) {
   //      std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
   //  }
   //  for (size_t i = 0; i < truevect.size(); i++) {
   //      std::cout << i << " [" << truevect[i] << "]"<< std::endl;
   //  }

   //  std::cout << "-========= reserve tests =========-" << std::endl;
   //  ft::vector<int> foo;
   // std::vector<int> bar;
   //  std::cout << foo.size() << " " << foo.capacity() << std::endl;
   //  std::cout << bar.size() << " " << bar.capacity() << std::endl;

   //  foo.reserve(100);
   //  foo.insert(foo.begin(), 12);
   //  foo.insert(foo.end(), 12);
   //  // for (size_t i = 0; i < 100; i++) {foo.insert(foo.end(), 21);}
   //  bar.reserve(100);
   //  for (size_t i = 0; i < 100; i++) {bar.insert(bar.end(), 21);}
   //  std::cout << foo.size() << " " << foo.capacity() << std::endl;
   //  std::cout << bar.size() << " " << bar.capacity() << std::endl;

    return (0);
}
