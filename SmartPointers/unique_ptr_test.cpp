#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

class Foo {
 public:
  ~Foo() {
      std::cout << "Foo dtor called \n";
  }

  std::unique_ptr<int> Source(int i) {
      return std::unique_ptr<int>(new int(i));
  }

  void Sink(std::unique_ptr<int> i) {
      std::cout << "Sink called, i will be deleted here \n";
  }
};

int main(int argc, char** argv) {

  // create unique_ptr p1 and check the address.
  std::unique_ptr<Foo> p1(new Foo);
  std::cout << "p1 address after creation : " << p1.get() << std::endl;

  // since unique_ptr is non-copyable , hence we can't directy assign it to 
  // another unique pointer p2, we have to call explicit move. After moving
  // p1 would be set to NULL. And p2 takes the ownership.
  std::unique_ptr<Foo> p2(std::move(p1));
  std::cout << "p1 address after std::move : " << p1.get() << std::endl;
  std::cout << "p2 address after taking ownership: " << p2.get() << std::endl;

  std::unique_ptr<int> int_ptr = p2->Source(5);
  // We cannot directly call Sink(int_ptr), as it would be lvalue referencing
  // which is not allowed in unique_ptr.
  p2->Sink(std::move(int_ptr));
  // But we can call like below, which would be rvalue referencing.
  p2->Sink(p2->Source(5));

  // It supports the reset, release similar to auto_ptr
  p2.reset(new Foo);
  std::cout << "p2 address after reset & new object assigned : " << p2.get() 
            << std::endl;

  Foo* temp_ptr = p2.release();
  std::cout << "p2 address after release called : " << p2.get() << std::endl;
  std::cout << "temp_ptr(raw pointer) address after p2 called release : " 
            << temp_ptr << std::endl;

  // We can use swap method to swap the resource and custom deleter if defined
  // between two objects.
  p2.reset(new Foo);
  std::cout << "p2 address before swap: " << p2.get() << std::endl;
  p1.swap(p2);
  std::cout << "p1 address after swap from p2 : " << p1.get() << std::endl;
  std::cout << "p2 address after swap: " << p2.get() << std::endl;

  // We can create array of unique_ptr which will call delete[] when go out of
  // scope, unlike auto_ptr which calls delete. Hence we were not able to use
  // auto_ptr with array.
  std::unique_ptr<int[]> int_array_ptr(new int[10]);
  int_array_ptr[0] = 10;
  // Since for array handling unique_ptr overrides operator[], we can't use
  // * and -> to dereference the array

  // It is safe to use unique_ptr with standard container, which was unlikely
  // in auto_ptr, because if some auto_ptr variable in container/outside copies
  // the reference of value from container, then ownership passed to new variable 
  // and container value having reference to that would be set to NULL.
  // For eg: 
  //  class X
  // {
  // };

  // std::vector<std::auto_ptr<X> > vecX;
  // vecX.push_back(new X);
  // std::auto_ptr<X> pX = vecX[0];  // after this operation vecX[0] is 
  // assigned NULL.

  // But with unique_ptr any attempt to copy with lvalue reference would
  // immmediately results in the compilation error. Below code shows creation
  // of vector containing int unique_ptr.
  std::vector<std::unique_ptr<int>> v;
  v.push_back(std::unique_ptr<int>(new int(2)));
  v.push_back(std::unique_ptr<int>(new int(0)));
  v.push_back(std::unique_ptr<int>(new int(1)));
  // Here we are calling sort, if any copying using lvalue referencing used 
  // in std::sort we will get compilaion error.
  std::sort(v.begin(), v.end());

  for (int j = 0; j < v.size(); j++){
      std::cout << "vector values : " << *v[j] << std::endl;
  }

  // Here once we go out of scope, just like auto_ptr unique_ptr p1 pointer 
  // which is holding Foo pointer automatically
  // calls the Foo dtor and we don't have to worry of about memory management.

  return 0;
}

