/**********************************************
*   fibonacci.cpp
*
*   Find the numbers of Fibonacci's sequence.
*
*   @author Ryan Morehouse
*   @license MIT
*
***********************************************/

#include <limits>
#include <iostream>
#include <sstream>

void error_msg() {
  std::cout << "Usage: fibonacci.o [n]\n[n] is a positive integer less than ";
  std::cout << std::numeric_limits<int>::max() << std::endl << std::endl;
}

int main(int argc, char *argv[]) {
  // user input
  int n;

  // check for arg
  if (argc < 2) {
    error_msg();
    return 1;
  }

  // verify arg is within limits
  std::istringstream ss(argv[1]);
  if(!(ss >> n)) {
    error_msg();
    return 1;
  } else if (n < 1 || n > std::numeric_limits<int>::max()) {
    error_msg();
    return 1;
  }

  // just print simple cases
  if(n == 1)
    std::cout << "[ 1 ]" << std::endl;
  else if (n == 2)
    std::cout << "[1, 1]" << std::endl;
  else {
    long int fib[n];
    fib[0] = 1;
    fib[1] = 1;

    for(int i = 2; i < n; i++)
      fib[i] = fib[i-1] + fib[i-2];

    std::cout << "[ ";
    for(int i = 0; i < n-1; i++)
      std::cout << fib[i] << ", ";
    std::cout << fib[n-1] << " ]" << std::endl;
  }

  return 0;
}

