#include <iostream>
#include <memory>

class Foo {
 public:
  
  ~Foo() {
    std::cout << "Foo Destructor called" << std::endl;
  }
  
  void Release(std::auto_ptr<Foo> ptr) {
    std::cout << "Foo Relase called" << std::endl;
  }

  void Print() {
    std::cout << "Foo::Print" << std::endl;
  }
};

class Bar {
 public:
  
  ~Bar() {
    std::cout << "Bar Destructor called" << std::endl;
  }
  
  void Print() {
    std::cout << "Bar::Print" << std::endl;
  }
};

int main(int argc, char** argv) {
  // Create new auto_ptr p1
  std::auto_ptr<Foo> p1(new Foo);
  p1->Print();
  std::cout << "p1 pointer address : " << p1.get() << std::endl;
  
  // Create new auto_ptr p2
  std::auto_ptr<Foo> p2 = p1;
  // Just to check, it prints Foo::print
  p2->Print();
  
  // Check p1 transferred ownership.
  std::cout << "p1 pointer address : " << p1.get() << std::endl;
  std::cout << "p2 pointer address : " << p2.get() << std::endl;
  
  // Take back the ownership from p2.  
  Foo* temp1 = p2.release();
  std::cout << "temp1 pointer address after taking ownership : " << temp1 << std::endl;
  std::cout << "p2 pointer address after release operation : " << p2.get() << std::endl;
  
  // After resetting Foo Dtor should be called and new
  // instance should be assigned.
  p2.reset(new Foo);
  
  std::cout << "p2 pointer address : " << p2.get() << std::endl;
  
  {
    // Creating aut_ptr inside brace scope, once we
    // go out of scope, Bar dtor should be called.
    std::auto_ptr<Bar> p3(new Bar);
  }
  
  Foo* temp2 = p2.get();

  // this will not release ownership, both temp_ptr and p2 hold the reference to
  // memory.
  std::cout << "temp2 pointer address : " << temp2 << std::endl;
  std::cout << "p2 pointer address : " << p2.get() << std::endl;

  p2->Release(p2);
  
  // Since ownership is already passed to Release methods
  // auto_ptr, therefore this should result in NULL.
  std::cout << "p2 pointer address : " << p2.get() << std::endl;

  // Check if raw pointers released memory or not, even though auto_ptr released
  // memory, raw pointers still hold the reference to it. 
  std::cout << "temp1 raw pointer address : " << temp1 << std::endl;
  std::cout << "temp2 raw pointer address : " << temp2 << std::endl;

  // For eg: 
  //  class X
  // {
  // };

  // std::vector<std::auto_ptr<X> > vecX;
  // vecX.push_back(new X);
  // std::auto_ptr<X> pX = vecX[0];  // after this operation vecX[0] is 
  // assigned NULL.

  return 0;  
}
