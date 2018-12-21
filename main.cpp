#include <iostream>
#include <foo.hpp>

#define XSTR(x) #x
#define STR(x) XSTR(x)

int main() {
  std::cout << foo() << std::endl;
  std::cout << "app says: " << STR(FOO) << std::endl;

  return 0;
}
