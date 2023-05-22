#include <iostream>

typedef std::string phoneNo_t;
// instead of using tydef use using keyword

using hewo = int;
int main()
{
  phoneNo_t k = "21";
  hewo p = 212;
  std::cout << "lmao " << k << " " << p;
  return 0;
}