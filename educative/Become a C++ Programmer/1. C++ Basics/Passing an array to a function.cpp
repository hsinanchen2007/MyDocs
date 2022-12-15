/*

https://www.educative.io/module/lesson/cpp-basics/x1OBmYpLlP3

Passing an array to a function#
To pass an array to a function, we just have to specify the array type, followed by 
an array name and square brackets in the function parameters.

*/

#include <iostream>

using namespace std;

// print_array function will print the values of an array
void print_array(int number[], int size) {
  for (int i = 0; i < size; i++) {
    cout << number[i] << " ";
  }
  cout << endl;
}

// modify_array function
void modify_array(int number[], int size) {
  // Traverse array
  for (int i = 0; i < size; i++) {
    // If value less tha 50 set it to -1
    if (number[i] < 50)
      number[i] = -1;
  }
  cout << "Values of array inside the function:" << endl;
  // Call print_array function 
  print_array(number,size);
}

// main function
int main() {
  // Initialize size of an array
  const int size = 8;
  // Initialize values of array
  int number[size] = {67, 89, 56, 43, 29, 15, 90, 67};

  cout << "Values of array before function call:" << endl;
  // Call print_array function
  print_array(number,size);
  // Call modify_array function
  modify_array(number, size);
  cout << "Values of array after function call:" << endl;
  // Call print_array function
  print_array(number,size);

}
