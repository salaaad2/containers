#include <iomanip>
#include <list>
#include "../inc/list.hpp"
struct is_odd
{
  bool operator()(const int &value)
  {
    return (value % 2) == 1;
  }
};
struct is_near
{
  bool operator()(int first, int second)
  {
    return (abs(first - second) <= 1);
  }
};
bool sup(const int &value, const int &value2)
{
  return (value > value2);
}
template < class T >
void display_checker(ft::list< T > f, std::list< T > f2)
{
  std::cout << std::endl;
  std::cout << "My list contain ";
  for (ft::list< int >::iterator it3 = f.begin(); it3 != f.end(); ++it3)
    std::cout << ' ' << *it3;
  std::cout << std::endl;
  std::cout << "True list contain ";
  for (std::list< int >::iterator it3 = f2.begin(); it3 != f2.end(); ++it3)
    std::cout << ' ' << *it3;
  std::cout << std::endl;
}

template < class T >
int checker(ft::list< T > f, std::list< T > f2, bool debug = false)
{
  if (f.size() != f2.size())
    return (0);
  if (f.empty() != f2.empty())
    return (0);
  if (*++f.end() != *++f2.end() || &*--f.end() != &*----f.begin())
    return (0);
  if (*----f.begin() != *----f2.begin() || &*f.begin() != &*++f.end())
    return (0);
  ft::list< int >::iterator it = f.begin();
  if (debug)
  {
    display_checker(f, f2);
  }
  for (std::list< int >::iterator it2 = f2.begin(); it2 != f2.end(); ++it2)
  {
    if (*it != *it2)
      return (0);
    ++it;
  }
  ft::list< int >::reverse_iterator rit = f.rbegin();
  for (std::list< int >::reverse_iterator rit2 = f2.rbegin(); rit2 != f2.rend(); ++rit2)
  {
    if (*rit != *rit2)
      return (0);
    ++rit;
  }
  return (1);
}

