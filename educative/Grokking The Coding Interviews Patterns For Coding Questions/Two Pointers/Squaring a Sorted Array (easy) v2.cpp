/*

Solution
This is a straightforward question. The only trick is that we can have negative numbers in the input array, 
which will make it a bit difficult to generate the output array with squares in sorted order.

An easier approach could be to first find the index of the first non-negative number in the array. After that, 
we can use Two Pointers to iterate the array. One pointer will move forward to iterate the non-negative numbers, 
and the other pointer will move backward to iterate the negative numbers. At any step, whichever number gives 
us a bigger square will be added to the output array. For the above-mentioned Example-1, we will do something 
like this:

-2
-1
0
2
3

Since the numbers at both ends can give us the largest square, an alternate approach could be to use two 
pointers starting at both ends of the input array. At any step, whichever pointer gives us the bigger square, 
we add it to the result array and move to the next/previous number according to the pointer. For the above-mentioned 
Example-1, we will do something like this:

    -2   
    -1   
    0   
    2   
    3   

Time complexity
The above algorithm’s time complexity will be O(N) as we are iterating the input array only once.

Space complexity
The above algorithm’s space complexity will also be O(N); this space will be used for the output array.

*/

using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    int highestSquareIdx = n - 1;
    int left = 0, right = n - 1;
    while (left <= right) {
      int leftSquare = arr[left] * arr[left];
      int rightSquare = arr[right] * arr[right];
      if (leftSquare > rightSquare) {
        squares[highestSquareIdx--] = leftSquare;
        left++;
      } else {
        squares[highestSquareIdx--] = rightSquare;
        right--;
      }
    }
    return squares;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = SortedArraySquares::makeSquares(vector<int>{-2, -1, 0, 2, 3});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = SortedArraySquares::makeSquares(vector<int>{-3, -1, 0, 1, 2});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}

