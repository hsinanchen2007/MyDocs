// https://leetcode.com/problems/

// some often common headers and namespace
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

// solution
void myprint(int value) {
    cout << value << endl;
}
void myprint2(double value) {
    cout << value << endl;
}

int main()
{
    vector<int> values{1,2,3,4,5};

    // show elements in vector with different iterator ways
    for (auto&& value : values) {
        cout << value << " " << endl;
        value = value + 1;
    }
    cout << endl;
    for (auto &value : values) {
        cout << value << " " << endl;
        value = value + 1;
    }
    cout << endl;
    for (auto value : values) {
        cout << &value << " " << endl;
    }
    cout << endl;
    for (auto value : values) {
        cout << *(&value) << " " << endl;
    }
    cout << endl;
    for (vector<int>::iterator v = values.begin(); v < values.end(); ++v) {
        cout << *v << " " << endl;
    }
    cout << endl;
    for_each(values.begin(), values.end(), myprint);
    cout << endl;

    // operator, assign elements into vector
    // STL: Replaces the contents of the container.
    cout << "Copy constructor of vector from one to another" << endl;
    vector<int> myValues = values;
    for_each(myValues.begin(), myValues.end(), myprint);
    cout << endl;

    // assign(), assign one value, begin/end, or multiple individual values into vector
    // Note that to specific value per index, needed to use {} to the given value per index
    cout << "Assign one value to vector, one by one" << endl;
    myValues.assign({0, 1, 2, 3, 4});
    for_each(myValues.begin(), myValues.end(), myprint);
    cout << endl;

    // assign(), assign values from another vector, by begin/end iterators, to this one
    cout << "Assign one value to vector, by begin/end" << endl;
    myValues.assign(values.begin(), values.end());
    for_each(myValues.begin(), myValues.end(), myprint);
    cout << endl;

    // assign(), assign one value by specific size and its one value for all index locations
    cout << "Assign one value to multiple elements in vector, by one value" << endl;
    myValues.assign(5 /* size */, 10 /* value */);
    for_each(myValues.begin(), myValues.end(), myprint);
    cout << endl;

    // get_allocator(), still didn't know what's the advantage of get_allocator() usage
    // STL: Returns the allocator associated with the container.
    cout << "Before calling allocator, vector size is " << myValues.size() << endl;
    for_each(myValues.begin(), myValues.end(), myprint);
    int *newArray = myValues.get_allocator().allocate(100);
    cout << "After calling allocator, vector size is " << myValues.size() << endl;
    for_each(myValues.begin(), myValues.end(), myprint);
    for (int i=0; i<100; i++) {
        myValues.get_allocator().construct(&newArray[i], i);
    }
    for (int i=0; i<100; i++) {
        cout << newArray[i] << " ";
    }
    for (int i=0; i<100; i++) {
        myValues.get_allocator().destroy(&newArray[i]);
    }
    myValues.get_allocator().deallocate(newArray, 100);
    cout << endl;
    for_each(myValues.begin(), myValues.end(), myprint);
    cout << "After calling deallocate, vector size is " << myValues.size() << endl;

    // at(), read/write value at specific index location in vector. Note that this is only used within range
    // It cannot be used to "add/insert" new elements
    // STL: Returns a reference to the element at specified location pos, with bounds checking.
    // If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
    cout << "Use at() to read/write value in vector ";
    for (int i=0; i<5; i++) {
        myValues.at(i) = i + 1;
    }
    for (int i=0; i<5; i++) {
        cout << myValues.at(i) << " ";
    }
    cout << endl;

    // operator[], direct access by specifying index like array. Note that this is only used within range
    // and this way will not check out of range error. It cannot be used to "add/insert" new elements
    // STL: Returns a reference to the element at specified location pos. No bounds checking is performed.
    cout << "Use operator [] to read/write value in vector ";
    for (int i=0; i<5; i++) {
        cout << myValues[i] << " ";
    }
    cout << endl;

    // front(), get first element in vector
    // STL: Returns a reference to the first element in the container.
    // Calling front on an empty container is undefined.
    cout << "The first element in vector by front() is " << myValues.front() << endl;

    // back(), get last element in vector
    // STL: Returns a reference to the last element in the container.
    // Calling back on an empty container causes undefined behavior.
    cout << "The last element in vector by back() is " << myValues.back() << endl;

    // data(), return the pointer of vector
    // STL: Returns pointer to the underlying array serving as element storage. The pointer is such that range 
    // [data(); data() + size()) is always a valid range, even if the container is empty (data() is not dereferenceable 
    // in that case).
    cout << "The pointer of vector by data() is " << myValues.data() << endl;
    cout << "The vale of pointer of vector by data() is " << *myValues.data() << endl;

    // iterator
    cout << "Use iterator begin and end" << endl;
    for (auto it=myValues.begin(); it!=myValues.end(); it++) {
        cout << *it << " " << endl;
    }
    for (vector<int>::iterator it=myValues.begin(); it!=myValues.end(); it++) {
        cout << *it << " " << endl;
    }
    cout << "Use iterator rbegin and rend" << endl;
    for (auto it=myValues.rbegin(); it!=myValues.rend(); it++) {
        cout << *it << " " << endl;
    }

    // empty(), check if the vector is empty or not
    // STL: Checks if the container has no elements, i.e. whether begin() == end().
    cout << boolalpha;
    cout << "Is vector empty? " << myValues.empty() << endl;

    // size(), return the size of current vector
    // STL: Returns the number of elements in the container, i.e. std::distance(begin(), end()).
    cout << "Vector size is " << myValues.size() << endl;

    // max_size(), return max size of vector that operating system can allocate
    // STL: Returns the maximum number of elements the container is able to hold due to system or 
    // library implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
    cout << "Vector max size is " << myValues.max_size() << endl;

    // capacity(), return # of elements that current vector can hold
    cout << "Vector capacity is " << myValues.capacity() << endl;

    // reserve(), allocate the size of vector dynamically. Note that array cannot do this
    // also reserve() will only have impact to capacity(), not for size() or max_size()
    // STL: Increase the capacity of the vector to a value that's greater or equal to new_cap. 
    // If new_cap is greater than the current capacity(), new storage is allocated, otherwise the function 
    // does nothing.
    // reserve() does not change the size of the vector.
    // If new_cap is greater than capacity(), all iterators, including the past-the-end iterator, and all 
    // references to the elements are invalidated. Otherwise, no iterators or references are invalidated.
    myValues.reserve(101);
    cout << "New vector capacity is " << myValues.capacity() << endl;
    cout << "New vector size is still " << myValues.size() << endl;
    cout << "New vector max size is still " << myValues.max_size() << endl;

    // shrink_to_fit(), change vector size to only hold existing elements
    // STL: Requests the removal of unused capacity.
    // It is a non-binding request to reduce capacity() to size(). It depends on the implementation whether 
    // the request is fulfilled.
    // If reallocation occurs, all iterators, including the past the end iterator, and all references to the 
    // elements are invalidated. If no reallocation takes place, no iterators or references are invalidated.
    cout << "Initializing first 50 elements" << endl;
    for (int i=0; i<50; i++) {
        myValues.push_back(i+1);
    }
    myValues.shrink_to_fit();
    cout << "New vector capacity is " << myValues.capacity() << endl;
    cout << "New vector size is still " << myValues.size() << endl;
    cout << "New vector max size is still " << myValues.max_size() << endl;    

    // clear(), remove all elements in vector
    // STL: Erases all elements from the container. After this call, size() returns zero.
    // Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end 
    // iterators are also invalidated.  
    // Leaves the capacity() of the vector unchanged (note: the standard's restriction on the changes to capacity 
    // is in the specification of vector::reserve, see [1])
    myValues.clear();
    cout << "New vector capacity after clear() is " << myValues.capacity() << endl;
    cout << "New vector size after clear() is  " << myValues.size() << endl;
    cout << "New vector max size after clear() is  " << myValues.max_size() << endl;    

    // insert(), insert new elements at specific index location. Note that this required iterator as index, not
    // a simple index number as index. Also, this call may have runtime issue as it will need to move all elements
    // from that insert position back to the end
    // STL: Inserts elements at the specified location in the container.
    // 1-2) inserts value before pos
    // 3) inserts count copies of the value before pos
    // 4) inserts elements from range [first, last) before pos.
    // This overload has the same effect as overload (3) if InputIt is an integral type. (until C++11)
    // This overload participates in overload resolution only if InputIt qualifies as LegacyInputIterator, to avoid 
    // ambiguity with the overload (3). (since C++11) The behavior is undefined if first and last are iterators into *this.
    // 5) inserts elements from initializer list ilist before pos.
    // Causes reallocation if the new size() is greater than the old capacity(). If the new size() is greater than capacity(), 
    // all iterators and references are invalidated. Otherwise, only the iterators and references before the insertion point 
    // remain valid. The past-the-end iterator is also invalidated.
    cout << "Initialize and insert new value at 3rd location" << endl;
    myValues.assign(5, 1);
    myValues.insert(myValues.begin() + 2, 101);
    for_each(myValues.begin(), myValues.end(), myprint);

    // emplace(), insert a new element instead of copy to vector. Note that this operation is faster than copy like push_back()
    // STL: Inserts a new element into the container directly before pos.
    // The element is constructed through std::allocator_traits::construct, which typically uses placement-new to construct the 
    // element in-place at a location provided by the container. However, if the required location has been occupied by an existing 
    // element, the inserted element is constructed at another location at first, and then move assigned into the required location.
    // The arguments args... are forwarded to the constructor as std::forward<Args>(args).... args... may directly or indirectly 
    // refer to a value in the container.
    // If the new size() is greater than capacity(), all iterators and references are invalidated. Otherwise, only the iterators and 
    // references before the insertion point remain valid. The past-the-end iterator is also invalidated.
    cout << "emplace() call to vector" << endl;
    myValues.clear();
    for (int i=0; i<100; i++) {
        myValues.emplace(myValues.begin() + i, i+1);
    }
    for_each(myValues.begin(), myValues.end(), myprint);

    // erase(), remove the specific ones by iterator
    // STL: Erases the specified elements from the container.
    // 1) Removes the element at pos.
    // 2) Removes the elements in the range [first, last).
    // Invalidates iterators and references at or after the point of the erase, including the end() iterator.
    // The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferenceable) cannot 
    // be used as a value for pos.
    // The iterator first does not need to be dereferenceable if first==last: erasing an empty range is a no-op.
    cout << "erase() call to vector by iterator, begin to end" << endl;
    myValues.erase(myValues.begin(), myValues.end());
    for_each(myValues.begin(), myValues.end(), myprint);

    // push_back(), add a new element into vector at the end
    // STL: Appends the given element value to the end of the container.
    // 1) The new element is initialized as a copy of value.
    // 2) value is moved into the new element.
    // If the new size() is greater than capacity() then all iterators and references (including the past-the-end iterator) are 
    // invalidated. Otherwise only the past-the-end iterator is invalidated.
    cout << "push_back() call to vector for new values" << endl;
    myValues.push_back(2);
    myValues.push_back(4);
    myValues.push_back(6);
    myValues.push_back(8);
    myValues.push_back(10);
    for_each(myValues.begin(), myValues.end(), myprint);

    // emplace_back(), similar to push_back() that add new element into the end of vector, but it constructs element and 
    // add it directly, which is faster than push_back() by copy way
    // STL: Appends a new element to the end of the container. The element is constructed through std::allocator_traits::construct, 
    // which typically uses placement-new to construct the element in-place at the location provided by the container. 
    // The arguments args... are forwarded to the constructor as std::forward<Args>(args)....
    // If the new size() is greater than capacity() then all iterators and references (including the past-the-end iterator) are 
    // invalidated. Otherwise only the past-the-end iterator is invalidated.
    cout << "emplace_back() call to vector for new values" << endl;
    myValues.emplace_back(2);
    myValues.emplace_back(4);
    myValues.emplace_back(6);
    myValues.emplace_back(8);
    myValues.emplace_back(10);
    for_each(myValues.begin(), myValues.end(), myprint);

    // pop_back(), remove one element from the end of vector
    // STL: Removes the last element of the container.
    // Calling pop_back on an empty container results in undefined behavior.
    // Iterators and references to the last element, as well as the end() iterator, are invalidated.
    cout << "pop_back() call to vector for old values" << endl;
    myValues.pop_back();
    myValues.pop_back();
    myValues.pop_back();
    myValues.pop_back();
    myValues.pop_back();
    for_each(myValues.begin(), myValues.end(), myprint);

    // resize(), change current size to different one, and this will affact size() return
    // if the given re-size is smaller than current one, the last elements will be removed
    // STL: Resizes the container to contain count elements.
    // If the current size is greater than count, the container is reduced to its first count elements.
    // If the current size is less than count,
    // 1) additional default-inserted elements are appended
    // 2) additional copies of value are appended.
    cout << "Current size before resize() " << myValues.size() << endl;
    myValues.resize(3);
    cout << "Current size after resize() to smaller " << myValues.size() << endl;
    for_each(myValues.begin(), myValues.end(), myprint);

    // it will assign default value into new resized larger vector elements, which is 0 here
    myValues.resize(10);
    cout << "Current size after resize() to larger " << myValues.size() << endl;
    for_each(myValues.begin(), myValues.end(), myprint);

    // swap(), swap two vectors
    cout << "Before swap() " << endl;
    vector<double> v1 = {1.1, 2.2, 3.3, 4.4, 5.5};
    vector<double> v2 = {6.6, 7.7, 8.8, 9.9, 10.10};
    for_each(v1.begin(), v1.end(), myprint2);
    for_each(v2.begin(), v2.end(), myprint2);
    v1.swap(v2);
    cout << "After swap() " << endl;
    for_each(v1.begin(), v1.end(), myprint2);
    for_each(v2.begin(), v2.end(), myprint2);

    // std::swap(), similar to vector's swap()
    cout << "After std::swap() " << endl;
    std::swap(v1, v2);
    for_each(v1.begin(), v1.end(), myprint2);
    for_each(v2.begin(), v2.end(), myprint2);

    // std::erase(), only available from C++ 20 or above
    // std::erase_if(), only available from C++ 20 or above
    // STL: 1) Erases all elements that compare equal to value from the container. Equivalent to
    // auto it = std::remove(c.begin(), c.end(), value);
    // auto r = std::distance(it, c.end());
    // c.erase(it, c.end());
    // return r;
    // 2) Erases all elements that satisfy the predicate pred from the container. Equivalent to
    // auto it = std::remove_if(c.begin(), c.end(), pred);
    // auto r = std::distance(it, c.end());
    // c.erase(it, c.end());
    // return r;
    // std::vector<char> cnt(10);
    // std::erase(cnt, 0);
    // auto erased = std::erase_if(cnt, [](char x) { return (x - '0') % 2 == 0; });

    return 0;
}
