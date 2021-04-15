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

    // std::cout << "print iterators"<< *itb << *ite << std::endl;
    ft::vector<int> cinvect(itb, ite);
    for (size_t i = 0; i < cinvect.size(); i++) {
        std::cout << "[" << cinvect[i] << "]"<< std::endl;
    }
    std::cout << "print iterators"<< *itb << *(ite - 1) << std::endl;
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
    truevect.erase(trueit);
    cinvect.erase(itb);
    std::cout << "itb    after erase : "<< *itb << std::endl;
    std::cout << "trueit after erase : "<< *trueit << std::endl;
    truevect.erase(trueit);
    cinvect.erase(itb);
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
    ft::vector<int> swaptest(1, 12);
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
    std::cout << "-========= assign =========-" << std::endl;
    std::cout << "-before-" << std::endl;
    for (size_t i = 0; i < cinvect.size(); i++) {
        std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
    }
    cinvect.assign(5, 19);
    std::cout << "----\n" << std::endl;
    for (size_t i = 0; i < cinvect.size(); i++) {
        std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
    }
    std::cout << "-========= erase @ end tests HOPE =========-" << std::endl;
     ft::vector<int> ael(6 ,12);
    std::vector<int> bel(6 ,12);
     ft::vector<int>::iterator aeli;
    std::vector<int>::iterator beli;
    aeli = ael.begin();
    beli = bel.begin();
    ael.insert(aeli, 2, 89);
    bel.insert(beli, 2, 89);
    // std::cout << "itb    after insert : "<< *aeli << std::endl;
    // std::cout << "trueit after insert : "<< *beli << std::endl;
    for (size_t i = 0; i < ael.size(); i++) {
        std::cout << i << " [" << ael[i] << "]"<< std::endl;
    }
    std::cout << "----\n" << std::endl;
    for (size_t i = 0; i < bel.size(); i++) {
        std::cout << i << " [" << bel[i] << "]"<< std::endl;
    }
    std::cout << "-========= iterators operators =========-" << std::endl;
    ft::vector<int> vecool(6 ,12);
    ft::vector<int>::iterator itcool;
    ft::vector<int>::iterator itcaal;

    itcool = vecool.begin();
    itcaal = vecool.begin();

    if (itcool >= itcaal) {
        std::cout << "cool is bigger" << std::endl;
    }
    if (itcool <= itcaal) {
        std::cout << "cool is smaller" << std::endl;
    }
    if (itcool != itcaal) {
        std::cout << "cool is different" << std::endl;
    }
    if (itcool == itcaal) {
        std::cout << "cool is the same" << std::endl;
    }
    std::cout << "-========= reverse iterators operators =========-" << std::endl;
    ft::vector<int>::reverse_iterator rit;
    rit = vecool.rbegin();
    for (; rit!= vecool.rend(); ++rit)
    std::cout << *rit << std::endl;

    for (size_t i = 0; i < vecool.size(); i++)
    std::cout << vecool[i] << std::endl;
    std::cout << "-========= reverse iterator fuckery =========-" << std::endl;
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    ft::vector<int>::reverse_iterator v1_it = v1.rbegin();
    ft::vector<int>::reverse_iterator v1_ite = v1.rbegin();
    ft::vector<int>::reverse_iterator tmpit1 = v1.rbegin();

    v1_ite++;
    v1_ite++;
    for (; tmpit1 != v1.rend(); ++tmpit1) {
       std::cout << *tmpit1 << std::endl;
    }
    std::cout <<  "===="<< *v1_it << std::endl;
    std::cout << *v1_ite << std::endl;
    std::cout << (v1_it > v1_ite) << std::endl;
    std::cout << (v1_it < v1_ite) << std::endl;

    std::vector<int> v2(arr1, arr1 + 5);
    std::vector<int>::reverse_iterator v2_it = v2.rbegin();
    std::vector<int>::reverse_iterator v2_ite = v2.rbegin();
    std::vector<int>::reverse_iterator tmpit2 = v2.rbegin();

    v2_ite++;
    v2_ite++;
    for (; tmpit2 != v2.rend(); ++tmpit2) {
       std::cout << *tmpit2 << std::endl;
    }
    std::cout << "===="<<  *v2_it << std::endl;
    std::cout << *v2_ite << std::endl;
    std::cout << (v2_it > v2_ite) << std::endl;
    std::cout << (v2_it < v2_ite) << std::endl;
    std::cout << "-========= push back empty =========-" << std::endl;
    ft::vector<int> vdeux;
    ft::vector<int>::iterator itdeux;

    itdeux = vdeux.insert(vdeux.end(), 42);
    std::cout << *itdeux << std::endl;

    itdeux = vdeux.insert(vdeux.end(), 2);
    std::cout << *itdeux << std::endl;

    itdeux = vdeux.insert(vdeux.end(), 2);
    std::cout << *itdeux << std::endl;

    itdeux = vdeux.insert(vdeux.end(), 19);
    std::cout << *itdeux << std::endl;
    // for (size_t i = 0; i < vdeux.size(); i++)
    // std::cout << vdeux[i] << std::endl;

    return (0);
}