template < class T >
void pcheck(ft::list< T > f, std::list< T > f2, int debug = 0)
{
  if (checker(f, f2, debug))
    std::cout << std::setw(0) << "\x1B[32m[OK]\033[0m ";
  else
  {
    display_checker(f, f2);
    std::cout << std::setw(0) << "\x1B[31m[KO]\033[0m ";
  }
}
void operator_checker(bool b1, bool b2, std::string txt)
{
  if (b1 == b2)
    std::cout << std::setw(2) << txt << " \x1B[32m[OK]\033[0m" << std::endl;
  else
    std::cout << std::setw(2) << txt << " \x1B[31m[KO]\033[0m" << std::endl;
}
int mainList()
{
  std::cout << "LIST" << '\n';
  bool debug = false;

  std::cout << "Constructor :" << std::endl;
  std::cout << "Init default " << std::endl;
  ft::list< int >  first;
  std::list< int > first_test;
  std::cout << "Init fill " << std::endl;
  ft::list< int >  second(3, 100);
  std::list< int > second_test(3, 100);
  std::cout << "Init with iterator " << std::endl;
  ;
  ft::list< int >  third(second.begin(), second.end());
  std::list< int > third_test(second_test.begin(), second_test.end());
  std::cout << "copy " << std::endl;
  ft::list< int >  fourth = second;
  std::list< int > fourth_test = second_test;
  std::cout << "operator = " << std::endl;
  ft::list< int >  five(3, 100);
  std::list< int > five_test(3, 100);
  five = fourth;
  five_test = fourth_test;
  third.front() = 3333;
  fourth.front() = 4444;
  five.front() = 5555;
  third_test.front() = 3333;
  fourth_test.front() = 4444;
  five_test.front() = 5555;
  pcheck(first, first_test, debug);
  pcheck(second, second_test, debug);
  pcheck(third, third_test, debug);
  pcheck(fourth, fourth_test, debug);
  pcheck(five, five_test, debug);
  std::cout << std::endl;

  std::cout << "Size " << std::endl;
  std::cout << std::setw(25) << "first.size() : " << first.size() << std::endl;
  std::cout << std::setw(25) << "first_test.size() : " << first_test.size()
            << std::endl;
  std::cout << std::endl;

  std::cout << std::setw(25) << "second.size() : " << second.size() << std::endl;
  std::cout << std::setw(25) << "second_test.size() : " << second_test.size()
            << std::endl;
  std::cout << std::endl;

  std::cout << std::setw(25) << "third.size() : " << third.size() << std::endl;
  std::cout << std::setw(25) << "third_test.size() : " << third_test.size()
            << std::endl;
  std::cout << std::endl;

  std::cout << std::setw(25) << "fourth.size() : " << fourth.size() << std::endl;
  std::cout << std::setw(25) << "fourth_test.size() : " << fourth_test.size()
            << std::endl;
  std::cout << std::endl;

  std::cout << std::setw(25) << "five.size() : " << fourth.size() << std::endl;
  std::cout << std::setw(25) << "five_test.size() : " << fourth_test.size()
            << std::endl;
  std::cout << std::endl;

  std::cout << "Max size " << std::endl;
  ;
  std::cout << std::setw(25) << "first.max_size() : " << first.max_size() << std::endl;
  std::cout << std::setw(25)
            << "first_test.max_size() : " << first_test.max_size() << std::endl;
  std::cout << std::setw(25) << "second.max_size() : " << second.max_size()
            << std::endl;
  std::cout << std::setw(25)
            << "second_test.max_size() : " << second_test.max_size() << std::endl;
  std::cout << std::endl;

  std::cout << "Empty " << std::endl;
  ;
  std::cout << std::setw(25) << "first.empty() : " << first.empty() << std::endl;
  std::cout << std::setw(25) << "first_test.empty() : " << first_test.empty()
            << std::endl;
  std::cout << std::setw(25) << "second.empty() : " << second.empty() << std::endl;
  std::cout << std::setw(25) << "second_test.empty() : " << second_test.empty()
            << std::endl;
  std::cout << std::endl;

  std::cout << "push/pop front/back ";
  first.push_front(1);
  first.push_front(2);
  first.push_front(3);
  first.push_back(4);
  first.pop_front();
  first.pop_back();
  first.pop_back();

  first_test.push_front(1);
  first_test.push_front(2);
  first_test.push_front(3);
  first_test.push_back(4);
  first_test.pop_front();
  first_test.pop_back();
  first_test.pop_back();
  pcheck(first, first_test, debug);
  std::cout << std::endl;
  std::cout << std::endl;

  first.push_back(10);
  first.push_back(20);
  first_test.push_back(10);
  first_test.push_back(20);
  first.clear();
  first_test.clear();
  ft::list< int > one(1, 1);

  std::cout << "first.front() : " << first.front() << std::endl;
  std::cout << "first.back() : " << first.back() << std::endl;
  std::cout << std::endl;

  std::cout << "second.front() : " << second.front() << std::endl;
  std::cout << "second.back() : " << second.back() << std::endl;
  std::cout << std::endl;

  std::cout << "one.front() : " << one.front() << std::endl;
  std::cout << "one.back() : " << one.back() << std::endl;
  std::cout << std::endl;

  ft::list< int > const list_const(2, 5);
  std::cout << "list_const.front() : " << list_const.front() << std::endl;
  std::cout << "list_const.back() : " << list_const.back() << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Insert :";
  second.clear();
  second_test.clear();
  ft::list< int >::iterator  it = second.begin();
  ft::list< int >::iterator  ret;
  std::list< int >::iterator it_test = second_test.begin();
  std::list< int >::iterator ret_test;
  ft::list< int >::iterator  it_end = second.end();
  std::list< int >::iterator it_test_end = second_test.end();
  ret = second.insert(it, 6);
  ret_test = second_test.insert(it_test, 6);
  ret = second.insert(it, 7);
  ret_test = second_test.insert(it_test, 7);
  ret = second.insert(it_end, 8);
  ret_test = second_test.insert(it_test_end, 8);
  pcheck(second, second_test, debug);

  ft::list< int > insert_list;
  insert_list.push_back(1);
  insert_list.push_back(2);
  insert_list.push_back(3);
  ft::list< int > insert_list2(5, 5);

  std::list< int > insert_list_test;
  insert_list_test.push_back(1);
  insert_list_test.push_back(2);
  insert_list_test.push_back(3);
  std::list< int > insert_list_test2(5, 5);

  ft::list< int >::iterator insert_list_it = insert_list.begin();
  ft::list< int >::iterator insert_list_it_e = insert_list.end();
  insert_list.insert(++insert_list_it, insert_list_it, insert_list_it_e);

  std::list< int >::iterator it_test_insert = insert_list_test.begin();
  std::list< int >::iterator it_test_insert_e = insert_list_test.end();
  insert_list_test.insert(++it_test_insert, it_test_insert, it_test_insert_e);

  pcheck(insert_list, insert_list_test, debug);
  std::cout << std::endl;
  std::cout << std::endl;

  // std::cout << "Assign :";
  // ft::list< int >  assign_list(5, -5);
  // std::list< int > assign_list_test(5, -5);

  // pcheck(assign_list, assign_list_test, debug);

  // assign_list.assign(assign_list.begin(), assign_list.end());
  // assign_list_test.assign(assign_list_test.begin(), assign_list_test.end());

  // pcheck(assign_list, assign_list_test, debug);

  // assign_list.assign(3, 2);
  // assign_list_test.assign(3, 2);

  // pcheck(assign_list, assign_list_test, debug);
  // std::cout << std::endl;
  // std::cout << std::endl;

  std::cout << "Erase :";
  ft::list< int > er;
  er.push_back(1);
  er.push_back(2);
  er.push_back(3);
  er.push_back(4);
  er.push_back(5);

  std::list< int > er_test;
  er_test.push_back(1);
  er_test.push_back(2);
  er_test.push_back(3);
  er_test.push_back(4);
  er_test.push_back(5);

  ft::list< int >::iterator  it_er = er.begin();
  std::list< int >::iterator it_er_test = er_test.begin();

  er.erase(it_er);
  er_test.erase(it_er_test);

  pcheck(er, er_test, debug);
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Erase P2 :";
  ft::list< int >::iterator it_er2 = er.begin();
  ft::list< int >::iterator it_er3 = er.begin();
  ++it_er3;
  ++it_er3;

  std::list< int >::iterator it_er_test2 = er_test.begin();
  std::list< int >::iterator it_er_test3 = er_test.begin();
  ++it_er_test3;
  ++it_er_test3;

  er.erase(it_er2, it_er3);
  er_test.erase(it_er_test2, it_er_test3);
  pcheck(er, er_test, debug);
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Swap :";
  ft::list< int > swap1;
  ft::list< int > swap2;
  swap1.push_back(1);
  swap1.push_back(2);
  swap1.push_back(3);
  swap1.push_back(4);
  swap1.push_back(5);
  swap2.push_back(10);
  swap2.push_back(20);
  swap2.push_back(30);
  swap2.push_back(40);

  std::list< int > swap1_test;
  std::list< int > swap2_test;
  swap1_test.push_back(1);
  swap1_test.push_back(2);
  swap1_test.push_back(3);
  swap1_test.push_back(4);
  swap1_test.push_back(5);
  swap2_test.push_back(10);
  swap2_test.push_back(20);
  swap2_test.push_back(30);
  swap2_test.push_back(40);

  // swap1.swap(swap2);
  // swap1_test.swap(swap2_test);

  // pcheck(swap1, swap1_test, debug);
  // pcheck(swap2, swap2_test, debug);
  // std::cout << std::endl;
  // std::cout << std::endl;

  // std::cout << "Resize :";
  // ft::list< int > second_resize;
  // for (int i = 1; i < 10; ++i)
  //   second_resize.push_back(i);
  // std::list< int > second_resize_test;
  // for (int i = 1; i < 10; ++i)
  //   second_resize_test.push_back(i);
  // second_resize.resize(4);
  // second_resize_test.resize(4);
  // pcheck(second_resize, second_resize_test, debug);
  // second_resize.resize(7, 1);
  // second_resize_test.resize(7, 1);
  // pcheck(second_resize, second_resize_test, debug);

  // std::cout << std::endl;
  // std::cout << std::endl;

  // std::cout << "Splice :";
  // ft::list< int > first_splice;
  // for (int i = 0; i <= 4; ++i)
  //   first_splice.push_back(i);
  // ft::list< int > first2_splice;
  // for (int i = 0; i <= 4; ++i)
  //   first2_splice.push_back(-i);
  // ft::list< int > first3_splice;
  // for (int i = 0; i <= 4; ++i)
  //   first3_splice.push_back(-i * 10);

  // std::list< int > first_splice_test;
  // for (int i = 0; i <= 4; ++i)
  //   first_splice_test.push_back(i);
  // std::list< int > first2_splice_test;
  // for (int i = 0; i <= 4; ++i)
  //   first2_splice_test.push_back(-i);
  // std::list< int > first3_splice_test;
  // for (int i = 0; i <= 4; ++i)
  //   first3_splice_test.push_back(-i * 10);

  // first_splice.splice(first_splice.begin(), first2_splice);
  // first_splice_test.splice(first_splice_test.begin(), first2_splice_test);
  // pcheck(first_splice, first_splice_test, debug);
  // pcheck(first2_splice, first2_splice_test, debug);
  // std::cout << std::endl;
  // std::cout << std::endl;

  // std::cout << "Splice P2 :";
  // first_splice.splice(first_splice.begin(), first3_splice, ++first3_splice.begin());
  // first_splice_test.splice(first_splice_test.begin(), first3_splice_test,
  //                          ++first3_splice_test.begin());

  // pcheck(first_splice, first_splice_test, debug);
  // pcheck(first3_splice, first3_splice_test, debug);
  // std::cout << std::endl;
  // std::cout << std::endl;

  // std::cout << "Splice P3 :";
  // first_splice.splice(first_splice.begin(), first3_splice,
  //                     ++first3_splice.begin(), --first3_splice.end());
  // first_splice_test.splice(first_splice_test.begin(), first3_splice_test,
  //                          ++first3_splice_test.begin(), --first3_splice_test.end());

  // pcheck(first_splice, first_splice_test, debug);
  // pcheck(first3_splice, first3_splice_test, debug);

  // std::cout << std::endl;
  // std::cout << std::endl;

  // std::cout << "Remove :";
  // ft::list< int > first_remove;
  // for (int i = 0; i <= 4; ++i)
  //   first_remove.push_back(i);
  // std::list< int > first_remove_test;
  // for (int i = 0; i <= 4; ++i)
  //   first_remove_test.push_back(i);

  // first_remove.remove(2);
  // first_remove_test.remove(2);

  // pcheck(first_remove, first_remove_test, debug);

  // std::cout << std::endl;
  // std::cout << std::endl;

  // std::cout << "Remove if :";
  // first_remove.remove_if(is_odd());
  // first_remove_test.remove_if(is_odd());
  // pcheck(first_remove, first_remove_test, debug);

  // std::cout << std::endl;
  // std::cout << std::endl;

  // std::cout << "Unique :";
  // ft::list< int > first_unique(5, 5);
  // first_unique.push_back(7);
  // first_unique.push_back(7);
  // first_unique.push_back(7);
  // first_unique.push_back(7);
  // first_unique.push_back(5);
  // std::list< int > first_unique_test(5, 5);
  // first_unique_test.push_back(7);
  // first_unique_test.push_back(7);
  // first_unique_test.push_back(7);
  // first_unique_test.push_back(7);
  // first_unique_test.push_back(5);

  // first_unique.unique();
  // first_unique_test.unique();
  // pcheck(first_unique, first_unique_test, debug);

  // std::cout << std::endl;
  // std::cout << std::endl;

  // std::cout << "Unique P2 :";
  // ft::list< int > first_unique2(6, 6);
  // first_unique2.push_back(7);
  // first_unique2.push_back(7);
  // first_unique2.push_back(7);
  // first_unique2.push_back(7);
  // first_unique2.push_back(5);
  // first_unique2.push_back(9);
  // std::list< int > first_unique2_test(6, 6);
  // first_unique2_test.push_back(7);
  // first_unique2_test.push_back(7);
  // first_unique2_test.push_back(7);
  // first_unique2_test.push_back(7);
  // first_unique2_test.push_back(5);
  // first_unique2_test.push_back(9);

  // first_unique2.unique(is_near());
  // first_unique2_test.unique(is_near());
  // pcheck(first_unique2, first_unique2_test, debug);

  // std::cout << std::endl;
  // std::cout << std::endl;

  // std::cout << "Sort :";
  // ft::list< int > first_sort(6, 6);
  // first_sort.push_back(100);
  // first_sort.push_back(1);
  // first_sort.push_back(9);
  // first_sort.push_back(99);
  // first_sort.push_back(4);
  // first_sort.push_back(8);
  // first_sort.push_back(1);
  // std::list< int > first_sort_test(6, 6);
  // first_sort_test.push_back(100);
  // first_sort_test.push_back(1);
  // first_sort_test.push_back(9);
  // first_sort_test.push_back(99);
  // first_sort_test.push_back(4);
  // first_sort_test.push_back(8);
  // first_sort_test.push_back(1);

  // first_sort.sort();
  // first_sort_test.sort();
  // pcheck(first_sort, first_sort_test, debug);
  // std::cout << std::endl;
  // std::cout << std::endl;

  // std::cout << "Sort P2 :";
  // ft::list< int > first_sort2(6, 6);
  // first_sort2.push_back(100);
  // first_sort2.push_back(1);
  // first_sort2.push_back(9);
  // first_sort2.push_back(99);
  // first_sort2.push_back(4);
  // first_sort2.push_back(8);
  // first_sort2.push_back(1);
  // std::list< int > first_sort2_test(6, 6);
  // first_sort2_test.push_back(100);
  // first_sort2_test.push_back(1);
  // first_sort2_test.push_back(9);
  // first_sort2_test.push_back(99);
  // first_sort2_test.push_back(4);
  // first_sort2_test.push_back(8);
  // first_sort2_test.push_back(1);

  // first_sort2.sort(sup);
  // first_sort2_test.sort(sup);

  // pcheck(first_sort2, first_sort2_test, debug);
  // std::cout << std::endl;
  // std::cout << std::endl;

  // std::cout << "Merge :";
  // ft::list< int > first_merge;
  // ft::list< int > first_merge2;
  // first_merge.push_back(7);
  // first_merge.push_back(-8);
  // first_merge.push_back(7);
  // first_merge.push_back(321);
  // first_merge.push_back(7);
  // first_merge.push_back(65);
  // first_merge2.push_back(555);
  // std::list< int > first_merge_test;
  // std::list< int > first_merge_test2;
  // first_merge_test.push_back(7);
  // first_merge_test.push_back(-8);
  // first_merge_test.push_back(7);
  // first_merge_test.push_back(321);
  // first_merge_test.push_back(7);
  // first_merge_test.push_back(65);
  // first_merge_test2.push_back(555);

  // first_merge.merge(first_merge2);
  // first_merge_test.merge(first_merge_test2);

  // pcheck(first_merge, first_merge_test, debug);
  // std::cout << std::endl;
  // std::cout << std::endl;

  // std::cout << "Merge P2 :";
  // ft::list< int > first_mergeBis;
  // ft::list< int > first_mergeBis2;
  // first_mergeBis.push_back(321);
  // first_mergeBis.push_back(65);
  // first_mergeBis.push_back(7);
  // first_mergeBis.push_back(7);
  // first_mergeBis.push_back(7);
  // first_mergeBis.push_back(-8);
  // first_mergeBis2.push_back(555);
  // std::list< int > first_mergeBis_test;
  // std::list< int > first_mergeBis_test2;
  // first_mergeBis_test.push_back(321);
  // first_mergeBis_test.push_back(65);
  // first_mergeBis_test.push_back(7);
  // first_mergeBis_test.push_back(7);
  // first_mergeBis_test.push_back(7);
  // first_mergeBis_test.push_back(-8);
  // first_mergeBis_test2.push_back(555);

  // first_mergeBis.merge(first_mergeBis2, sup);
  // first_mergeBis_test.merge(first_mergeBis_test2, sup);
  // pcheck(first_mergeBis, first_mergeBis_test, debug);
  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << "Reverse :";
  // ft::list< int > first_reverse;
  // for (int i = 0; i <= 4; ++i)
  //   first_reverse.push_back(i);
  // std::list< int > first_reverse_test;
  // for (int i = 0; i <= 4; ++i)
  //   first_reverse_test.push_back(i);
  // first_reverse.reverse();
  // first_reverse_test.reverse();
  // pcheck(first_reverse, first_reverse_test, debug);
  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << "relational operators :" << std::endl;
  // ft::list< int > a;
  // ft::list< int > b;
  // ft::list< int > c;
  // for (int i = 1; i <= 3; ++i)
  // {
  //   a.push_back(i * 10);
  //   b.push_back(i * 10);
  //   c.push_back(i * 10);
  // }
  // c.reverse();

  // std::list< int > a_test;
  // std::list< int > b_test;
  // std::list< int > c_test;
  // for (int i = 1; i <= 3; ++i)
  // {
  //   a_test.push_back(i * 10);
  //   b_test.push_back(i * 10);
  //   c_test.push_back(i * 10);
  // }
  // c_test.reverse();
  // operator_checker((a == b), (a_test == b_test), "==");
  // operator_checker((a != b), (a_test != b_test), "!=");
  // operator_checker((a < b), (a_test < b_test), "<");
  // operator_checker((a > b), (a_test > b_test), ">");
  // operator_checker((a >= b), (a_test >= b_test), ">=");
  // operator_checker((a <= b), (a_test <= b_test), "<=");

  // std::cout << "swap (list) :";
  // swap(a, c);
  // swap(a_test, c_test);
  // pcheck(a, a_test, debug);
  // pcheck(c, c_test, debug);
  // std::cout << std::endl;
  // std::cout << std::endl;

  return 0;
}

int main(void) {
  mainList();
  return 0;
}
