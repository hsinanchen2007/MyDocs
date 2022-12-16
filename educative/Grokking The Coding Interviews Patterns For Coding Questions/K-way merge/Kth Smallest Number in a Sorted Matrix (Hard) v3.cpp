/*

https://www.educative.io/courses/grokking-the-coding-interview/x1NJVYKNvqz

An Alternate Solution
Since each row and column of the matrix is sorted, is it possible to use Binary Search to 
find the Kth smallest number?

The biggest problem to use Binary Search, in this case, is that we don’t have a straightforward 
sorted array, instead, we have a matrix. As we remember, in Binary Search, we calculate the 
middle index of the search space (‘1’ to ‘N’) and see if our required number is pointed out by 
the middle index; if not we either search in the lower half or the upper half. In a sorted matrix, 
we can’t really find a middle. Even if we do consider some index as middle, it is not straightforward 
to find the search space containing numbers bigger or smaller than the number pointed out by the 
middle index.

An alternative could be to apply the Binary Search on the “number range” instead of the “index range”. 
As we know that the smallest number of our matrix is at the top left corner and the biggest number 
is at the bottom right corner. These two numbers can represent the “range” i.e., the start and the 
end for the Binary Search. Here is how our algorithm will work:

Start the Binary Search with start = matrix[0][0] and end = matrix[n-1][n-1].
Find middle of the start and the end. This middle number is NOT necessarily an element in the matrix.
Count all the numbers smaller than or equal to middle in the matrix. As the matrix is sorted, we can 
do this in O(N).

While counting, we can keep track of the “smallest number greater than the middle” (let’s call it n1) 
and at the same time the “biggest number less than or equal to the middle” (let’s call it n2). These two 
numbers will be used to adjust the “number range” for the Binary Search in the next iteration.

If the count is equal to ‘K’, n2 will be our required number as it is the “biggest number less than or 
equal to the middle”, and is definitely present in the matrix.
If the count is less than ‘K’, we can update start = n2 to search in the higher part of the matrix and 
if the count is greater than ‘K’, we can update end = n1 to search in the lower part of the matrix in 
the next iteration.

Here is the visual representation of our algorithm:

 middle = (start + end) / 2   middle = (2 + 11) / 2 =  6   
    2   
    3   
    5   
    6   
    7   
    8   
    8   
    10   
    11   
    2   
    3   
    5   
    6   
    7   
    8   
    8   
    10   
    11   
 middle = (start + end) / 2middle = (7 + 11) / 2 = 9  
 Smallest number greater than the middle(9): 10Biggest number less than or equal to the middle(9): 8    
 Number of elements less than or equal to the middle(9) = 7  
 Smallest number greater than the middle(6): 7Biggest number less than or equal to the middle(6): 6    
 Number of elements less than or equal to the middle(6) = 4  
    2   
    3   
    5   
    6   
    7   
    8   
    8   
    10   
    11   
 middle = (start + end) / 2middle = (7 + 8) / 2 = 7  
 As there are only 4 elements less than or equal to the middle, and we are looking for the 5th smallest number, 
 so let's search higher and update our 'start' to the smallest number greater than the middle.  
 As there are 7 elements less than or equal to the middle, and we are looking for the 5th smallest number, so let's 
 search lower and update our 'end'  to the biggest number less than or equal to the middle.  
 Step 1:  
 Step 2:  
 Step 3:  
 Smallest number greater than the middle(7): 8Biggest number less than or equal to the middle(7): 7    
 Number of elements less than or equal to the middle(7) = 5  

 As there are 5 elements less than or equal to the middle therefore '7', which is the biggest number less than 
 or equal to the middle, is our required number  

Time complexity
The Binary Search could take O(log(max-min )) iterations where ‘max’ is the largest and ‘min’ is the smallest 
element in the matrix and in each iteration we take O(N) for counting, therefore, the overall time complexity 
of the algorithm will be O(N*log(max-min)).

Space complexity
The algorithm runs in constant space O(1).

*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestInSortedMatrix {
 public:
  static int findKthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int start = matrix[0][0], end = matrix[n - 1][n - 1];
    while (start < end) {
      int mid = start + (end - start) / 2;
      // first number is the smallest and the second number is the largest
      pair<int, int> smallLargePair = {matrix[0][0], matrix[n - 1][n - 1]};
      int count = countLessEqual(matrix, mid, smallLargePair);
      if (count == k) {
        return smallLargePair.first;
      }

      if (count < k) {
        start = smallLargePair.second;  // search higher
      } else {
        end = smallLargePair.first;  // search lower
      }
    }

    return start;
  }

 private:
  static int countLessEqual(vector<vector<int>> &matrix, int mid, pair<int, int> &smallLargePair) {
    int count = 0;
    int n = matrix.size(), row = n - 1, col = 0;
    while (row >= 0 && col < n) {
      if (matrix[row][col] > mid) {
        // as matrix[row][col] is bigger than the mid, let's keep track of the
        // smallest number greater than the mid
        smallLargePair.second = min(smallLargePair.second, matrix[row][col]);
        row--;
      } else {
        // as matrix[row][col] is less than or equal to the mid, let's keep track of the
        // biggest number less than or equal to the mid
        smallLargePair.first = max(smallLargePair.first, matrix[row][col]);
        count += row + 1;
        col++;
      }
    }
    return count;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> matrix2 = {vector<int>{2, 6, 8}, vector<int>{3, 7, 10},
                                 vector<int>{5, 8, 11}};
  int result = KthSmallestInSortedMatrix::findKthSmallest(matrix2, 5);
  cout << "Kth smallest number is: " << result << endl;
}

