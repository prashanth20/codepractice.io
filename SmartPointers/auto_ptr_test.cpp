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
  Foo* temp = p2.release();
  std::cout << "temp pointer address after taking ownership : " << temp << std::endl;
  
  // After resetting Foo Dtor should be called and new
  // instance should be assigned.
  p2.reset(new Foo);
  
  std::cout << "p2 pointer address : " << p2.get() << std::endl;
  
  {
    // Creating aut_ptr inside brace scope, once we
    // go out of scope, Bar dtor should be called.
    std::auto_ptr<Bar> p3(new Bar);
  }
  
  p2->Release(p2);
  
  // Since ownership is already passed to Release methods
  // suto_ptr, therefore this should result in NULL.
  std::cout << "p2 pointer address : " << p2.get() << std::endl;
      
  return 0;  
}
