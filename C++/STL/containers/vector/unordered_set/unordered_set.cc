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
void printMySetStr(string element) {
    cout << element << " ";
}

template<typename Os, typename Container>
inline Os& operator<<(Os& os, Container const& container)
{
    os << "{ ";
    for (const auto& item : container) {
        os << item << ' ';
    }
    return os << "}";
} 

// main
int main() {
    // STL unordered_set study
    unordered_set<int> myUnOrderedInt_Set1;
    unordered_set<double> myUnOrderedDouble_Set2;
    unordered_set<string> myUnOrderedString_Set3;

    // find target within vector, two numbers sum up = target
    vector<int> myV = {1, 3, 5, 7, 9};
    int target = 12;

    for (int i = 0; i < myV.size(); i++) {
        myUnOrderedInt_Set1.insert(myV[i]);
    }

    for (int i = 0; i < myV.size(); i++) {
        int tmp = target - myV[i];
        if (myUnOrderedInt_Set1.find(tmp) != myUnOrderedInt_Set1.end()) {
            cout << "Find answer of " << myV[i] << " and " << tmp << endl;
        }
    }

    // begin()/end()/cbegin()/cend(), iterator to all elements in set. Note that for unordered_set/unordered_map,
    // there is no such rbegin()/rend() usage
    // STL: Returns an iterator to the first element of the unordered_set.
    // If the unordered_set is empty, the returned iterator will be equal to end().
    // STL: Returns an iterator to the element following the last element of the unordered_set.
    // This element acts as a placeholder; attempting to access it results in undefined behavior.
    // search key of string
    myUnOrderedString_Set3.emplace("key1");
    myUnOrderedString_Set3.emplace("key2");
    myUnOrderedString_Set3.emplace("key3");
    myUnOrderedString_Set3.emplace("key123");
    myUnOrderedString_Set3.emplace("key321");

    if (myUnOrderedString_Set3.find("key1234")!= myUnOrderedString_Set3.end()) {
        cout << "Found key1234" << endl;
    } else {
        cout << "key1234 doesn't exist. Here are keys in unordered_set: " << endl;
        for (auto item = myUnOrderedString_Set3.begin(); item != myUnOrderedString_Set3.end(); item++) {
            cout << *item << endl;
        }
    }

    // empty(), check if the set is empty or not
    // STL: Checks if the container has no elements, i.e. whether begin() == end().
    cout << boolalpha << "myUnOrderedString_Set3 is empty? " << myUnOrderedString_Set3.empty()? "yes" : "no";
    cout << endl;

    // size(), current # of elements in the set
    cout << "How many items in myUnOrderedString_Set3? " << myUnOrderedString_Set3.size() << endl;

    // max_size(), max # of elements can be added in the set based on current system
    // STL: Returns the maximum number of elements the container is able to hold due to system or library 
    // implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
    cout << "Max size of this system can hold elements in the set? " << myUnOrderedString_Set3.max_size() << endl;

    // clear(), remove all elements in the set
    // STL: Erases all elements from the container. After this call, size() returns zero.
    // Invalidates any references, pointers, or iterators referring to contained elements. May also invalidate past-the-end iterators.
    myUnOrderedString_Set3.clear();
    cout << "How many items in myUnOrderedString_Set3 after clear() call? " << myUnOrderedString_Set3.size() << endl;

    // insert(), add one element into unordered_set, the key and value are same as the given key
    // STL: Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
    // 1-2) Inserts value.
    // 3-4) Inserts value, using hint as a non-binding suggestion to where the search should start.
    // 5) Inserts elements from range [first, last). If multiple elements in the range have keys that compare equivalent, it is unspecified 
    // which element is inserted (pending LWG2844).
    // 6) Inserts elements from initializer list ilist. If multiple elements in the range have keys that compare equivalent, it is unspecified 
    // which element is inserted (pending LWG2844).
    // 7) If nh is an empty node handle, does nothing. Otherwise, inserts the element owned by nh into the container , if the container doesn't 
    // already contain an element with a key equivalent to nh.key(). The behavior is undefined if nh is not empty and 
    // get_allocator() != nh.get_allocator().
    // 8) If nh is an empty node handle, does nothing and returns the end iterator. Otherwise, inserts the element owned by nh into the 
    // container, if the container doesn't already contain an element with a key equivalent to nh.key(), and returns the iterator pointing 
    // to the element with key equivalent to nh.key() (regardless of whether the insert succeeded or failed). If the insertion succeeds, 
    // nh is moved from, otherwise it retains ownership of the element. The element is inserted as close as possible to hint. The behavior 
    // is undefined if nh is not empty and get_allocator() != nh.get_allocator().
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count(). If the insertion 
    // is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and 
    // references obtained to that element before it was extracted become valid. (since C++17)
    myUnOrderedDouble_Set2.insert(1.2);
    myUnOrderedDouble_Set2.insert(2.3);
    myUnOrderedDouble_Set2.insert(3.4);
    myUnOrderedDouble_Set2.insert(4.5);
    cout << "myUnOrderedDouble_Set2 now has following items: " << endl;
    for (auto item = myUnOrderedDouble_Set2.begin(); item != myUnOrderedDouble_Set2.end(); item++) {
        cout << *item << endl;
    }

    // emplace(); construct element directly into unordered_set
    // STL: Inserts a new element into the container constructed in-place with the given args if there is no element with the key in the 
    // container.
    // Careful use of emplace allows the new element to be constructed while avoiding unnecessary copy or move operations. The constructor 
    // of the new element is called with exactly the same arguments as supplied to emplace, forwarded via std::forward<Args>(args).... 
    // The element may be constructed even if there already is an element with the key in the container, in which case the newly constructed 
    // element will be destroyed immediately.
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    myUnOrderedString_Set3.emplace("newStr1");
    myUnOrderedString_Set3.emplace("Str2new");
    myUnOrderedString_Set3.emplace("newStr3new");
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;

    // emplace_hint(), give additional hint to add new element into unordered_set, but not guarantee
    // STL: Inserts a new element to the container, using hint as a suggestion where the element should go. The element is constructed in-place, 
    // i.e. no copy or move operations are performed.
    // The constructor of the element is called with exactly the same arguments as supplied to the function, forwarded with std::forward<Args>(args)....
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    myUnOrderedString_Set3.emplace_hint(myUnOrderedString_Set3.begin(), "str4Hint");
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;
    myUnOrderedString_Set3.emplace_hint(myUnOrderedString_Set3.end(), "str5Hint");
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;

    // erase(), remove a specific element from unordered_set
    // STL: Removes specified elements from the container.
    // 1) Removes the element at pos. Only one overload is provided if iterator and const_iterator are the same type.
    // 2) Removes the elements in the range [first; last), which must be a valid range in *this.
    // 3) Removes the element (if one exists) with the key equivalent to key.
    // 4) Removes the element (if one exists) with key that compares equivalent to the value x. This overload participates in overload 
    // resolution only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type, and neither iterator nor 
    // const_iterator is implicitly convertible from K. This assumes that such Hash is callable with both K and Key type, and that the 
    // KeyEqual is transparent, which, together, allows calling this function without constructing an instance of Key.
    // References and iterators to the erased elements are invalidated. Other iterators and references are not invalidated.
    // The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferenceable) cannot be 
    // used as a value for pos.
    // The order of the elements that are not erased is preserved. (This makes it possible to erase individual elements while iterating 
    // through the container.)
    int return1 = myUnOrderedString_Set3.erase("str6");
    if (return1 == 0) {
        cout << "No element is removed" << endl;
    } else {
        cout << "str6 is removed" << endl;
    }
    int return2 = myUnOrderedString_Set3.erase("str5Hint");
    if (return2 == 0) {
        cout << "No element is removed" << endl;
    } else {
        cout << "str5Hint is removed" << endl;
    }

    // swap(), swap two unordered_set with same type
    // STL: Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual 
    // elements.
    // All iterators and references remain valid. The past-the-end iterator is invalidated.
    // The Hash and KeyEqual objects must be Swappable, and they are exchanged using unqualified calls to non-member swap.
    // If std::allocator_traits<allocator_type>::propagate_on_container_swap::value is true, then the allocators are exchanged using an 
    // unqualified call to non-member swap. Otherwise, they are not swapped (and if get_allocator() != other.get_allocator(), the behavior 
    // is undefined).(since C++11)
    cout << "swap myUnOrderedString_Set3 and myUnOrderedString_Set4" << endl;
    unordered_set<string> myUnOrderedString_Set4;
    cout << "Before: " << endl;
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;
    for_each(myUnOrderedString_Set4.begin(), myUnOrderedString_Set4.end(), printMySetStr);
    cout << endl;
    myUnOrderedString_Set3.swap(myUnOrderedString_Set4);
    cout << "After: " << endl;
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;
    for_each(myUnOrderedString_Set4.begin(), myUnOrderedString_Set4.end(), printMySetStr);
    cout << endl;
    myUnOrderedString_Set3 = myUnOrderedString_Set4;

    // extract(), in general, for set or unordered_set, the given key itself is also a value
    // change key in set or unordered_set is not usual, but this is a way.
    // Note that when it is being added back, still need to call "insert()" and with "move()" to update that element (key/value) 
    // accordingly
    // STL: 1) Unlinks the node that contains the element pointed to by position and returns a node handle that owns it.
    // 2) If the container has an element with key equivalent to k, unlinks the node that contains that element from the container and 
    // returns a node handle that owns it. Otherwise, returns an empty node handle.
    // 3) Same as (2). This overload participates in overload resolution only if Hash::is_transparent and KeyEqual::is_transparent are 
    // valid and each denotes a type, and neither iterator nor const_iterator is implicitly convertible from K. This assumes that such 
    // Hash is callable with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function 
    // without constructing an instance of Key.
    // In either case, no elements are copied or moved, only the internal pointers of the container nodes are repointed .
    // Extracting a node invalidates only the iterators to the extracted element, and preserves the relative order of the elements that 
    // are not erased. Pointers and references to the extracted element remain valid, but cannot be used while element is owned by a node 
    // handle: they become usable if the element is inserted into a container.
    cout << "After changing str4Hint to str4HintNew" << endl;
    auto item = myUnOrderedString_Set3.extract("str4Hint");
    item.value() = "str4HintNew";
    myUnOrderedString_Set3.insert(move(item));
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;

    // merge(), merge elements from ont to another, as this is unordered_Set, not unordered_multiset, if there are duplicated one,
    // it will leave in original unordered_set
    // STL: Attempts to extract ("splice") each element in source and insert it into *this using the hash function and key equality 
    // predicate of *this. If there is an element in *this with key equivalent to the key of an element from source, then that element 
    // is not extracted from source. No elements are copied or moved, only the internal pointers of the container nodes are repointed. 
    // All pointers and references to the transferred elements remain valid, but now refer into *this, not into source. Iterators referring 
    // to the transferred elements and all iterators referring to *this are invalidated. Iterators to elements remaining in source remain 
    // valid.
    // The behavior is undefined if get_allocator() != source.get_allocator().
    cout << "Before merge, myUnOrderedString_Set4" << endl;
    for_each(myUnOrderedString_Set4.begin(), myUnOrderedString_Set4.end(), printMySetStr);
    cout << endl;
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;
    cout << "Merge myUnOrderedString_Set3 to myUnOrderedString_Set4, it should have str4HintNew" << endl;
    myUnOrderedString_Set4.merge(myUnOrderedString_Set3);
    for_each(myUnOrderedString_Set4.begin(), myUnOrderedString_Set4.end(), printMySetStr);
    cout << endl;
    cout << "myUnOrderedString_Set3 should miss only one str4HintNew" << endl;
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;

    // count(), return number of specific element in unordered_set, this should be either 0 or 1 here
    // as unordered_set can only hold one element, no duplicated one
    // STL: 1) Returns the number of elements with key that compares equal to the specified argument key, which is either 1 or 0 
    // since this container does not allow duplicates.
    // 2) Returns the number of elements with key that compares equivalent to the specified argument x. This overload participates 
    // in overload resolution only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes 
    // that such Hash is callable with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling 
    // this function without constructing an instance of Key.
    cout << "Count() of newStr3new returns " << myUnOrderedString_Set3.count("newStr3new") << endl;
    cout << "Count() of xyz returns " << myUnOrderedString_Set3.count("xyz") << endl;

    // find(), look up one specific element, and return iterator. If not found, it will be same as end() iterator
    // STL: 1,2) Finds an element with key equivalent to key.
    // 3,4) Finds an element with key that compares equivalent to the value x. This overload participates in overload resolution only 
    // if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash is callable 
    // with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without constructing 
    // an instance of Key.
    auto item2 = myUnOrderedString_Set3.find("newStr3new");
    if (item2 == myUnOrderedString_Set3.end()) {
        cout << "Cannot find newStr3new" << endl;
    } else {
        cout << "Find newStr3new" << endl;
    }

    // contains(), similar to find(), but this one will return boolean
    // STL: 1) Checks if there is an element with key equivalent to key in the container.
    // 2) Checks if there is an element with key that compares equivalent to the value x. This overload participates in overload resolution 
    // only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash is callable 
    // with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without constructing an 
    // instance of Key.
    // This function is supported only if C++ 20 or after



    // equal_range(), return a pair of two iterators, first one pointed to the iterator that pointed to the first element of key, second
    // one pointed to the iterator that is right after the key
    // STL: 1,2) Returns a range containing all elements with key key in the container. The range is defined by two iterators, the first 
    // pointing to the first element of the wanted range and the second pointing past the last element of the range.
    // 3,4) Returns a range containing all elements in the container with key equivalent to x. This overload participates in overload 
    // resolution only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash 
    // is callable with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without 
    // constructing an instance of Key.



    // bucket_count()/max_bucket_count()/bucket_size(), return number of buckets in the current unordered_set
    // Note that bucket_size() will need to pvovide a bucket index value
    // STL: Returns the number of buckets in the container.
    // STL: Returns the maximum number of buckets the container is able to hold due to system or library implementation limitations.
    // STL: Returns the number of elements in the bucket with index n.
    cout << "bucket_count() is " << myUnOrderedString_Set4.bucket_count() << endl; 
    cout << "max_bucket_count() is " << myUnOrderedString_Set4.max_bucket_count() << endl;
    cout << "bucket_size(0) is " << myUnOrderedString_Set4.bucket_size(0) << endl;

    // load_factor()/max_load_factor(), return the factor info of container
    // STL: Returns the average number of elements per bucket, that is, size() divided by bucket_count().
    // STL Manages the maximum load factor (number of elements per bucket). The container automatically increases the number of buckets 
    // if the load factor exceeds this threshold.
    // 1) Returns current maximum load factor.
    // 2) Sets the maximum load factor to ml.
    cout << "load_factor() is " << myUnOrderedString_Set4.load_factor() << endl;
    cout << "max_load_factor() is " << myUnOrderedString_Set4.max_load_factor() << endl;

    // rehash(), re-generate hash table based on given specified number
    // STL: Sets the number of buckets to count and rehashes the container, i.e. puts the elements into appropriate buckets considering 
    // that total number of buckets has changed. If the new number of buckets makes load factor more than maximum load factor 
    // (count < size() / max_load_factor()), then the new number of buckets is at least size() / max_load_factor().
    cout << "bucket_count() is " << myUnOrderedString_Set3.bucket_count() << endl; 
    cout << "bucket_size(0) is " << myUnOrderedString_Set3.bucket_size(0) << endl;
    myUnOrderedString_Set3.rehash(10);
    cout << "bucket_count() is " << myUnOrderedString_Set3.bucket_count() << endl; 
    cout << "bucket_size(0) is " << myUnOrderedString_Set3.bucket_size(0) << endl;

    // reserve(), reserve specific buckets based on given number
    // STL: Sets the number of buckets to the number needed to accomodate at least count elements without exceeding maximum load factor 
    // and rehashes the container, i.e. puts the elements into appropriate buckets considering that total number of buckets has changed. 
    // Effectively calls rehash(std::ceil(count / max_load_factor())).
    myUnOrderedString_Set4.reserve(1000);
    cout << "bucket_count() is " << myUnOrderedString_Set4.bucket_count() << endl; 
    cout << "bucket_size(0) is " << myUnOrderedString_Set4.bucket_size(0) << endl;

    // hash_function(), return the hash function used in this container
    // STL: Returns the function that hashes the keys.



    // key_eq()
    // STL: Returns the function that compares keys for equality.



    // operator==,!=(std::unordered_set)
    // STL: Compares the contents of two unordered containers.
    // The contents of two unordered containers lhs and rhs are equal if the following conditions hold:
    // lhs.size() == rhs.size()
    // each group of equivalent elements [lhs_eq1, lhs_eq2) obtained from lhs.equal_range(lhs_eq1) has a corresponding group of equivalent 
    // elements in the other container [rhs_eq1, rhs_eq2) obtained from rhs.equal_range(rhs_eq1), that has the following properties:
    // std::distance(lhs_eq1, lhs_eq2) == std::distance(rhs_eq1, rhs_eq2).
    // std::is_permutation(lhs_eq1, lhs_eq2, rhs_eq1) == true.
    // The behavior is undefined if Key is not EqualityComparable.
    // The behavior is also undefined if hash_function() and key_eq() do (until C++20)key_eq() does (since C++20) not have the same behavior 
    // on lhs and rhs or if operator== for Key is not a refinement of the partition into equivalent-key groups introduced by key_eq() (that is,
    // if two elements that compare equal using operator== fall into different partitions)
    // The != operator is synthesized from operator==.(since C++20)



    // std::swap(), swap content in two container, same data type is required
    // STL: Specializes the std::swap algorithm for std::unordered_set. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
    std::unordered_set<int> alice{1, 2, 3};
    std::unordered_set<int> bob{7, 8, 9, 10};
    auto print = [](const int& n) { std::cout << ' ' << n; };
 
    // Print state before swap
    std::cout << "alice:";
    std::for_each(alice.begin(), alice.end(), print);
    std::cout << "\n" "bob  :";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << '\n';
    std::cout << "-- SWAP\n";
    std::swap(alice, bob);

    // Print state after swap
    std::cout << "alice:";
    std::for_each(alice.begin(), alice.end(), print);
    std::cout << "\n" "bob  :";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << '\n';

    // erase_if(), remove the specific element if condition matched
    // STL: Erases all elements that satisfy the predicate pred from the container. Equivalent to
    // auto old_size = c.size();
    // for (auto i = c.begin(), last = c.end(); i != last; ) {
    //  if (pred(*i)) {
    //    i = c.erase(i);
    //  } else {
    //    ++i;
    //  }
    // }
    // return old_size - c.size();

    // std::unordered_set data { 3, 3, 4, 5, 5, 6, 6, 7, 2, 1, 0 };
    // std::cout << "Original:\n" << data << '\n';
    // auto divisible_by_3 = [](auto const& x) { return (x % 3) == 0; };
    //
    // const auto count = std::erase_if(data, divisible_by_3);
    //
    // std::cout << "Erase all items divisible by 3:\n" << data << '\n'
    //           << count << " items erased.\n";


    return 0;
}
