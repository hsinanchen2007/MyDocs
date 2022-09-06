/*

https://www.educative.io/courses/grokking-the-coding-interview/g2w6QPBA2Nk

Problem Statement#
Given an array of lowercase letters sorted in ascending order, find the smallest letter in the 
given array greater than a given ‘key’.

Assume the given array is a circular list, which means that the last letter is assumed to be 
connected with the first letter. This also means that the smallest letter in the given array is 
greater than the last letter of the array and is also the first letter of the array.

Write a function to return the next letter of the given ‘key’.

Example 1:

Input: ['a', 'c', 'f', 'h'], key = 'f'
Output: 'h'
Explanation: The smallest letter greater than 'f' is 'h' in the given array.

Example 2:

Input: ['a', 'c', 'f', 'h'], key = 'b'
Output: 'c'
Explanation: The smallest letter greater than 'b' is 'c'.

Example 3:

Input: ['a', 'c', 'f', 'h'], key = 'm'
Output: 'a'
Explanation: As the array is assumed to be circular, the smallest letter greater than 'm' is 'a'.

Example 4:

Input: ['a', 'c', 'f', 'h'], key = 'h'
Output: 'a'
Explanation: As the array is assumed to be circular, the smallest letter greater than 'h' is 'a'.

*/

using namespace std;

#include <iostream>
#include <vector>

class NextLetter {
 public:
  static char searchNextLetter(const vector<char>& letters, char key) {
    // TODO: Write your code here
    int left = 0;
    int right = letters.size() - 1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (letters[middle] < key) {
        left = middle + 1;
      } else if (letters[middle] > key) {
        right = middle - 1;
      } else if (letters[middle] == key) {
        left = middle + 1;
      }
    }

    // tricky part is here
    return letters[left % letters.size()];
  }
};

int main(int argc, char* argv[]) {
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'f') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'b') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'm') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'h') << endl;
}

