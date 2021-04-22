#include "../inc/containers.hpp"

int main(void)
{
   //  size_t qwe = 8;

   //  ft::vector<int> svect;

   //  ft::vector<int> unovect;
   //  ft::vector<int> dosvect(qwe, 200);
   // std::vector<int> truevect (8, 2);
   //  ft::vector<int> trevect(8, 2);
   //  ft::vector<int> quavect(trevect);

   //  ft::vector<int>::iterator itb = trevect.begin();
   //  ft::vector<int>::iterator ite = trevect.end();
   //  std::vector<int>::iterator trueit;

   //  // std::cout << "print iterators"<< *itb << *ite << std::endl;
   //  ft::vector<int> cinvect(itb, ite);
   //  for (size_t i = 0; i < cinvect.size(); i++) {
   //      std::cout << "[" << cinvect[i] << "]"<< std::endl;
   //  }
   //  std::cout << "print iterators"<< *itb << *(ite - 1) << std::endl;
   //  std::cout << unovect.size() << " " << unovect.capacity() << std::endl;
   //  std::cout << dosvect.size() << " " << dosvect.capacity() << std::endl;
   //  std::cout << trevect.size() << " " << trevect.capacity() << std::endl;
   //  std::cout << quavect.size() << " " << quavect.capacity() << std::endl;
   //  std::cout << cinvect.size() << " " << cinvect.capacity() << std::endl;
   //  std::cout << truevect.size() << " " << truevect.capacity() << std::endl;
   //  std::cout << "-========= insert tests =========-" << std::endl;
   //  std::cout << "true vector" << std::endl;
   //  trueit = truevect.begin();
   //  trueit++;
   //  truevect.insert(trueit, 3, 42);
   //  trueit = truevect.end();
   //  truevect.insert(trueit, 42);

   //  std::cout << "my vector" << std::endl;
   //  itb = cinvect.begin();
   //  itb++;
   //  cinvect.insert(itb, 3, 42);
   //  itb = cinvect.end();
   //  cinvect.insert(itb, 42);
   //  std::cout << "itb    after insert : "<< *itb << std::endl;
   //  std::cout << "trueit after insert : "<< *trueit << std::endl;
   //  std::cout << cinvect.size() << " " << cinvect.capacity() << std::endl;
   //  std::cout << truevect.size() << " " << truevect.capacity() << std::endl;
   //  for (size_t i = 0; i < cinvect.size(); i++) {
   //      std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
   //  }
   //  std::cout << "----\n" << std::endl;
   //  for (size_t i = 0; i < truevect.size(); i++) {
   //      std::cout << i << " [" << truevect[i] << "]"<< std::endl;
   //  }

   //  std::cout << "-========= erase/iter tests =========-" << std::endl;
   //  trueit = truevect.begin();
   //  itb    =  cinvect.begin();
   //  std::cout << "itb    before erase : "<< *itb << std::endl;
   //  std::cout << "trueit before erase : "<< *trueit << std::endl;
   //  trueit++;
   //  itb++;
   //  truevect.erase(trueit);
   //  cinvect.erase(itb);
   //  std::cout << "itb    after erase : "<< *itb << std::endl;
   //  std::cout << "trueit after erase : "<< *trueit << std::endl;
   //  truevect.erase(trueit);
   //  cinvect.erase(itb);
   //  ft::vector<int>::iterator asd = itb;
   //  asd += 3;
   //  std::cout << *asd << "\n";
   //  std::cout << *itb << "\n";
   //  cinvect.erase(itb, asd);
   //  truevect.erase(trueit, trueit + 3);
   //  for (size_t i = 0; i < cinvect.size(); i++) {
   //      std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
   //  }
   //  std::cout << "----\n" << std::endl;
   //  for (size_t i = 0; i < truevect.size(); i++) {
   //      std::cout << i << " [" << truevect[i] << "]"<< std::endl;
   //  }

   //  std::cout << "-========= erase @ end tests =========-" << std::endl;
   //  trueit = truevect.end();
   //  itb    =  cinvect.end();
   //  trueit--;
   //  itb--;
   //  trueit = truevect.erase(trueit);
   //  itb =     cinvect.erase(itb);
   //  for (size_t i = 0; i < cinvect.size(); i++) {
   //      std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
   //  }
   //  std::cout << "----\n" << std::endl;
   //  for (size_t i = 0; i < truevect.size(); i++) {
   //      std::cout << i << " [" << truevect[i] << "]"<< std::endl;
   //  }
   //  std::cout << "-========= push/pop _back tests =========-" << std::endl;
   //  truevect.pop_back();
   //  cinvect.pop_back();
   //  truevect.push_back(90);
   //  cinvect.push_back(90);
   //  truevect.pop_back();
   //  cinvect.pop_back();
   //  for (size_t i = 0; i < cinvect.size(); i++) {
   //      std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
   //  }
   //  std::cout << "----\n" << std::endl;
   //  for (size_t i = 0; i < truevect.size(); i++) {
   //      std::cout << i << " [" << truevect[i] << "]"<< std::endl;
   //  }
   //  std::cout << "-========= reserve tests =========-" << std::endl;
   //  ft::vector<int> foo;
   //  std::vector<int> bar;
   //  std::cout << foo.size() << " " << foo.capacity() << std::endl;
   //  std::cout << bar.size() << " " << bar.capacity() << std::endl;

   //  foo.reserve(100);
   //  for (size_t i = 0; i < 8; i++) {foo.push_back(21);}
   //  bar.reserve(100);
   //  for (size_t i = 0; i < 8; i++) {bar.push_back(21);}
   //  std::cout << foo.size() << " " << foo.capacity() << std::endl;
   //  std::cout << bar.size() << " " << bar.capacity() << std::endl;

   //  std::cout << "-========= clear tests =========-" << std::endl;
   //  for (size_t i = 0; i < foo.size(); i++) {
   //      std::cout << i << " [" << foo[i] << "]"<< std::endl;
   //  }
   //  std::cout << "----\n" << std::endl;
   //  for (size_t i = 0; i < bar.size(); i++) {
   //      std::cout << i << " [" << bar[i] << "]"<< std::endl;
   //  }
   //  foo.clear();
   //  bar.clear();
   //  std::cout << bar.size() << " " << bar.capacity() << std::endl;
   //  std::cout << foo.size() << " " << foo.capacity() << std::endl;
   //  for (size_t i = 0; i < foo.size(); i++) {
   //      std::cout << i << " [" << foo[i] << "]"<< std::endl;
   //  }
   //  std::cout << "----\n" << std::endl;
   //  for (size_t i = 0; i < bar.size(); i++) {
   //      std::cout << i << " [" << bar[i] << "]"<< std::endl;
   //  }
   //  std::cout << "-========= swap =========-" << std::endl;
   //  std::cout << "-cinvect :: --" << std::endl;
   //  for (size_t i = 0; i < cinvect.size(); i++) {
   //      std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
   //  }
   //  std::cout << "-swaptest :: --" << std::endl;
   //  ft::vector<int> swaptest(1, 12);
   //  swaptest.insert(swaptest.end(), 12);
   //  swaptest.insert(swaptest.end(), 12);
   //  swaptest.insert(swaptest.end(), 12);
   //  for (size_t i = 0; i < swaptest.size(); i++) {
   //      std::cout << i << " [" << swaptest[i] << "]"<< std::endl;
   //  }
   //  swaptest.swap(cinvect);
   //  std::cout << "-post :: --" << std::endl;
   //  for (size_t i = 0; i < cinvect.size(); i++) {
   //      std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
   //  }
   //  std::cout << "----\n" << std::endl;
   //  for (size_t i = 0; i < swaptest.size(); i++) {
   //      std::cout << i << " [" << swaptest[i] << "]"<< std::endl;
   //  }
   //  std::cout << "-========= assign =========-" << std::endl;
   //  std::cout << "-before-" << std::endl;
   //  for (size_t i = 0; i < cinvect.size(); i++) {
   //      std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
   //  }
   //  cinvect.assign(5, 19);
   //  std::cout << "----\n" << std::endl;
   //  for (size_t i = 0; i < cinvect.size(); i++) {
   //      std::cout << i << " [" << cinvect[i] << "]"<< std::endl;
   //  }
   //  std::cout << "-========= erase @ end tests HOPE =========-" << std::endl;
   //   ft::vector<int> ael(6 ,12);
   //  std::vector<int> bel(6 ,12);
   //   ft::vector<int>::iterator aeli;
   //  std::vector<int>::iterator beli;
   //  aeli = ael.begin();
   //  beli = bel.begin();
   //  ael.insert(aeli, 2, 89);
   //  bel.insert(beli, 2, 89);
   //  // std::cout << "itb    after insert : "<< *aeli << std::endl;
   //  // std::cout << "trueit after insert : "<< *beli << std::endl;
   //  for (size_t i = 0; i < ael.size(); i++) {
   //      std::cout << i << " [" << ael[i] << "]"<< std::endl;
   //  }
   //  std::cout << "----\n" << std::endl;
   //  for (size_t i = 0; i < bel.size(); i++) {
   //      std::cout << i << " [" << bel[i] << "]"<< std::endl;
   //  }
   //  std::cout << "-========= iterators operators =========-" << std::endl;
   //  ft::vector<int> vecool(6 ,12);
   //  ft::vector<int>::iterator itcool;
   //  ft::vector<int>::iterator itcaal;

   //  itcool = vecool.begin();
   //  itcaal = vecool.begin();

   //  if (itcool >= itcaal) {
   //      std::cout << "cool is bigger" << std::endl;
   //  }
   //  if (itcool <= itcaal) {
   //      std::cout << "cool is smaller" << std::endl;
   //  }
   //  if (itcool != itcaal) {
   //      std::cout << "cool is different" << std::endl;
   //  }
   //  if (itcool == itcaal) {
   //      std::cout << "cool is the same" << std::endl;
   //  }
   //  std::cout << "-========= reverse iterators operators =========-" << std::endl;
   //  ft::vector<int>::reverse_iterator rit;
   //  rit = vecool.rbegin();
   //  for (; rit!= vecool.rend(); ++rit)
   //  std::cout << *rit << std::endl;

   //  for (size_t i = 0; i < vecool.size(); i++)
   //  std::cout << vecool[i] << std::endl;
   //  std::cout << "-========= reverse iterator fuckery =========-" << std::endl;
   //  int             arr1[5] = {1, 2, 3, 4, 5};
   //  ft::vector<int> v1(arr1, arr1 + 5);
   //  ft::vector<int>::reverse_iterator v1_it = v1.rbegin();
   //  ft::vector<int>::reverse_iterator v1_ite = v1.rbegin();
   //  ft::vector<int>::reverse_iterator tmpit1 = v1.rbegin();

   //  v1_ite++;
   //  v1_ite++;
   //  for (; tmpit1 != v1.rend(); ++tmpit1) {
   //     std::cout << *tmpit1 << std::endl;
   //  }
   //  std::cout <<  "===="<< *v1_it << std::endl;
   //  std::cout << *v1_ite << std::endl;
   //  std::cout << (v1_it > v1_ite) << std::endl;
   //  std::cout << (v1_it < v1_ite) << std::endl;

   //  std::vector<int> v2(arr1, arr1 + 5);
   //  std::vector<int>::reverse_iterator v2_it = v2.rbegin();
   //  std::vector<int>::reverse_iterator v2_ite = v2.rbegin();
   //  std::vector<int>::reverse_iterator tmpit2 = v2.rbegin();

   //  v2_ite++;
   //  v2_ite++;
   //  for (; tmpit2 != v2.rend(); ++tmpit2) {
   //     std::cout << *tmpit2 << std::endl;
   //  }
   //  std::cout << "===="<<  *v2_it << std::endl;
   //  std::cout << *v2_ite << std::endl;
   //  std::cout << (v2_it > v2_ite) << std::endl;
   //  std::cout << (v2_it < v2_ite) << std::endl;
   //  std::cout << "-========= push back empty =========-" << std::endl;
   //  ft::vector<int> vdeux;
   //  ft::vector<int>::iterator itdeux;

   //  itdeux = vdeux.insert(vdeux.end(), 42);
   //  std::cout << *itdeux << std::endl;

   //  itdeux = vdeux.insert(vdeux.end(), 2);
   //  std::cout << *itdeux << std::endl;

   //  itdeux = vdeux.insert(vdeux.end(), 2);
   //  std::cout << *itdeux << std::endl;

   //  itdeux = vdeux.insert(vdeux.end(), 19);
   //  std::cout << *itdeux << std::endl;
   //  for (size_t i = 0; i < vdeux.size(); i++)
   //  std::cout << vdeux[i] << std::endl;

   //  std::cout << "#===================================#" << std::endl;
   //  std::cout << "#============== stack ==============#" << std::endl;
   //  std::cout << "#===================================#" << std::endl;
   //  ft::stack<int> coolstack;

   //  coolstack.push(1);
   //  coolstack.push(2);
   //  coolstack.push(3);
   //  coolstack.push(5);
   //  coolstack.push(5);
   //  coolstack.push(5);
   //  while (!coolstack.empty())
   //  {
   //      std::cout << coolstack.top() << std::endl;
   //      coolstack.pop();
   //  }
   //  std::cout << "#===================================#" << std::endl;
   //  std::cout << "#============== queue ==============#" << std::endl;
   //  std::cout << "#===================================#" << std::endl;
   //  ft::queue<int> coolqueue;


   //  coolqueue.push(12);
   //  coolqueue.push(75);
   //  coolqueue.back() -= coolqueue.front();

   //  std::cout << "myqueue.back() is now " << coolqueue.back() << '\n';
   std::cout << "#===================================#" << std::endl;
   std::cout << "#============== LIST ===============#" << std::endl;
   std::cout << "#===================================#" << std::endl;
   std::cout << "-========= insert =========-" << std::endl;
   ft::list<int> mylist(5, 12);

   ft::list<int>::iterator it;
   ft::list<int>::iterator itmp;

   it = mylist.begin();
   mylist.insert(it, 1, 100);
   for (itmp = mylist.begin(); itmp != mylist.end() ; itmp++) {
      std::cout << "[" << *itmp << "]\n";
   }

   it = mylist.begin();
   it++;
   it++;
   mylist.insert(it, 4, 213);
   std::cout << "[------]\n";
   for (itmp = mylist.begin(); itmp != mylist.end() ; itmp++) {
      std::cout << "[" << *itmp << "]\n";
   }
   std::cout << "-========= erase + resize =========-" << std::endl;
   ft::list<int> resizeme(2, 1);
  it = resizeme.begin();
   resizeme.insert(it, 2, 88);
  std::cout << "[" << resizeme.size() << "] it : " << *it << std::endl;

   for (itmp = resizeme.begin(); itmp != resizeme.end(); itmp++) {
      std::cout << "[" << *itmp << "]\n";
   }

   std::cout << "-========= erase =========-" << std::endl;
   std::list<int> tlist(5, 12);
   std::list<int>::iterator itt = tlist.begin();
   mylist.assign(5, 12);
   it = mylist.begin();
   it++;
   it = mylist.erase(it);
   it = mylist.erase(it);
  itt++;
   itt = tlist.erase(itt);
   itt = tlist.erase(itt);
   for (it = mylist.begin(); it != mylist.end(); it++) {
      std::cout << "[" << *it << "]\n";
   }
   std::cout << "[-------]\n";
   for (itt = tlist.begin(); itt != tlist.end(); itt++) {
      std::cout << "[" << *itt << "]\n";
   }
   std::cout << "-========= sort =========-" << std::endl;
   ft::list<int> sortme(5, 1);
   ft::list<int>::iterator sortit;

   sortme.push_front(1);
   sortme.push_front(3);
   sortme.push_front(4);
   sortme.push_front(2);
   sortme.push_front(5);
   //
   sortit = sortme.begin();

   sortit++;
   sortit++;
   sortme.insert(sortit, 2, 12);
   sortit--;
   sortme.insert(sortit, 1, 9);

   sortme.sort();
   for (sortit = sortme.begin(); sortit != sortme.end(); sortit++) {
      std::cout << "[" << *sortit << "]\n";
   }
   std::cout << "[-------]\n";
   std::cout << "-========= remove =========-" << std::endl; // TODO: SEGV
   ft::list<int> rmrf(1, 1);
   rmrf.push_front(5);
   rmrf.push_front(5);
   rmrf.push_front(4);
   rmrf.push_front(3);
   rmrf.push_front(5);
   rmrf.push_front(5);
   rmrf.push_front(5);
   rmrf.push_front(5);
   rmrf.push_front(5);
   rmrf.push_front(2);
   rmrf.push_back(1);
   rmrf.push_back(90);

   rmrf.remove(5);
   // rmrf.erase(rmrf.end());
   //rmrf.pop_back();
   for (ft::list<int>::iterator qwe = rmrf.begin(); qwe != rmrf.end(); qwe++) {
      std::cout << "[" << *qwe << "]\n";
   }

   std::cout << "-========= unique =========-" << std::endl;

   ft::list<double> uni(4, 5);
   ft::list<double>::iterator unit = uni.begin();

   // unit = uni.erase(unit);
   // unit = uni.erase(unit);
   // unit = uni.erase(unit);
   uni.push_back(1);
   uni.push_back(1);
   uni.push_back(1);
   uni.push_back(1);
   uni.push_back(1);
   uni.push_back(1);
   uni.push_back(2);
   uni.push_back(2);
   uni.push_back(2);
   uni.push_back(2);
   uni.push_back(2);
   uni.push_back(2);
   uni.push_back(2);
   uni.push_back(3);
   uni.push_back(3);
   uni.push_back(3);
   uni.push_back(3);
   uni.push_back(3);
   uni.push_back(3);
   uni.push_back(3);
   uni.push_back(3);
   uni.unique();
   for (ft::list<double>::iterator qwe = uni.begin(); qwe != uni.end(); qwe++) {
      std::cout << "[" << *qwe << "]\n";
   }
   std::cout << "-========= splice =========-" << std::endl; // TODO: SEGV
   ft::list<int> spl1(5, 1);
   ft::list<int> spl2(8, 5);
   ft::list<int>::iterator split1 = spl1.begin();
   ft::list<int>::iterator split2 = spl2.begin();

   split1++;
   split2++;
   split2++;
   split2++;
   split2++;
   spl1.splice(split1, spl2, split2);
   for (split1 = spl1.begin(); split1 != spl1.end(); split1++) {
      std::cout << "[" << *split1 << "]\n";
   }
   if (spl2.empty()) {
      std::cout << "empty" << std::endl;
   }
   else {
      std::cout << "{" << spl2.size() << "}" << std::endl;
   }

   return (0);
}
