/*

https://www.educative.io/module/lesson/cpp-basics/N0vPzjWo0zv

ℹ️ By default, pointers are passed by value. When we call the function, the value of the 
address is copied to the pointer variable. So if we change the value of the pointer inside 
the function, we cannot see that change outside the function body.

The "number" parameter variable at function "passPointer()" copies the address of the
variable "num" from main() function, and proceed the operations inside the function
"passPointer()", but if the "number" address is changed inside the function "passPointer()",
it will be just changed like a local variable inside that function, so once it is finished,
the original variable "num" at main() remains same wiothout change.

*/

#include <iostream>

using namespace std;

// function definition
void passPointer(int *number) {
  cout << "Address of number inside function call = " << number << endl;
  cout << "Value of number inside function call = " << *number << endl;
  int value = 13;
  number = &value;  
  cout << "Address of number inside function call after assigning value = " << number << endl;
  *number = *number + 14;
  cout << "Value of number inside function call after plus = " << *number << endl;
}

int main() {
  // Initialize variable
  int num = 10;
  cout << "Value of number before function call = " << num << endl;
  // Call function
  cout << "Address of number before function call = " << &num << endl;
  passPointer(&num);
  cout << "Value of number after function call = " << num << endl;
  cout << "Address of number before function call = " << &num << endl;

  return 0;
}

/*
Value of number before function call = 10
Address of number before function call = 0x7ffe7de28b44
Address of number inside function call = 0x7ffe7de28b44
Value of number inside function call = 10
Address of number inside function call after assigning value = 0x7ffe7de28b14
Value of number inside function call after plus = 27
Value of number after function call = 10
Address of number before function call = 0x7ffe7de28b44
*/