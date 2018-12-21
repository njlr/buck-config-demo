#include <string>
#include <foo.hpp>

#define XSTR(x) #x
#define STR(x) XSTR(x)

std::string foo() {
  return std::string("foo says: ") + STR(FOO);
}
