#ifndef IITERATOR_H_
#define IITERATOR_H_
template <class T>
class Iiterator {
public:
  virtual ~Iiterator(){};
  virtual T *getPointer() const = 0;
  virtual void setPointer(T *) = 0;
  // comparisons operators
  virtual bool operator==(const Iiterator &rhs) const = 0;
  virtual bool operator!=(const Iiterator &rhs) const = 0;
  virtual bool operator<(const Iiterator &rhs) const = 0;
  virtual bool operator>(const Iiterator &rhs) const = 0;
  virtual bool operator<=(const Iiterator &rhs) const = 0;
  virtual bool operator>=(const Iiterator &rhs) const = 0;
  // dereference operators
  virtual T operator*(void) const = 0;
  // virtual T operator->(void) const = 0; A faire
  virtual T operator[](int) const = 0;
  // assignation _pointer operator
  virtual void operator=(const T &rhs) = 0;
  // incrementation and decrementation operators
  // prefix increment
  virtual Iiterator &operator++() = 0;
  // postfix increment
  virtual Iiterator &operator++(int) = 0;
  // prefix decrement
  virtual Iiterator &operator--() = 0;
  // postfix decrement
  virtual Iiterator &operator--(int) = 0;
  // arithmetic operators
  virtual Iiterator &operator+(int rhs) = 0;
  virtual Iiterator &operator-(int rhs) = 0;
  virtual Iiterator &operator+(const Iiterator &rhs) = 0;
  virtual Iiterator &operator-(const Iiterator &rhs) = 0;
  virtual Iiterator &operator+=(int rhs) = 0;
  virtual Iiterator &operator-=(int rhs) = 0;
};

#endif // IITERATOR_H_
