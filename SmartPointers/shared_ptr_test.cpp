#include <memory>
#include <iostream>

class Foo {
 public:
  ~Foo() {
      std::cout << "foo dtor called \n";
  }
  void Print() {
      std::cout << "Foo :: Print called \n";
  }
};


int main(int argc, char** argv) {
  std::shared_ptr<Foo> fooPtr(new Foo);
  std::shared_ptr<Foo> nullPtr;

  std::cout << "fooPtr address : " << fooPtr << std::endl;
  std::cout << "fooPtr.get address : " << fooPtr.get() << std::endl;
  std::cout << "fooPtr usecount : " << fooPtr.use_count() << std::endl;
  {
      // Lets check how use count gets reduced as fooptr1 and fooptr2 goes
      // out of scope.
      std::shared_ptr<Foo> fooPtr1 = fooPtr;
      std::cout << "fooPtr usecount : " << fooPtr.use_count() << std::endl;
      {
          std::shared_ptr<Foo> fooPtr2 = fooPtr;
          std::cout << "fooPtr usecount : " << fooPtr.use_count() << std::endl;
      }
      std::cout << "fooPtr usecount : " << fooPtr.use_count() << std::endl;
  }
  std::cout << "fooPtr usecount : " << fooPtr.use_count() << std::endl;
  // checking boolean operation.
  if (!nullPtr) {
      std::cout << "nullPtr points to NULL \n";
  }

  // Call Foo object method
  fooPtr->Print();
  
  // Difference between normal shared_ptr usage and make_shared is:
  // The shared pointer manages both the object itself, and a small object 
  // containing the reference count and other housekeeping data. make_shared 
  // can allocate a single block of memory to hold both of these; constructing
  // a shared pointer from a pointer to an already-allocated object will need 
  // to allocate a second block to store the reference count (Source : Stack
  // Overflow).
  std::shared_ptr<Foo> fooPtr3 = std::make_shared<Foo>();

  std::cout << "fooPtr3 address" << fooPtr3.get() << std::endl;

  // Since fooPtr3 is not shared with anyone, it is unique we can check the
  // same with unique mwthod present on the shared_ptr.
  std::cout << "fooPtr3 is unique ? " << (fooPtr3.unique() ? "true" : "false")
            << std::endl;

  std::shared_ptr<Foo> fooPtr4 = fooPtr;

  std::cout << "fooPtr4 usecount before resetting original: " << fooPtr4.use_count() 
            << std::endl;
  
  // eventhough we are resetting, still we hold the refernce in fooPtr4 hence
  // Foo dtor will not be called after this.
  fooPtr.reset();

  std::cout << "fooPtr address : " << fooPtr.get() << std::endl;

  std::cout << "fooPtr usecount after resetting original: " << fooPtr4.use_count() 
            << std::endl;
  return 0;
}
