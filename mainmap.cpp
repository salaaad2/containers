/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:34:53 by user42            #+#    #+#             */
/*   Updated: 2020/11/02 12:51:59 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <map>
#include "inc/map.hpp"
template <class T>
void display(T &m)
{
  std::cout << "map:\n";
  for (typename T::iterator it = m.begin(); it != m.end(); it++)
  {
    std::cout << "key : " << (*it).first
              << " , value : " << (*it).second << std::endl;
  }
  std::cout << "map backwards:\n";
  for (typename T::reverse_iterator rit = m.rbegin(); rit != m.rend(); ++rit)
  {
    std::cout << "key : " << (*rit).first
              << " , value : " << (*rit).second << std::endl;
  }
  std::cout << '\n';
}
template <class T>
void display2(T &m)
{
  std::cout << "map:\n";
  for (typename T::iterator it = m.begin(); it != m.end(); it++)
  {
    std::cout << "key : " << (*it).first
              << " , value : " << (*it).second << std::endl;
  }
  std::cout << "map backwards:\n";
  for (typename T::reverse_iterator rit = m.rbegin(); rit != m.rend(); ++rit)
  {
    std::cout << "key : " << (*rit).first
              << " , value : " << (*rit).second << std::endl;
  }
  std::cout << '\n';
}template < class Integer >
void is_same(Integer b1, Integer b2)
{
  if (b1 == b2)
    std::cout << "\x1B[32m[OK]\033[0m (" << b1 << ")\n";
  else
    std::cout << "\x1B[31m[KO]\033[0m (" << b1 << " instead of " << b2 << ")\n";
}void is_same(bool b)
{
  if (b)
    std::cout << "\x1B[32m[OK]\033[0m\n";
  else
    std::cout << "\x1B[31m[KO]\033[0m\n";
}template <class T1, class T2>
void debuger(T1 &f, T2 &f2)
{
  display(f);
  display2(f2);  std::cout << "size:" << '\t';
  is_same(f.size(), f2.size());
  std::cout << "empty:" << '\t';
  is_same(f.empty(), f2.empty());
}template < class T1, class T2 >
bool checker(T1 &f, T2 &f2, bool debug = false)
{
  if (debug)
    debuger(f, f2);
  if (f.size() != f2.size())
    return (0);
  if (f.empty() != f2.empty())
    return (0);
  typename T1::iterator it = f.begin();
  for (typename T2::iterator it2 = f2.begin(); it2 != f2.end(); ++it2) {
    if ((*it).first != (*it2).first)
      return (0);
    ++it; }
  typename T1::reverse_iterator rit = f.rbegin();
  for (typename T2::reverse_iterator rit2 = f2.rbegin(); rit2 != f2.rend(); ++rit2) {
    if ((*rit).first != (*rit2).first)
      return (0);
    ++rit; }
  return (1);
}template < class T1, class T2 >
void check_equalrange(T1 &f, T2 &f2, char c, bool debug = false)
{
  int ret = 1;
  if (f.equal_range(c).first->first != f2.equal_range(c).first->first)
    ret = 0;
  if (f.equal_range(c).first->second != f2.equal_range(c).first->second)
    ret = 0;
  if (f.equal_range(c).second->first != f2.equal_range(c).second->first)
    ret = 0;
  if (f.equal_range(c).second->second != f2.equal_range(c).second->second)
    ret = 0;
  is_same(ret);  if (debug) {
    // lower_bound
  	std::cout << f.equal_range(c).first->first << '\t' << f.equal_range(c).first->second << '\n';
  	std::cout << f2.equal_range(c).first->first << '\t'  << f2.equal_range(c).first->second << '\n';
    // upper_bound
  	std::cout << f.equal_range(c).second->first << '\t' << f.equal_range(c).second->second << '\n';
  	std::cout << f2.equal_range(c).second->first << '\t'  << f2.equal_range(c).second->second << '\n';
  }
}int mainMap(void)
{
  std::cout <<"\n\n"<< "MAP" << '\n'; 	ft::map<char, int, std::less<char> > f;
	ft::map<char, int, std::less<char> >::key_compare mycomp = f.key_comp();
	std::map<char, int, std::less<char> > f2;
	std::map<char, int, std::less<char> >::key_compare mycomp2 = f2.key_comp();  std::cout << "Test for max size:" << '\n';
	std::cout << "mine: " << f.max_size() << '\n'
            << "his:  " << f2.max_size() << '\n';  std::cout << '\n' << "Operator []:" << '\n';
  f['a'] = 1;
	f['b'] = 2;
	f['c'] = 3;
	f['e'] = 4;
	f['f'] = 4;
	f['f'] = 5;  f2['a'] = 1;
	f2['b'] = 2;
	f2['c'] = 3;
	f2['e'] = 4;
	f2['f'] = 4;
	f2['f'] = 5;
  is_same(f['a'], f2['a']);
  is_same(f['f'], f2['f']);
  is_same(f['!'], f2['!']);
  is_same(checker(f, f2));  std::cout << '\n' << "Insert:" << '\n';
  f.insert (f.begin(), std::pair<char,int>('g', 6));
	f.insert (f.begin(), std::pair<char,int>('g', -6));
  f2.insert (f2.begin(), std::pair<char,int>('g', 6));
	f2.insert (f2.begin(), std::pair<char,int>('g', -6));
  is_same(checker(f, f2));  std::cout << '\n' << "Erase:" << '\n';
  f.erase(f.find('b'));
  f2.erase(f2.find('b'));
  is_same(checker(f, f2));  // erasing unfound value in std::map cause segfault
  // f.erase(f.find('r'));
  // f2.erase(f2.find('r'));  // erasing in empty std::map cause infinite loop
 	// ft::map<char, int> e;
	// std::map<char, int> e2;
  // e.erase(e.begin());
  // e2.erase(e2.begin());  std::cout << '\n' << "Count:" << '\n';
  is_same(f.count('a'), f2.count('a'));
  is_same(f.count('b'), f2.count('b'));	std::cout << '\n' << "Test for value_comp:" << '\n';
	std::pair<char,int> highest = *f.rbegin();
  ft::map<char,int>::iterator it = f.begin();
	std::pair<char,int> highest2 = *f2.rbegin();
	std::map<char,int>::iterator it2 = f2.begin();  std::cout << " Mine->\t";
  do
    std::cout << it->first << " : " << it->second << '\t';
	while ( f.value_comp()(*it++, highest) );
	std::cout << '\n' << " Real->\t";
	do
    std::cout << it2->first << " : " << it2->second << '\t';
	while ( f2.value_comp()(*it2++, highest2) );
  std::cout << '\n';	std::cout << '\n' << "Test for key_comp:" << '\n';  char hiest = f.rbegin()->first;     // key value of last element
  it = f.begin();
  char hiest2 = f2.rbegin()->first;     // key value of last element  std::cout << " Mine->\t";
  std::map<char,int>::iterator itt2 = f2.begin();
  do {
    std::cout << it->first << " : " << it->second << '\t';
  } while ( mycomp((*it++).first, hiest) );
	std::cout << '\n' << " Real->\t";
  do {
    std::cout << itt2->first << " : " << itt2->second << '\t';
  } while ( mycomp2((*itt2++).first, hiest2) );
  std::cout << '\n';	std::cout << '\n' << "Test for equal range:" << '\n';
  check_equalrange(f, f2, 'a');
  check_equalrange(f, f2, 'c');
  check_equalrange(f, f2, ')');  std::cout << '\n' << "Constructors:" << '\n';
  ft::map<char, int, std::less<char> > f3(f.begin(), f.end());
  f3['k'] = 99;
  std::map<char, int, std::less<char> > f32(f2.begin(), f2.end());
  f32['k'] = 99;
  is_same(checker(f3, f32));  ft::map<char, int, std::less<char> > f4(f3);
  f4['y'] = 101;
  std::map<char, int, std::less<char> > f42(f32);
  f42['y'] = 101;
  is_same(checker(f4, f42));  ft::map<char, int, std::less<char> > f5;
  f5 = f4;
  f5['o'] = 55;
  std::map<char, int, std::less<char> > f52;
  f52 = f42;
  f52['o'] = 55;
  is_same(checker(f5, f52));  ft::map<char, int, std::less<char> > fe;
  std::map<char, int, std::less<char> > fe2;
  fe = f5;
  fe2 = f52;
  is_same(checker(fe, fe2));  std::cout << '\n' << "Swap:" << '\n';
  f3['k'] = 2;
  f32['k'] = 2;
  swap(f, f3);
  swap(f2, f32);
  is_same(checker(f, f2));
  is_same(checker(f3, f32));
  f.swap(f3);
  f2.swap(f32);
  is_same(checker(f, f2));
  is_same(checker(f3, f32));  std::cout << '\n' << "Relational operators:" << '\n';
  is_same((f == f3), (f2 == f32));
  is_same((f != f3), (f2 != f32));
  is_same((f <= f3), (f2 <= f32));
  is_same((f >= f3), (f2 >= f32));
  is_same((f <  f3), (f2 <  f32));
  is_same((f >  f3), (f2 >  f32));  std::cout << '\n' << "Clear:" << '\n';
  f.clear();
  f2.clear();
  is_same(checker(f, f2));
  ft::map<char, int, std::less<char> > emp;
  std::map<char, int, std::less<char> > emp2;
  emp.clear();
  emp2.clear();
  is_same(checker(emp, emp2));	return 0;
}
