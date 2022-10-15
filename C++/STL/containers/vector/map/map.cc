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
void myMapPrint(std::pair<string, int> element) {
    cout << element.first << " " << element.second << endl;
}
void myMapPrint2(std::pair<char, double> element) {
    cout << element.first << " " << element.second << endl;
}
void myMapPrint3(std::pair<string, double> element) {
    cout << element.first << " " << element.second << endl;
}

// main
int main() {

    // constructor, initialized at the beginning or by std::makr_pair()
    map<string, int> myMap1 = {{"Book", 4}, {"Desktop", 3}, {"Laptop", 1}, {"Table", 2}};
    map<string, int> myMap2 = {{"Breakfast", 1}, {"Lunch", 2}, {"Dinner", 3}};

    // insert after constructor
    map<string, double> myMap3;
    myMap3.insert(std::make_pair("Student1", 99.9));
    myMap3.insert(std::make_pair("Student2", 65.4));
    myMap3.insert(std::make_pair("Student3", 35.7));
    map<string, double> myMap6;

    // copy constructor
    map<string, double> myMap4 = myMap3;

    // character constructor
    map<char, double> myMap5 = {{'A', 0.1}, {'C', 0.3}, {'E', 0.5}};

    // at(), return an element with range check
    // STL: Returns a reference to the mapped value of the element with key equivalent to key. 
    // If no such element exists, an exception of type std::out_of_range is thrown.
    auto item1 = myMap1.at("Book");
    cout << "The number of Book by at() is " << item1 << endl;

    // operator[], access element by operator like array, but there is no range check
    // STL: Returns a reference to the value that is mapped to a key equivalent to key, performing an insertion if such key does not already exist.
    auto item2 = myMap1["Book"];
    cout << "The number of Book by operator is " << item2 << endl;

    // operator[] has another feature that will insert new element by this operator way
    // as there is no value specified, the default value will be 0 assigned to "Bag"
    auto item3 = myMap1["Bag"];
    cout << "The size of myMap1 now after Bag is " << myMap1.size() << endl;
    for_each(myMap1.begin(), myMap1.end(), myMapPrint);

    // what if we add another not existed one? This will be OK as "key" of map is different, even the default value is 0
    // the sorting of map is based on given key, so if all values are 0 in this map, this is like a set, except map will do the sorting
    // automatically based on key, while set will not do it
    // Output:
    // Bag 0
    // Book 4
    // Desktop 3
    // Laptop 1
    // Table 2
    // Watch 0
    auto item4 = myMap1["Watch"];
    cout << "The size of myMap1 now after Watch is " << myMap1.size() << endl;
    for_each(myMap1.begin(), myMap1.end(), myMapPrint);

    // begin()/end()/cbegin()/cend(), iterator, in general in map, we will NOT modify key as it will cause unnecessary re-sorting
    // so we can use cbegin()/cend() most of time
    cout << "Items inside myMap2 are:" << endl;
    for (auto item5 = myMap2.cbegin(); item5 !=myMap2.end(); item5++) {
        cout << "  " << item5->first << " " << item5->second << endl;
    }

    // empty(), check if the given map is empty or not, use std::boolalpha/std::noboolalpha to change 0/1 to false/true
    // STL: Checks if the container has no elements, i.e. whether begin() == end()
    cout << "myMap3 is empty? " << std::boolalpha << myMap3.empty() << endl;
    cout << "myMap3 is empty? " << std::noboolalpha << myMap3.empty() << endl;

    // size()/max_size(), return current size of map (number of elements), or max size that this OS can handle
    // STL: Returns the number of elements in the container, i.e. std::distance(begin(), end())
    // STL: Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, 
    // i.e. std::distance(begin(), end()) for the largest container.
    cout << "myMap4 size is " << myMap4.size() << endl;
    cout << "myMap4 max size is " << myMap4.max_size() << endl;

    // clear(), erase all elements in the map
    // STL: Erases all elements from the container. After this call, size() returns zero. Invalidates any references, pointers, 
    // or iterators referring to contained elements. Any past-the-end iterator remains valid.
    cout << "myMap4 size now is " << myMap4.size() << " before clear() call" << endl;
    myMap4.clear();
    cout << "myMap4 size now is " << myMap4.size() << " after clear() call" << endl;

    // insert(), insert a new element into map, based on its pair of (key, value)
    // STL: Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
    // 1-3) Inserts value. The overload (2) is equivalent to emplace(std::forward<P>(value)) and only participates in overload resolution 
    // if std::is_constructible<value_type, P&&>::value == true.
    // 4-6) Inserts value in the position as close as possible, just prior(since C++11), to hint. The overload (5) is equivalent to 
    // emplace_hint(hint, std::forward<P>(value)) and only participates in overload resolution if std::is_constructible<value_type, P&&>::value == true.
    // 7) Inserts elements from range [first, last). If multiple elements in the range have keys that compare equivalent, it is unspecified 
    // which element is inserted (pending LWG2844).
    // 8) Inserts elements from initializer list ilist. If multiple elements in the range have keys that compare equivalent, it is unspecified 
    // which element is inserted (pending LWG2844).
    // 9) If nh is an empty node handle, does nothing. Otherwise, inserts the element owned by nh into the container , if the container 
    // doesn't already contain an element with a key equivalent to nh.key(). The behavior is undefined if nh is not empty and 
    // get_allocator() != nh.get_allocator().
    // 10) If nh is an empty node handle, does nothing and returns the end iterator. Otherwise, inserts the element owned by nh into the container, 
    // if the container doesn't already contain an element with a key equivalent to nh.key(), and returns the iterator pointing to the element 
    // with key equivalent to nh.key() (regardless of whether the insert succeeded or failed). If the insertion succeeds, nh is moved from, 
    // otherwise it retains ownership of the element. The element is inserted as close as possible to the position just prior to hint. 
    // The behavior is undefined if nh is not empty and get_allocator() != nh.get_allocator().
    // No iterators or references are invalidated. If the insertion is successful, pointers and references to the element obtained while it is held 
    // in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid. (since C++17)
    cout << "myMap5 size is " << myMap5.size() << endl;

    // insert pair directly by adding {} and corresponding key with '' or "", and value, into the map 
    myMap5.insert({'B', 0.2});
    cout << "myMap5 size now is " << myMap5.size() << endl;

    // insert with std::make_pair() into map
    myMap5.insert(std::make_pair('D', 0.4));
    cout << "myMap5 size now is " << myMap5.size() << endl;

    // insert with std::pair() into map, note that by using std::pair, it needed additional definition <char, double> there
    // while std::make_pair didn't need it
    myMap5.insert(std::pair<char, double>{'F', 0.6});
    cout << "myMap5 size now is " << myMap5.size() << endl;

    cout << "All elements in the myMap5 are" << endl;
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);

    // insert_or_assign(), insert this new (key, value) or just update the value of same key
    // STL: 1,3) If a key equivalent to k already exists in the container, assigns std::forward<M>(obj) to the mapped_type corresponding 
    // to the key k. If the key does not exist, inserts the new value as if by insert, constructing it from value_type(k, std::forward<M>(obj))
    // 2,4) Same as (1,3), except the mapped value is constructed from value_type(std::move(k), std::forward<M>(obj))
    // The behavior is undefined (until C++20). The program is ill-formed (since C++20) if std::is_assignable_v<mapped_type&, M&&> is false.
    // No iterators or references are invalidated.
    myMap5.insert_or_assign('A', 0.6);
    myMap5.insert_or_assign('B', 0.5);
    myMap5.insert_or_assign('C', 0.4);
    myMap5.insert_or_assign('D', 0.3);
    myMap5.insert_or_assign('E', 0.2);
    myMap5.insert_or_assign('F', 0.1);
    cout << "All elements in the myMap5 after insert_or_assign() update are" << endl;
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);

    // emplace(), like insert() but it will construct the element with faster runtime
    // STL: Inserts a new element into the container constructed in-place with the given args if there is no element with the key in the container.
    // Careful use of emplace allows the new element to be constructed while avoiding unnecessary copy or move operations. The constructor of the 
    // new element (i.e. std::pair<const Key, T>) is called with exactly the same arguments as supplied to emplace, forwarded via 
    // std::forward<Args>(args).... The element may be constructed even if there already is an element with the key in the container, in which case 
    // the newly constructed element will be destroyed immediately.
    // No iterators or references are invalidated.
    myMap5.clear();
    myMap5.emplace('A', 0.001);
    myMap5.emplace('B', 0.010);
    myMap5.emplace('C', 0.100);
    cout << "New elements in the myMap5 are" << endl;
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);

    // emplace_hint(), similar to emplace(), but by giving a hint to insert the new element at a location, however, it doesn't guarantee that the 
    // new inserted element will be really there, just be as close as possible
    // STL: Inserts a new element to the container as close as possible to the position just before hint. The element is constructed in-place, i.e. 
    // no copy or move operations are performed.
    // The constructor of the element type (value_type, that is, std::pair<const Key, T>) is called with exactly the same arguments as supplied to 
    // the function, forwarded with std::forward<Args>(args)....
    // No iterators or references are invalidated.
    cout << "New element \"Z\" in the myMap5 has hint to location 0" << endl;
    myMap5.emplace_hint(myMap5.begin(), 10000, 'Z');
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);

    // try_emplace(), a new API that combines emplace() or emplace_hint(), if the given key doesn't exist, inert this new key, otherwise, nothing
    // STL: Inserts a new element into the container with key k and value constructed with args, if there is no element with the key in the container.
    // 1) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace except that the element is 
    // constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(k),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // 2) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace except that the element is constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(std::move(k)),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // 3) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace_hint except that the element is constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(k),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // 4) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace_hint except that the element is constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(std::move(k)),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // No iterators or references are invalidated.
    cout << "Changes of original A, B, C should remain same by calling try_emplace()" << endl;
    myMap5.try_emplace('A', 111.111);
    myMap5.try_emplace('B', 222.222);
    myMap5.try_emplace('C', 333.333);
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);
    cout << "Changes of new X, Y, Z should be inserted by calling try_emplace()" << endl;
    myMap5.try_emplace('Z', 444.444);
    myMap5.try_emplace('Y', 555.555);
    myMap5.try_emplace('X', 666.666);
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);

    // erase(), delete one specific element in map
    // STL: Removes specified elements from the container.
    // 1) Removes the element at pos.
    // 2) Removes the elements in the range [first; last), which must be a valid range in *this.
    // 3) Removes the element (if one exists) with the key equivalent to key.
    // 4) Removes the element (if one exists) with key that compares equivalent to the value x. This overload participates in overload resolution 
    // only if the qualified-id Compare::is_transparent is valid and denotes a type, and neither iterator nor const_iterator is implicitly convertible 
    // from K. It allows calling this function without constructing an instance of Key.
    // References and iterators to the erased elements are invalidated. Other references and iterators are not affected.
    // The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferenceable) cannot be used as a value for pos.
    myMap5.erase('A');
    myMap5.erase('B');
    myMap5.erase('C');
    myMap5.erase('D');
    myMap5.erase('Z');
    cout << "After calling erase() to remove specific elements" << endl; 
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);
    myMap5.clear();

    // swap(), swap elements from one map to another map
    // STL: Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
    // All iterators and references remain valid. The past-the-end iterator is invalidated.
    // The Compare objects must be Swappable, and they are exchanged using unqualified call to non-member swap.
    // If std::allocator_traits<allocator_type>::propagate_on_container_swap::value is true, then the allocators are exchanged using an unqualified 
    // call to non-member swap. Otherwise, they are not swapped (and if get_allocator() != other.get_allocator(), the behavior is undefined). (since C++11)
    cout << "myMap3 before swap()" << endl; 
    for_each(myMap3.begin(), myMap3.end(), myMapPrint3);
    cout << "myMap6 before swap()" << endl; 
    for_each(myMap6.begin(), myMap6.end(), myMapPrint3);
    myMap3.swap(myMap6);
    cout << "myMap3 after swap()" << endl; 
    for_each(myMap3.begin(), myMap3.end(), myMapPrint3);
    cout << "myMap6 after swap()" << endl; 
    for_each(myMap6.begin(), myMap6.end(), myMapPrint3);

    // extract(), get one element by specifying key, and by using key(), that allows us to change key in the map, not usual usage
    // Also, it needed to be inserted again back to map with std::move() call
    // STL: 1) Unlinks the node that contains the element pointed to by position and returns a node handle that owns it.
    // 2) If the container has an element with key equivalent to k, unlinks the node that contains that element from the container and returns a node 
    // handle that owns it. Otherwise, returns an empty node handle.
    // 3) Same as (2). This overload participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type, 
    // and neither iterator nor const_iterator is implicitly convertible from K. It allows calling this function without constructing an instance of Key.
    // In either case, no elements are copied or moved, only the internal pointers of the container nodes are repointed (rebalancing may occur, as with 
    // erase()).
    // Extracting a node invalidates only the iterators to the extracted element. Pointers and references to the extracted element remain valid, but 
    // cannot be used while element is owned by a node handle: they become usable if the element is inserted into a container.
    auto test1 = myMap6.extract("Student1");
    test1.key() = "Student4";
    myMap6.insert(std::move(test1));
    cout << "myMap6 after changing Student1 to Student4" << endl; 
    for_each(myMap6.begin(), myMap6.end(), myMapPrint3);

    // merge(), merge to maps into one, as map can only allow one key, when it already has the key, the later value will be ignored
    // STL: Attempts to extract ("splice") each element in source and insert it into *this using the comparison object of *this. If there is an element 
    // in *this with key equivalent to the key of an element from source, then that element is not extracted from source. No elements are copied or moved, 
    // only the internal pointers of the container nodes are repointed. All pointers and references to the transferred elements remain valid, but now 
    // refer into *this, not into source.
    // The behavior is undefined if get_allocator() != source.get_allocator().
    std::map<int, std::string> ma {{1, "apple"}, {5, "pear"}, {10, "banana"}};
    std::map<int, std::string> mb {{2, "zorro"}, {4, "batman"}, {5, "X"}, {8, "alpaca"}};
    for (auto el = ma.begin(); el != ma.end(); el++) {
        cout << el->first << " " << el->second << endl;
    }
    for (auto el = mb.begin(); el != mb.end(); el++) {
        cout << el->first << " " << el->second << endl;
    }
    ma.merge(mb);
    cout << "After merge to ma" << endl;
    for (auto &el : ma) {
        cout << el.first << " " << el.second << endl;
    }
    cout << "Elements left in mb due to same key 5" << endl;
    for (auto &el : mb) {
        cout << el.first << " " << el.second << endl;
    }

    // count(), return number of elements of given key. For map, it should be either 0 or 1 as map doesn't allow duplicated ones
    // STL: Returns the number of elements with key that compares equivalent to the specified argument, which is either 1 or 0 since this container 
    // does not allow duplicates.
    // 1) Returns the number of elements with key key.
    // 2) Returns the number of elements with key that compares equivalent to the value x. This overload participates in overload resolution 
    // only if the qualified-id Compare::is_transparent 
    // is valid and denotes a type. They allow calling this function without constructing an instance of Key.
    cout << "How many elements of key 1 in ma? " << ma.count(1) << endl;

    // find(), find the given element by key
    // STL: 1,2) Finds an element with key equivalent to key.
    // 3,4) Finds an element with key that compares equivalent to the value x. This overload participates in overload resolution only if the qualified-id 
    // Compare::is_transparent is valid and denotes a type. It allows calling this function without constructing an instance of Key.
    auto left_element = mb.find(5);
    cout << "The last element left in mb is " << left_element->first << " " << left_element->second << endl;

    // contains(), check if the given key existed in the map, note that this is supported from C++ 20
    // STL: 1) Checks if there is an element with key equivalent to key in the container.
    // 2) Checks if there is an element with key that compares equivalent to the value x. This overload participates in overload resolution only if the 
    // qualified-id Compare::is_transparent is valid and denotes a type. It allows calling this function without constructing an instance of Key.
    // cout << "Is key 5 existed in the mb? " << std::boolalpha << mb.contains(5) << endl; 

    // equal_range(), return two iterators, first is not less than the key, second is the first one that is greater than the key, so the first and second
    // may be the same one
    // STL: Returns a range containing all elements with the given key in the container. The range is defined by two iterators, one pointing to the first 
    // element that is not less than key and another pointing to the first element greater than key. Alternatively, the first iterator may be obtained 
    // with lower_bound(), and the second with upper_bound().
    // 1,2) Compares the keys to key.
    // 3,4) Compares the keys to the value x. This overload participates in overload resolution only if the qualified-id Compare::is_transparent is valid 
    // and denotes a type. It allows calling this function without constructing an instance of Key. This section is incomplete Reason: explain better
    cout << "Elements in ma are:" << endl;
    for (auto &el : ma) {
        cout << " " << el.first << " " << el.second << endl;
    }
    auto range_elements = ma.equal_range(6);
    cout << "The equal range of ma for number 6 is " << range_elements.first->first << " and " << range_elements.second->first << endl;
    range_elements = ma.equal_range(4);
    cout << "The equal range of ma for number 4 is " << range_elements.first->first << " and " << range_elements.second->first << endl;
    range_elements = ma.equal_range(8);
    cout << "The equal range of ma for number 8 is " << range_elements.first->first << " and " << range_elements.second->first << endl;

    // lower_bound()/upper_bound(), return the iterator that is first iterator not less than the given key, or greater than the given key
    auto bound_element = ma.lower_bound(4);
    cout << "The lower_bound of ma for number 4 is " << bound_element->first << " and " << bound_element->second << endl;
    bound_element = ma.upper_bound(4);
    cout << "The upper_bound of ma for number 4 is " << bound_element->first << " and " << bound_element->second << endl;

    // key_comp(), compare function for map, if we want to customize the comparison function
    // STL: Returns the function object that compares the keys, which is a copy of this container's constructor argument comp.
    // Below code examlpe is from https://en.cppreference.com/w/cpp/container/map/key_comp
    struct ModCmp {
        bool operator()(const int lhs, const int rhs) const
        {
            return (lhs % 97) < (rhs % 97);
        }
    };
    std::map<int, char, ModCmp> cont = {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    auto comp_func = cont.key_comp();
    cout << "key_comp() operation:" << endl;
    for (auto it = cont.begin(); it != cont.end(); it++) {
        bool before = comp_func(it->first, 100);
        cout << boolalpha << it->first << " " << it->second << " " << before << endl;
        bool after = comp_func(100, it->first);
        cout << boolalpha << it->first << " " << it->second << " " << after << endl;
    }
    
    // value_comp(), compare function for map, if we want to customize the comparsion function
    // STL: Returns a function object that compares objects of type std::map::value_type (key-value pairs) by using key_comp to 
    // compare the first components of the pairs.
    auto comp_value_func = cont.value_comp();
    const std::pair<int, char> val = { 100, 'a' };
    cout << "value_comp() operation:" << endl;
    for (auto it : cont) {
        bool before = comp_value_func(it, val);
        cout << boolalpha << it.first << " " << it.second << " " << before << endl;
        bool after = comp_value_func(val, it);
        cout << boolalpha << it.first << " " << it.second << " " << after << endl;
    }

    // std::swap(), swap whole map from one to another
    // STL: Specializes the std::swap algorithm for std::map. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
    std::map<int, char> alice{{1, 'a'}, {2, 'b'}, {3, 'c'}};
    std::map<int, char> bob{{7, 'Z'}, {8, 'Y'}, {9, 'X'}, {10, 'W'}};
    auto print = [](std::pair<const int, char>& n) { 
        std::cout << " " << n.first << '(' << n.second << ')'; 
    };
    std::for_each(alice.begin(), alice.end(), print);
    cout << endl;
    std::for_each(bob.begin(), bob.end(), print);
    cout << endl;
    std::cout << "-- SWAP --\n";
    std::swap(alice, bob);
    std::for_each(alice.begin(), alice.end(), print);
    cout << endl;
    std::for_each(bob.begin(), bob.end(), print);
    cout << endl;

    // erase_if(), erase element if the condition matched
    // STL: Erases all elements that satisfy the predicate pred from the container. Equivalent to
    // auto old_size = c.size();
    // for (auto i = c.begin(), last = c.end(); i != last; ) {
    //   if (pred(*i)) {
    //     i = c.erase(i);
    //   } else {
    //     ++i;
    //   }
    // }
    // return old_size - c.size();
    // std::map<int, char> data {{1, 'a'},{2, 'b'},{3, 'c'},{4, 'd'},
    //                          {5, 'e'},{4, 'f'},{5, 'g'},{5, 'g'}};
    // const auto count = std::erase_if(data, [](const auto& item) {
    //   auto const& [key, value] = item;
    //   return (key & 1) == 1;
    // });

    return 0;
}
