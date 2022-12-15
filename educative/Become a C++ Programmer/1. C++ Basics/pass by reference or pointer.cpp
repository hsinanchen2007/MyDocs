/*

https://www.educative.io/module/lesson/cpp-basics/gxwNop7BzkY

References vs. pointers
There is a lot of overlap between pointers and references but the two have some stark 
differences as well.

A reference is never nullptr. Therefore, it must always be initialized by having an 
existing variable assigned to it. The following lines would not work:

    1. int& intRef; // not assign a vairable as its reference
    2. int& intRef = nullptr; // reference is not a pointer

References behave like constant pointers. A reference always refers to its initial 
variable. The value of the variable can change but the reference cannot be assigned to 
another variable.

Like pointers, a reference can only be initialized by a variable of the same type.

References as parameters
References allow functions to modify the value of a variable. When a normal variable is 
passed to a function, a copy of its value is made and the variable itself remains 
untouched. However, if a reference is passed, the actual value of the variable is used 
and can therefore be modified.

*/

#include <iostream>

void xchg(int& x, int& y){ // Reference parameters
  int t = x;
  x = y;
  y = t;
}

void xchgPtr(int *x, int *y){ // Pointer parameters
  int t = *x;
  *x = *y;
  *y = t;
}

int main() {
  int a = 10;
  int b = 20;
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;

  xchg(a, b);
  std::cout << std::endl;

  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;

  xchgPtr(&a, &b);
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;

  return 0;
}


