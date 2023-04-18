#include "zmytest/test.hpp"
#include "../../vector/vector.hpp" //delete
#include "zlasdtest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2023" << std::endl;
  //test
  lasd::Vector<int> vec(4);
  bool res = vec.Empty();
  //lasdtest(); // Call in the menu of your library test!
  return 0;
}
