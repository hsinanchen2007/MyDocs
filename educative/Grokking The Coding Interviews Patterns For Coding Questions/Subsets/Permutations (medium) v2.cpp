/*

https://www.educative.io/courses/grokking-the-coding-interview/B8R83jyN3KY

Solution
This problem follows the Subsets pattern and we can follow a similar Breadth First Search 
(BFS) approach. However, unlike Subsets, every permutation must contain all the numbers.

Let’s take the example-1 mentioned above to generate all the permutations. Following a BFS 
approach, we will consider one number at a time:

If the given set is empty then we have only an empty permutation set: []
Let’s add the first element (1), the permutations will be: [1]
Let’s add the second element (3), the permutations will be: [3,1], [1,3]
Let’s add the third element (5), the permutations will be: [5,3,1], [3,5,1], [3,1,5], [5,1,3], 
[1,5,3], [1,3,5]
Let’s analyze the permutations in the 3rd and 4th step. How can we generate permutations 
in the 4th step from the permutations of the 3rd step?

If we look closely, we will realize that when we add a new number (5), we take each permutation 
of the previous step and insert the new number in every position to generate the new permutations. 
For example, inserting ‘5’ in different positions of [3,1] will give us the following permutations:

Inserting ‘5’ before ‘3’: [5,3,1]
Inserting ‘5’ between ‘3’ and ‘1’: [3,5,1]
Inserting ‘5’ after ‘1’: [3,1,5]
Here is the visual representation of this algorithm:

    []   
    []   
    [1]   
    [5]   
    [1,5]   
    [3]   
    [1,3]   
    [5,3]   
    [1,5,3]   
 Given set:  
    1   
    3   
    5   
    [1]   
 Given set:  
    [3,1]   
    [1,3]   
    [5,3,1]   
    [3,5,1]   
    [3,1,5]   
    [5,1,3]   
    [1,5,3]   
    [1,3,5]   

Time complexity
We know that there are a total of N! permutations of a set with ‘N’ numbers. In the algorithm 
above, we are iterating through all of these permutations with the help of the two ‘for’ loops. 
In each iteration, we go through all the current permutations to insert a new number in them 
on line 17 (line 23 for C++ solution). To insert a number into a permutation of size ‘N’ will 
take O(N), which makes the overall time complexity of our algorithm O(N*N!)

Space complexity
All the additional space used by our algorithm is for the result list and the queue to store the 
intermediate permutations. If you see closely, at any time, we don’t have more than N! permutations 
between the result list and the queue. Therefore the overall space complexity to store N!
permutations each containing N elements will be O(N*N!)

*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Permutations {
 public:
  static vector<vector<int>> findPermutations(const vector<int>& nums) {
    vector<vector<int>> result;
    queue<vector<int>> permutations;
    permutations.push(vector<int>());
    for (auto currentNumber : nums) {
      // we will take all existing permutations and add the current number to create new
      // permutations
      int n = permutations.size();
      for (int i = 0; i < n; i++) {
        vector<int> oldPermutation = permutations.front();
        permutations.pop();
        // create a new permutation by adding the current number at every position
        for (int j = 0; j <= oldPermutation.size(); j++) {
          vector<int> newPermutation(oldPermutation);
          newPermutation.insert(newPermutation.begin() + j, currentNumber);
          if (newPermutation.size() == nums.size()) {
            result.push_back(newPermutation);
          } else {
            permutations.push(newPermutation);
          }
        }
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Permutations::findPermutations(vector<int>{1, 3, 5});
  cout << "Here are all the permutations: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
