#include "foo/foo.h"

int main() {

  std::cout << "Hello, World! This is my fisrt project with Cmake" << std::endl;

  Foo<double> f{};
  f.add(0.42F);
  f.add(42.0F);
  f.add(42.0F);
  f.print();
  return 0;
}
