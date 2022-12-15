/*

https://www.educative.io/module/lesson/cpp-basics/g2AgxlmOrlD

Dynamic arrays
In the arrays lesson, we discussed static arrays. In a static array, a fixed amount 
of memory is allocated to the array during the compile time. Therefore, we cannot 
allocate more memory to the arrays during program execution.

Suppose we have declared an array that can store five integer values.

What if we want to store more than five values in an array? Here is dynamic arrays 
come in!

Dynamic arrays can grow or shrink during the program execution.
Declaration
The general syntax for declaring dynamic arrays is given below:

svg viewer

Initialization
We can initialize a dynamic array just like a static array.

svg viewer

Deallocating array 
The basic syntax for deallocating a dynamic array is given below:

svg viewer

Print all elements of a dynamic array
The code will initialize the dynamic array and then print all its elements using the 
for loop.

*/

#include <iostream>

using namespace std;

// printArray function
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// main function
int main() {
  // Initialize variable size
  int size = 5;

  // Create Array 
  int * Arr = new int[size];

  // Fill elements of an array
  for (int i = 0; i < size; i++) {
    Arr[i] = i;
  }

  // Call printArray function 
  printArray(Arr, size);  

  // Create new array
  int * ResizeArray = new int[size + 2];

  // Copy elements in new arary
  for (int i = 0; i < size; i++) {
    ResizeArray[i] = Arr[i];
  }

  // Delete old array
  delete[] Arr;

  // Pointer Array will point to ResizeArray
  Arr = ResizeArray;

  // Store new values
  Arr[size] = 90;
  Arr[size + 1] = 100;
  
  // Call printArray function
  printArray(Arr, size + 2);
}
