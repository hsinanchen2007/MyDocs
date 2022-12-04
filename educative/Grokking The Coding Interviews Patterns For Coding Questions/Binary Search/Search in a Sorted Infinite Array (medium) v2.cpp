/*

Solution#
The problem follows the Binary Search pattern. Since Binary Search helps us find a number 
in a sorted array efficiently, we can use a modified version of the Binary Search to find 
the ‘key’ in an infinite sorted array.

The only issue with applying binary search in this problem is that we don’t know the bounds 
of the array. To handle this situation, we will first find the proper bounds of the array 
where we can perform a binary search.

An efficient way to find the proper bounds is to start at the beginning of the array with 
the bound’s size as ‘1’ and exponentially increase the bound’s size (i.e., double it) until 
we find the bounds that can have the key.

Consider Example-1 mentioned above:

 key = 16  
 Since key is greater than the element at index end, we will double our bounds   
 Since key is greater than the element at index end, we will double our bounds   
    4   
    6   
    8   
    10   
    12   
    14   
    16   
    18   
    20   
    22   
    24   
    26   
    28   
    30   
    4   
    6   
    8   
    10   
    12   
    14   
    16   
    18   
    20   
    22   
    24   
    26   
    28   
    30   
    4   
    6   
    8   
    10   
    12   
    14   
    16   
    18   
    20   
    22   
    24   
    26   
    28   
    30   

Since key is less than the element at index end, we've found the searchable bounds  
Bounds size = 2  
Bounds size = 4  
Bounds size = 8  

Once we have searchable bounds we can apply the binary search.

Time complexity#
There are two parts of the algorithm. In the first part, we keep increasing the bound’s size exponentially 
(double it every time) while searching for the proper bounds. Therefore, this step will take O(logN)
assuming that the array will have maximum ‘N’ numbers. In the second step, we perform the binary search 
which will take O(logN), so the overall time complexity of our algorithm will be O(logN + logN) which is 
asymptotically equivalent to O(logN)

Space complexity#
The algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayReader {
 public:
  vector<int> arr;

  ArrayReader(const vector<int> &arr) { this->arr = arr; }

  virtual int get(int index) {
    if (index >= arr.size()) {
      return numeric_limits<int>::max();
    }
    return arr[index];
  }
};

class SearchInfiniteSortedArray {
 public:
  static int search(ArrayReader *reader, int key) {
    // find the proper bounds first
    int start = 0, end = 1;
    while (reader->get(end) < key) {
      int newStart = end + 1;
      end += (end - start + 1) * 2;  // increase to double the bounds size
      start = newStart;
    }
    return binarySearch(reader, key, start, end);
  }

 private:
  static int binarySearch(ArrayReader *reader, int key, int start, int end) {
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (key < reader->get(mid)) {
        end = mid - 1;
      } else if (key > reader->get(mid)) {
        start = mid + 1;
      } else {  // found the key
        return mid;
      }
    }

    return -1;
  }
};

int main(int argc, char *argv[]) {
  ArrayReader *reader =
      new ArrayReader(vector<int>{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
  cout << SearchInfiniteSortedArray::search(reader, 16) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 11) << endl;
  reader = new ArrayReader(vector<int>{1, 3, 8, 10, 15});
  cout << SearchInfiniteSortedArray::search(reader, 15) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 200) << endl;
  delete reader;
}

