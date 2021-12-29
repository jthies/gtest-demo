#include "functions.hpp"
#include "vector.hpp"
#include <iostream>

int main()
{
  Vector<double> v={1,2,3,4,5};

  std::cout << "1+1="<<add_numbers(1,1)<<std::endl;
  std::cout << "... and I can even count to five! "<<v<<std::endl;
  return 0;
}
