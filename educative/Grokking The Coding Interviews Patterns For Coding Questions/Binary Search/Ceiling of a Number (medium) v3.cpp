/*

https://www.educative.io/courses/grokking-the-coding-interview/qA5wW7R8ox7

Solution#
This problem follows the Binary Search pattern. Since Binary Search helps us find a number in a sorted array 
efficiently, we can use a modified version of the Binary Search to find the ceiling of a number.

We can use a similar approach as discussed in Order-agnostic Binary Search. We will try to search for the ‘key’ 
in the given array. If we find the ‘key’, we return its index as the ceiling. If we can’t find the ‘key’, the 
next big number will be pointed out by the index start. Consider Example-2 mentioned above:

As key > arr[middle], therefore start = middle + 1  
    1   
    3   
    8   
    10   
    15   

As key > arr[middle], therefore start = middle + 1  
    1   
    3   
    8   
    10   
    15   
    1   
    3   
    8   
    10   
    15   

As key < arr[middle], therefore end = middle - 1, and the loop will break as end has become less than start      
Search 'key' = '12'  

Since we are always adjusting our range to find the ‘key’, when we exit the loop, the start of our range will point 
to the smallest number greater than the ‘key’ as shown in the above picture.

We can add a check in the beginning to see if the ‘key’ is bigger than the biggest number in the input array. 
If so, we can return ‘-1’.

Time complexity#
Since we are reducing the search range by half at every step, this means that the time complexity of our algorithm 
will be O(logN) where ‘N’ is the total elements in the given array.

Space complexity#
The algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <vector>

class CeilingOfANumber {
 public:
  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    if (key > arr[arr.size() - 1]) {  // if the 'key' is bigger than the biggest element
      return -1;
    }

    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (key < arr[mid]) {
        end = mid - 1;
      } else if (key > arr[mid]) {
        start = mid + 1;
      } else {  // found the key
        return mid;
      }
    }
    // since the loop is running until 'start <= end', so at the end of the while loop, 'start ==
    // end+1' we are not able to find the element in the given array, so the next big number will be
    // arr[start]
    return start;
  }
};

int main(int argc, char* argv[]) {
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 6) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 17) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, -1) << endl;
}

