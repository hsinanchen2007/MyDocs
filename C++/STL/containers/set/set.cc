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
// Example module 97 key compare function
struct ModCmp {
    bool operator()(const int lhs, const int rhs) const
    {
        return (lhs % 97) < (rhs % 97);
    }
};

// main
int main() {
    // STL set, key is value and only unique key is allowed, key will be sorted automatically
    set<string> mySet1;
    set<string> mySet2;
    set<string> mySet3;

    // constructor, the input keys are with random order, but once it is built, key will be 
    // sorted automatically
    mySet1.insert("cat");
    mySet1.insert("dog");
    mySet1.insert("tiger");
    mySet1.insert("chicken");
    mySet1.insert("bird");
    mySet1.insert("elephant");
    mySet1.insert("flamingo");
    mySet1.insert("snake");

    // assign from one set to another set
    mySet2 = mySet1;

    // move from one set to another set
    mySet3 = std::move(mySet2);

    // from/begin way, but it needed to do it when it is first defined
    set<string> mySet4(mySet1.begin(), mySet1.end());

    // another way to define mySet5
    set<string> mySet5(mySet4);

    // iterator
    // note that in the for_each statement, the third parameter is "[](string a) {}", if it is 
    // not defined in seperate function
    cout << "mySet1 by for_each() way" << endl;
    for_each(mySet1.begin(), mySet1.end(), [] (string a) {
        cout << a << endl;
    });
    // like other containers, use for loop with ++ to iterate all elements
    cout << "All elements in all set for for loop way" << endl;
    cout << "mySet1" << endl;
    for (auto item=mySet1.begin(); item!=mySet1.end(); item++) {
        cout << *item << endl;
    }
    cout << "mySet2" << endl;
    for (auto item=mySet2.begin(); item!=mySet2.end(); item++) {
        cout << *item << endl;
    }
    cout << "mySet3" << endl;
    for (auto item=mySet3.begin(); item!=mySet3.end(); item++) {
        cout << *item << endl;
    }
    // get reference, which is true element in mySet4
    cout << "mySet4" << endl;
    for (auto &item : mySet4) {
        cout << item << endl;
    }
    cout << "mySet5" << endl;
    for (auto item : mySet5) {
        cout << item << endl;
    }

    // empty(), check if the given set is empty or not
    // STL: Checks if the container has no elements, i.e. whether begin() == end()
    cout << boolalpha;
    cout << "Is mySet5 empty? " << mySet5.empty() << endl;

    // size(), check how many elements in the set
    // STL: Returns the number of elements in the container, i.e. std::distance(begin(), end())
    cout << "How many elements in mySet4? " << mySet4.size() << endl;
    mySet4.clear();
    cout << "How many elements in mySet4 after clear() call? " << mySet4.size() << endl;

    // max_size(), return the max size that the current system can hold
    // STL: Returns the maximum number of elements the container is able to hold due to system or 
    // library implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
    cout << "Max size of the mySet1 in system " << mySet1.max_size() << endl;

    // clear(), erase all elements in the set
    // STL: Erases all elements from the container. After this call, size() returns zero.
    // Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end 
    // iterator remains valid.
    cout << "How many elements in mySet5? " << mySet5.size() << endl;
    mySet5.clear();
    cout << "How many elements in mySet5 after clear() call? " << mySet5.size() << endl;

    // insert(), add a new element into set
    // STL: Inserts element(s) into the container, if the container doesn't already contain an element with 
    // an equivalent key.
    // 1-2) inserts value.
    // 3-4) inserts value in the position as close as possible, just prior(since C++11), to hint.
    // 5) Inserts elements from range [first, last). If multiple elements in the range have keys that compare 
    // equivalent, it is unspecified which element is inserted (pending LWG2844).
    // 6) Inserts elements from initializer list ilist. If multiple elements in the range have keys that compare 
    // equivalent, it is unspecified which element is inserted (pending LWG2844).
    // 7) If nh is an empty node handle, does nothing. Otherwise, inserts the element owned by nh into the container 
    // , if the container doesn't already contain an element with a key equivalent to nh.key(). The behavior is 
    // undefined if nh is not empty and get_allocator() != nh.get_allocator().
    // 8) If nh is an empty node handle, does nothing and returns the end iterator. Otherwise, inserts the element 
    // owned by nh into the container, if the container doesn't already contain an element with a key equivalent to 
    // nh.key(), and returns the iterator pointing to the element with key equivalent to nh.key() (regardless of whether 
    // the insert succeeded or failed). If the insertion succeeds, nh is moved from, otherwise it retains ownership 
    // of the element. The element is inserted as close as possible to the position just prior to hint. The behavior 
    // is undefined if nh is not empty and get_allocator() != nh.get_allocator().
    // No iterators or references are invalidated. If the insertion is successful, pointers and references to the 
    // element obtained while it is held in the node handle are invalidated, and pointers and references obtained to 
    // that element before it was extracted become valid. (since C++17)
    mySet1.insert("xyz");
    cout << "After inserting xyz intio mySet1, this one should be added into last one if we iterate all elements" << endl;
    for_each(mySet1.begin(), mySet1.end(), [] (string a) {
        cout << a << endl;
    });

    // emplace(), construct a new element into set. This operation should be faster
    // STL: Inserts a new element into the container constructed in-place with the given args if there is no element 
    // with the key in the container.
    // Careful use of emplace allows the new element to be constructed while avoiding unnecessary copy or move operations. 
    // The constructor of the new element is called with exactly the same arguments as supplied to emplace, forwarded via 
    // std::forward<Args>(args).... The element may be constructed even if there already is an element with the key in the 
    // container, in which case the newly constructed element will be destroyed immediately.
    // No iterators or references are invalidated.
    mySet1.emplace("zyx");
    cout << "After inserting zyx intio mySet1, this one should be added into last one if we iterate all elements" << endl;
    for_each(mySet1.begin(), mySet1.end(), [] (string a) {
        cout << a << endl;
    });

    // emplace_hint(), by giving a hint to construct new element into set, however, it is still be sorted and added based on
    // the key, the hint is just a hint
    // STL: Inserts a new element into the container as close as possible to the position just before hint. The element 
    // is constructed in-place, i.e. no copy or move operations are performed.
    // The constructor of the element is called with exactly the same arguments as supplied to the function, forwarded 
    // with std::forward<Args>(args)....
    // No iterators or references are invalidated.
    mySet1.emplace_hint(mySet1.begin(), "zyx2");
    cout << "After inserting zyx2 intio mySet1 by hint, this one should be still added into last one if we iterate all elements" << endl;
    for_each(mySet1.begin(), mySet1.end(), [] (string a) {
        cout << a << endl;
    });

    // erase(), remove one specific element from set
    // STL: Removes specified elements from the container.
    // 1) Removes the element at pos. Only one overload is provided if iterator and const_iterator are the same type. 
    // (since C++11)
    // 2) Removes the elements in the range [first; last), which must be a valid range in *this.
    // 3) Removes the element (if one exists) with the key equivalent to key.
    // 4) Removes the element (if one exists) with key that compares equivalent to the value x. This overload participates 
    // in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type, and neither iterator 
    // nor const_iterator is implicitly convertible from K. It allows calling this function without constructing an instance of Key.
    // References and iterators to the erased elements are invalidated. Other references and iterators are not affected.
    // The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferenceable) 
    // cannot be used as a value for pos.
    mySet1.erase("xyz");
    mySet1.erase("zyx");
    mySet1.erase("zyx2");
    cout << "After removing all xyz elements, the updated mySet1" << endl;
    for_each(mySet1.begin(), mySet1.end(), [] (string a) {
        cout << a << endl;
    });    

    // erase elements based on begin/end iterators
    mySet5 = mySet1;
    mySet5.erase(mySet5.begin(), mySet5.end());
    cout << "After removing all elements, the updated mySet5" << endl;
    for_each(mySet5.begin(), mySet5.end(), [] (string a) {
        cout << a << endl;
    });

    // swap(), swap elements from one set to another set. Note that the swapped elements are from different sets, 
    // not within same set
    // STL: Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on 
    // individual elements.
    // All iterators and references remain valid. The past-the-end iterator is invalidated.
    // The Compare objects must be Swappable, and they are exchanged using unqualified call to non-member swap.
    // If std::allocator_traits<allocator_type>::propagate_on_container_swap::value is true, then the allocators are exchanged 
    // using an unqualified call to non-member swap. Otherwise, they are not swapped (and if get_allocator() != other.get_allocator(), 
    // the behavior is undefined). (since C++11)
    set<int> myIntSet1={1,3,5,7,9};
    set<int> myIntSet2={2,4,6,8,10};
    cout << "Before swap, myIntSet1" << endl;
    for_each(myIntSet1.begin(), myIntSet1.end(), [] (int a) {
        cout << a << endl;
    });
    cout << "Before swap, myIntSet2" << endl;
    for_each(myIntSet2.begin(), myIntSet2.end(), [] (int a) {
        cout << a << endl;
    });
    myIntSet2.swap(myIntSet1);
    cout << "After swap, myIntSet1" << endl;
    for_each(myIntSet1.begin(), myIntSet1.end(), [] (int a) {
        cout << a << endl;
    });
    cout << "After swap, myIntSet2" << endl;
    for_each(myIntSet2.begin(), myIntSet2.end(), [] (int a) {
        cout << a << endl;
    });
    myIntSet2.swap(myIntSet1);

    // extract(), get the key from set, and can change it accordingly. Note that the value() should be used
    // STL: 1) Unlinks the node that contains the element pointed to by position and returns a node handle that owns it.
    // 2) If the container has an element with key equivalent to k, unlinks the node that contains that element from the 
    // container and returns a node handle that owns it. Otherwise, returns an empty node handle.
    // 3) Same as (2). This overload participates in overload resolution only if the qualified-id Compare::is_transparent 
    // is valid and denotes a type, and neither iterator nor const_iterator is implicitly convertible from K. It allows 
    // calling this function without constructing an instance of Key.
    // In either case, no elements are copied or moved, only the internal pointers of the container nodes are repointed 
    // (rebalancing may occur, as with erase())
    // Extracting a node invalidates only the iterators to the extracted element. Pointers and references to the extracted 
    // element remain valid, but cannot be used while element is owned by a node handle: they become usable if the element 
    // is inserted into a container.  
    //
    // auto key=myIntSet2.extract(1);
    // key.value() = 2;

    // merge(), merge elements from one set to another set
    // STL: Attempts to extract ("splice") each element in source and insert it into *this using the comparison object of 
    // *this. If there is an element in *this with key equivalent to the key of an element from source, then that element 
    // is not extracted from source. No elements are copied or moved, only the internal pointers of the container nodes are 
    // repointed. All pointers and references to the transferred elements remain valid, but now refer into *this, not into 
    // source.
    // The behavior is undefined if get_allocator() != source.get_allocator().
    // 
    // myIntSet1.merge(myIntSet2);

    // count(), return number of elements of that specific key. In general, this should be either 0 or 1 as set only allows
    // one key
    // STL: Returns the number of elements with key that compares equivalent to the specified argument, which is either 1 or 0 
    // since this container does not allow duplicates.
    // 1) Returns the number of elements with key key.
    // 2) Returns the number of elements with key that compares equivalent to the value x. This overload participates in overload 
    // resolution only if the qualified-id Compare::is_transparent is valid and denotes a type. They allow calling this function 
    // without constructing an instance of Key.
    cout << "How many elements of dog from mySet1? " << mySet1.count("dog") << endl;
    cout << "How many elements of eagle from mySet1? " << mySet1.count("eagle") << endl;

    // find(), find one specific element from set, and we can check if the return is valud by using end() like other containers
    // STL: 1,2) Finds an element with key equivalent to key.
    // 3,4) Finds an element with key that compares equivalent to the value x. This overload participates in overload resolution 
    // only if the qualified-id Compare::is_transparent is valid and denotes a type. It allows calling this function without 
    // constructing an instance of Key.
    auto search=mySet1.find("cat");
    if (search != mySet1.end()) {
        cout << "Find the key cat " << *search << endl;
    } else {
        cout << "Do not find the key cat " << endl;
    }
    search=mySet1.find("eagle");
    if (search != mySet1.end()) {
        cout << "Find the key cat " << *search << endl;
    } else {
        cout << "Do not find the key eagle" << endl;
    }

    // contains(), check if the given element existed in the set
    // STL: 1) Checks if there is an element with key equivalent to key in the container.
    // 2) Checks if there is an element with key that compares equivalent to the value x. This overload participates in overload 
    // resolution only if the qualified-id Compare::is_transparent is valid and denotes a type. It allows calling this function 
    // without constructing an instance of Key.
    // search=mySet1.contains("dog");

    // equal_range(), return a pair of iterators like begin() and end() based on the specified range. The first iterator will be 
    // the one of lower range or the exact one specified in the given element
    // STL: Returns a range containing all elements with the given key in the container. The range is defined by two iterators, 
    // one pointing to the first element that is not less than key and another pointing to the first element greater than key. 
    // Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
    // 1,2) Compares the keys to key.
    // 3,4) Compares the keys to the value x. This overload participates in overload resolution only if the qualified-id 
    // Compare::is_transparent is valid and denotes a type. It allows calling this function without constructing an instance of Key.
    cout << "mySet1 by for_each() way" << endl;
    for_each(mySet1.begin(), mySet1.end(), [] (string a) {cout << a << endl;});
    cout << "Element dog is located at the range" << endl;
    auto [la, ub] = mySet1.equal_range("dog");
    cout << *la << endl;
    cout << *ub << endl;

    // when using a key which is not existed in the set, it will return one closest
    // for example, "eagle" is not there, so it returns "elephant" which is the only one starting from latter "e" in the set
    cout << "Element eagle is not located in the set" << endl;
    auto [laa, ubb] = mySet1.equal_range("eagle");
    cout << *laa << endl;
    cout << *ubb << endl;

    // lower_bound()/upper_bound(), get lower and upper bounds, here it returns only one, not a pair like equal_range()
    // STL: 1) Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
    // 2) Returns an iterator pointing to the first element that compares not less (i.e. greater or equal) to the value x. 
    // This overload participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes 
    // a type. It allows calling this function without constructing an instance of Key.
    auto lower = mySet1.lower_bound("dog");
    auto higher = mySet1.upper_bound("dog");
    cout << "Lower bound is " << *lower << " upper bound is " << *higher << endl;

    std::set<int, ModCmp> cont{1, 2, 3, 4, 5};

    // key_comp()/value_comp(), never use this one before, below code example is from https://en.cppreference.com/w/cpp/container/set/key_comp
    // STL: Returns the function object that compares the keys, which is a copy of this container's constructor argument comp. 
    // It is the same as value_comp.
    // STL: Returns the function object that compares the values. It is the same as key_comp.
    auto comp_func = cont.key_comp();
    for (int key : cont) {
        bool before = comp_func(key, 100);
        bool after = comp_func(100, key);
        if (!before && !after)
            std::cout << key << " equivalent to key 100\n";
        else if (before)
            std::cout << key << " goes before key 100\n";
        else if (after)
            std::cout << key << " goes after key 100\n";
        else
            std::cout << "Error\n";
    }

    // std::swap(), similar to swap(), and it swap the whole set
    // STL: Specializes the std::swap algorithm for std::set. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
    cout << "Before swap, myIntSet1" << endl;
    for_each(myIntSet1.begin(), myIntSet1.end(), [] (int a) {
        cout << a << endl;
    });
    cout << "Before swap, myIntSet2" << endl;
    for_each(myIntSet2.begin(), myIntSet2.end(), [] (int a) {
        cout << a << endl;
    });
    std::swap(myIntSet1, myIntSet2);
    cout << "After swap, myIntSet1" << endl;
    for_each(myIntSet1.begin(), myIntSet1.end(), [] (int a) {
        cout << a << endl;
    });
    cout << "After swap, myIntSet2" << endl;
    for_each(myIntSet2.begin(), myIntSet2.end(), [] (int a) {
        cout << a << endl;
    });

    // erase_if(), erase the elements if it matches the criteria
    // STL: Erases all elements that satisfy the predicate pred from the container. Equivalent to
    // auto divisible_by_3 = [](auto const& x) { return (x % 3) == 0; };
    // const auto count = std::erase_if(myIntSet2 divisible_by_3);



    return 0;
}
