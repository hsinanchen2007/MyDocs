/*

https://www.educative.io/module/lesson/cpp-basics/N0vPzjWo0zv

ℹ️ By default, pointers are passed by value. When we call the function, the value of the 
address is copied to the pointer variable. So if we change the value of the pointer inside 
the function, we cannot see that change outside the function body.

The "number" parameter variable at function "passPointer()" copies the address of the
variable "num" from main() function, and proceed the operations inside the function
"passPointer()", but for this case, "number" variable still points to same address of 
"num" at main(), so when it changed the value of the number, it is actually change to 
value of the "num" at main(), so once it finished and returned back to main(), the value
of "num" is also changed to new value.

*/

#include <iostream>

using namespace std;
// function definition
void passPointer(int *number) {
  // Multiply the number by 10
  *number = *number * 10;
  cout << "Value of number inside the function = " << *number << endl;
}

int main() {
  // Initialize variable
  int num = 10;
  cout << "Value of number before function call = " << num << endl;
  // Call function
  passPointer(&num);
  cout << "Value of number after function call = " << num << endl;

  return 0;
}

/*
Value of number before function call = 10
Value of number inside the function = 100
Value of number after function call = 100
*/