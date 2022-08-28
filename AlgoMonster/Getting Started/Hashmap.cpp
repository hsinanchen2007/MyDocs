/*

Improvements
As the possibility of keys increases, collision (where two different items have the same hash value) is unavoidable 
by the pigeonhole principle. It is necessary to consider what happens when two keys with the same hash values are 
used in this table.

With the current situation, the data structure will treat them as interchangeable, leading to unexpected behavior. 
For example, you want to set the entry for "Anne", but doing so will change the entry for ”John”, which we often do 
not want.

One method of dealing with this problem is Separate Chaining. Instead of storing the entry directly in the array, 
we use a list of key-value pairs in each entry in the array instead. When we set the value represented by a key in 
the hash table, after finding out the key's hash, we first search for if the key exists already in the list represented 
by the hash value. If so, we can update the value to a new one. Otherwise, we can append the new key-value pair into 
the list. Searching for an item takes similar steps.

The list is usually a linked list, although other lists that can dynamically increase in The size will do as well.

Below is a graphical explanation.

First slide
Previous
Next
Another strategy is Open Addressing, where we use the same table to store everything, but we find the next unused space 
instead when adding a new key.

Efficiency
Assuming the hash function uses constant time, the average time complexity is O(n / k) for each insertion/access operation 
on the table, where n is the number of entries in the hash table and k is the array size of the table. This is because 
of the pigeonhole principle.

However, in the worst-case scenario, where everything in the array is hashed to the same key, the time complexity is O(n), 
which is worse.

That is why having a good hash function is very important to the efficiency of a hash table. Having a simple hash function 
ensures that each key lookup is efficient. Having a hash function where collision is unlikely ensures that the number of 
entries at each index is kept at minimal, thus improving each lookup's efficiency.

Most modern programming languages offer a dynamic hash table: a hash table whose size dynamic changes as more items are added. 
Because of this setup, each access to the table has an average time complexity of O(1), which is very close to accessing 
an array. When you need a non-integer index, you can use a hash table instead. For example, Python has the dict class, while 
Java has the HashMap class.

Here is a demonstration of how you would use a hash table in specific languages:

get_counter() takes an integer array and returns a hash table with the array elements as keys and their frequencies as values.


https://en.wikipedia.org/wiki/Hash_table#Separate_chaining
https://en.wikipedia.org/wiki/Hash_table#Open_addressing

*/

#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <map> // map
#include <sstream> // istringstream
#include <string> // getline, string
#include <unordered_map> // unordered_map
#include <vector> // vector

std::unordered_map<int, int> get_counter(std::vector<int> arr) {
    // initialize a hash map to store each number and its count
    std::unordered_map<int, int> counter;
    for (int num : arr) {
        // check if num is a key in the hash map
        if (counter.count(num)) {
            // update the count of num to increase by 1
            counter[num] += 1;
        } else {
            // set the count of num to 1
            counter[num] = 1;
        }
    }
    return counter;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<int> arr = get_words<int>();
    std::unordered_map<int, int> counter = get_counter(arr);
    std::map<int, int> ordered_counter(counter.begin(), counter.end());
    for (auto const& [key, val] : ordered_counter) {
        std::cout << key << ' ' << val << std::endl;
    }
}
