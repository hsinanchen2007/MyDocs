/*

https://www.educative.io/courses/grokking-the-coding-interview/gk20xz4VwpG

Solution
One straight forward solution can be to use a HashMap kind of data structure and iterate 
through the input:

If number is already present in HashMap, remove it.
If number is not present in HashMap, add it.
In the end, only number left in the HashMap is our required single number.
Time and space complexity Time Complexity of the above solution will be O(n) and space 
complexity will also be O(n)

Can we do better than this using the XOR Pattern?

Solution with XOR

Recall the following two properties of XOR:

It returns zero if we take XOR of two same numbers.
It returns the same number if we XOR with zero.
So we can XOR all the numbers in the input; duplicate numbers will zero out each other and 
we will be left with the single number.

Time Complexity: Time complexity of this solution is O(n) as we iterate through all numbers 
of the input once.

Space Complexity: The algorithm runs in constant space O(1).

*/

using namespace std;

#include <iostream>
#include <vector>

class SingleNumber {
  public:
    static int findSingleNumber(const vector<int>& arr) {
      int num = 0;
      for (int i=0; i < arr.size(); i++) {
        num = num ^ arr[i];
      }
      return num;
    }
};

int main(int argc, char* argv[]) {
  cout << SingleNumber::findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;
}

