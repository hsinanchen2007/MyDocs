/*

https://www.educative.io/module/lesson/cpp-basics/m7Y7LwvPvQG

Explanation
First, we allocated the dynamic array of size 10.
Then, we initialized the array with random numbers using the rand() method.
The elements of the array are then printed using a for loop.
Then we calculated the mean by calculating the sum and then dividing it by size.
Afterwards, the standard deviation is calculated by finding the average of the squared 
differences from the mean and then taking a square root of it.
In the end, the memory of the dynamic array was deallocated by using delete keyword.

*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int size = 10;

  //Declare dynamic array
  int *Array = new int[size];

  //Initialize dynamic array
  for(int i = 0 ; i < size; i++){
    Array[i] = rand() % 100; 
  }   

  //Prints dynamic array
  cout << "Elements of array: ";
  for(int i = 0 ; i < size; i++){
    cout << Array[i] << " ";
  } 
  cout << endl;

  //Calculate mean and print
  float sum = 0;
  for(int i = 0 ; i < size; i++){
    sum += Array[i];
  } 
  float mean = sum/size ;
  cout << "Mean: " << mean << endl;

  //Calculate standard deviation and print
  float stdDev = 0;
  for(int i = 0 ; i < size; i++){
    stdDev += pow(Array[i] - mean, 2);
  }
  stdDev = sqrt(stdDev / size);
  cout << "Standard Deviation: " << stdDev << endl;
  // Deletes a memory allocated to dynamic array
  delete[] Array;
}
