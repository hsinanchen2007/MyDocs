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


// main
int main() {
    // STL unordered_map container study, a string to int map used like a hash table
    unordered_map<string, int> myStrToIntMap;

    myStrToIntMap.insert(std::make_pair("key0", 0));
    myStrToIntMap.insert(std::make_pair("key1", 1));
    myStrToIntMap.insert(std::make_pair("key2", 2));
    myStrToIntMap.insert(std::make_pair("key3", 3));
    myStrToIntMap.insert(std::make_pair("key4", 4));

    // begin()/end() iterators used in unordered_map container
    // STL: Returns an iterator to the first element of the unordered_map.
    // If the unordered_map is empty, the returned iterator will be equal to end().
    for (auto item = myStrToIntMap.begin(); item != myStrToIntMap.end(); item++) {
        cout << item->first << " " << item->second << endl;
    }
    for (auto item : myStrToIntMap) {
        cout << item.first << " " << item.second << endl;
    }
    for (auto &item : myStrToIntMap) {
        cout << item.first << " " << item.second << endl;
    }

    // Note above and below for loop difference, can't compile below
    // for (auto item : myStrToIntMap) {
    //     cout << item->first << " " << item->second << endl;
    // }

    // empty(), check if the container is empty or not
    // STL: Checks if the container has no elements, i.e. whether begin() == end().
    cout << boolalpha << "Is this container empty? " << myStrToIntMap.empty()? "yes" : "no";
    cout << endl;

    // size()/max_size(), check current number of elements in the container
    // STL: Returns the number of elements in the container, i.e. std::distance(begin(), end()).
    // STL: Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, 
    // i.e. std::distance(begin(), end()) for the largest container.
    cout << "size() of the container is " << myStrToIntMap.size() << endl;
    cout << "max_size() of the container is " << myStrToIntMap.max_size() << endl;

    // clear(), remove all elements in the container
    // STL: Erases all elements from the container. After this call, size() returns zero.
    // Invalidates any references, pointers, or iterators referring to contained elements. May also invalidate past-the-end iterators.
    unordered_map<string, int> myStrToIntMap2;
    myStrToIntMap2 = myStrToIntMap;
    cout << "size() of the container before clear() is " << myStrToIntMap.size() << endl;
    myStrToIntMap.clear();
    cout << "size() of the container after clear() is " << myStrToIntMap.size() << endl;
    myStrToIntMap = myStrToIntMap2;
    
    // insert(), add a new element into unordered_map container, note that it can only hold one unique pair (key, value)
    // STL: Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
    // 1-2) Inserts value. The overload (2) is equivalent to emplace(std::forward<P>(value)) and only participates in overload resolution 
    // if std::is_constructible<value_type, P&&>::value == true.
    // 3-4) Inserts value, using hint as a non-binding suggestion to where the search should start. The overload (4) is equivalent to 
    // emplace_hint(hint, std::forward<P>(value)) and only participates in overload resolution if std::is_constructible<value_type, P&&>::value 
    // == true.
    // 5) Inserts elements from range [first, last). If multiple elements in the range have keys that compare equivalent, it is unspecified 
    // which element is inserted (pending LWG2844).
    // 6) Inserts elements from initializer list ilist. If multiple elements in the range have keys that compare equivalent, it is unspecified 
    // which element is inserted (pending LWG2844).
    // 7) If nh is an empty node handle, does nothing. Otherwise, inserts the element owned by nh into the container , if the container 
    // doesn't already contain an element with a key equivalent to nh.key(). The behavior is undefined if nh is not empty and get_allocator() 
    // != nh.get_allocator().
    // 8) If nh is an empty node handle, does nothing and returns the end iterator. Otherwise, inserts the element owned by nh into the 
    // container, if the container doesn't already contain an element with a key equivalent to nh.key(), and returns the iterator pointing to 
    // the element with key equivalent to nh.key() (regardless of whether the insert succeeded or failed). If the insertion succeeds, nh is 
    // moved from, otherwise it retains ownership of the element. The element is inserted as close as possible to hint. The behavior is 
    // undefined if nh is not empty and get_allocator() != nh.get_allocator().
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count(). If the insertion 
    // is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and 
    // references obtained to that element before it was extracted become valid. (since C++17)
    myStrToIntMap.insert(std::make_pair("key99", 99));
    for (auto item : myStrToIntMap) {
        cout << item.first << " " << item.second << endl;
    }

    // insert_or_assign(), similar to the insert(), but if the key is already there, update the value instead
    // Note that this function will return a pair of answer, the iterator and boolean status
    // That means this return may return a valid iterator, but its status is false, which mean the key is already there, but just
    // update its value, not new created iterator returned
    // STL: 1,3) If a key equivalent to k already exists in the container, assigns std::forward<M>(obj) to the mapped_type corresponding to 
    // the key k. If the key does not exist, inserts the new value as if by insert, constructing it from value_type(k, std::forward<M>(obj))
    // 2,4) Same as (1,3), except the mapped value is constructed from value_type(std::move(k), std::forward<M>(obj))
    // The behavior is undefined (until C++20)The program is ill-formed (since C++20) if std::is_assignable_v<mapped_type&, M&&> is false.
    // If an insertion occurs and results in a rehashing of the container, all iterators are invalidated. Otherwise iterators are not affected. 
    // References are not invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    // auto tricky_return = myStrToIntMap.insert_or_assign(std::make_pair("key99", 1000));
    // if (tricky_return.first != myStrToIntMap.end()) {
    //     cout << "Update key99 and return status " << boolalpha << tricky_return.second << endl;
    // } else {
    //     cout << "Fail to update key99 and return status " << boolalpha << tricky_return.second << endl;
    // }

    // emplace()/emplace_hint(), construct a new element into container without any copy or move operation
    // STL: Inserts a new element into the container constructed in-place with the given args if there is no element with the key in the 
    // container.
    // Careful use of emplace allows the new element to be constructed while avoiding unnecessary copy or move operations. The constructor 
    // of the new element (i.e. std::pair<const Key, T>) is called with exactly the same arguments as supplied to emplace, forwarded via 
    // std::forward<Args>(args).... The element may be constructed even if there already is an element with the key in the container, in 
    // which case the newly constructed element will be destroyed immediately.
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    // STL: Inserts a new element to the container, using hint as a suggestion where the element should go. The element is constructed in-place, 
    // i.e. no copy or move operations are performed.
    // The constructor of the element type (value_type, that is, std::pair<const Key, T>) is called with exactly the same arguments as 
    // supplied to the function, forwarded with std::forward<Args>(args)....
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    myStrToIntMap.emplace(std::make_pair("key100", 100));
    myStrToIntMap.emplace_hint(myStrToIntMap.end(), std::make_pair("key101", 101));
    for (auto item : myStrToIntMap) {
        cout << item.first << " " << item.second << endl;
    }

    // try_emplace(), do nothing if the key is already in container
    // STL: Inserts a new element into the container with key k and value constructed with args, if there is no element with the key in the 
    // container.
    // 1) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace except that the element is 
    // constructed as
    //value_type(std::piecewise_construct,
    //       std::forward_as_tuple(k),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // 2) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace except that the element is 
    // constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(std::move(k)),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // 3) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace_hint except that the element 
    // is constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(k),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // 4) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace_hint except that the element 
    // is constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(std::move(k)),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    // auto tricky_return2 = myStrToIntMap.try_emplace(std::make_pair("key99", 1000));
    // if (tricky_return2.first != myStrToIntMap.end()) {
    //    cout << "Update key99 and return status " << boolalpha << tricky_return2.second << endl;
    // } else {
    //    cout << "Fail to update key99 and return status " << boolalpha << tricky_return2.second << endl;
    // }

    // erase(), remote the specific element in container
    // STL: Removes specified elements from the container.
    // 1) Removes the element at pos.
    // 2) Removes the elements in the range [first; last), which must be a valid range in *this.
    // 3) Removes the element (if one exists) with the key equivalent to key.
    // 4) Removes the element (if one exists) with key that compares equivalent to the value x. This overload participates in overload 
    // resolution only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type, and neither iterator nor 
    // const_iterator is implicitly convertible from K. This assumes that such Hash is callable with both K and Key type, and that the 
    // KeyEqual is transparent, which, together, allows calling this function without constructing an instance of Key.
    // References and iterators to the erased elements are invalidated. Other iterators and references are not invalidated.
    // The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferenceable) cannot 
    // be used as a value for pos.
    // The order of the elements that are not erased is preserved. (This makes it possible to erase individual elements while iterating 
    // through the container.)
    cout << "Removing elements ......" << endl;
    myStrToIntMap.erase("key99");
    myStrToIntMap.erase("key100");
    myStrToIntMap.erase("key101");
    for (auto item : myStrToIntMap) {
        cout << item.first << " " << item.second << endl;
    }

    // swap(), swap content in two containers with same type defined
    // STL: Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual 
    // elements.
    // All iterators and references remain valid. The past-the-end iterator is invalidated.
    // The Hash and KeyEqual objects must be Swappable, and they are exchanged using unqualified calls to non-member swap.
    // If std::allocator_traits<allocator_type>::propagate_on_container_swap::value is true, then the allocators are exchanged using an 
    // unqualified call to non-member swap. Otherwise, they are not swapped (and if get_allocator() != other.get_allocator(), the behavior 
    // is undefined).(since C++11)
    cout << "myStrToIntMap2 is clear now" << endl;
    myStrToIntMap2.clear();
    for (auto item : myStrToIntMap2) {
        cout << item.first << " " << item.second << endl;
    }
    cout << "myStrToIntMap2 is being swapped now" << endl;
    myStrToIntMap2.swap(myStrToIntMap);
    for (auto item : myStrToIntMap2) {
        cout << item.first << " " << item.second << endl;
    }
    // copy construct
    myStrToIntMap = myStrToIntMap2;

    // extract(), get key from container, modify key, and add it back. Not a usual way
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
    auto modify = myStrToIntMap.extract("key4");
    modify.key() = "key4444";
    myStrToIntMap.insert(move(modify));
    // update value as well
    // myStrToIntMap.insert_or_assign(std::make_pair("key4444", 4444));
    for (auto item : myStrToIntMap) {
        cout << item.first << " " << item.second << endl;
    }

    // merge(), merge content from one container to another container. Note that if key is already in the to be merged container, it will 
    // be skipped and leave in original container
    // STL: Attempts to extract ("splice") each element in source and insert it into *this using the hash function and key equality 
    // predicate of *this. If there is an element in *this with key equivalent to the key of an element from source, then that element 
    // is not extracted from source. No elements are copied or moved, only the internal pointers of the container nodes are repointed. 
    // All pointers and references to the transferred elements remain valid, but now refer into *this, not into source. Iterators referring 
    // to the transferred elements and all iterators referring to *this are invalidated. Iterators to elements remaining in source remain 
    // valid.
    // The behavior is undefined if get_allocator() != source.get_allocator().
    cout << "After merge" << endl;
    myStrToIntMap2.merge(myStrToIntMap);
    for (auto item : myStrToIntMap2) {
        cout << item.first << " " << item.second << endl;
    }

    // at(), return the value of the specific key
    // STL: Returns a reference to the mapped value of the element with key equivalent to key. If no such element exists, an exception of type 
    // std::out_of_range is thrown.
    auto at_return = myStrToIntMap2.at("key1");
    cout << at_return << endl;

    // [] operation of map
    // STL: Returns a reference to the value that is mapped to a key equivalent to key, performing an insertion if such key does not already 
    // exist.
    // 1) Inserts a value_type object constructed in-place from std::piecewise_construct, std::forward_as_tuple(key), std::tuple<>() if the 
    // key does not exist. This function is equivalent to return this->try_emplace(key).first->second;. (since C++17)
    // When the default allocator is used, this results in the key being copy constructed from key and the mapped value being value-initialized.
    // -value_type must be EmplaceConstructible from std::piecewise_construct, std::forward_as_tuple(key), std::tuple<>(). When the default 
    // allocator is used, this means that key_type must be CopyConstructible and mapped_type must be DefaultConstructible.
    // 2) Inserts a value_type object constructed in-place from std::piecewise_construct, std::forward_as_tuple(std::move(key)), std::tuple<>() 
    // if the key does not exist. This function is equivalent to return this->try_emplace(std::move(key)).first->second;. (since C++17)
    // When the default allocator is used, this results in the key being move constructed from key and the mapped value being value-initialized.
    // -value_type must be EmplaceConstructible from std::piecewise_construct, std::forward_as_tuple(std::move(key)), std::tuple<>(). When the 
    // default allocator is used, this means that key_type must be MoveConstructible and mapped_type must be DefaultConstructible.
    // If an insertion occurs and results in a rehashing of the container, all iterators are invalidated. Otherwise iterators are not affected. 
    // References are not invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    myStrToIntMap2["key1"] = 100;
    myStrToIntMap2["key2"] = 200;
    myStrToIntMap2["key3"] = 300;
    myStrToIntMap2["key4"] = 400;

    // the given key does not exist yet, but this will automatically add (key50, 50) into container
    myStrToIntMap2["key50"] = 50;

    cout << "After new key50 is added" << endl;
    for (auto item : myStrToIntMap2) {
        cout << item.first << " " << item.second << endl;
    }

    // count(), return # of elements of specific key, here should be either 0 or 1 only as it can only handle one unique key
    // STL: 1) Returns the number of elements with key that compares equal to the specified argument key, which is either 1 or 0 since this 
    // container does not allow duplicates.
    // 2) Returns the number of elements with key that compares equivalent to the specified argument x. This overload participates in overload 
    // resolution only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash is 
    // callable with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without constructing 
    // an instance of Key.
    cout << "How many key1 in the container? " << myStrToIntMap2.count("key1") << endl;
    cout << "How many key333 in the container? " << myStrToIntMap2.count("key333") << endl;

    // find(), check and see if the given key existed in the container
    // STL: 1,2) Finds an element with key equivalent to key.
    // 3,4) Finds an element with key that compares equivalent to the value x. This overload participates in overload resolution only 
    // if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash is callable with 
    // both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without constructing an 
    // instance of Key.
    auto myReturn1 = myStrToIntMap2.find("key1");
    if (myReturn1 != myStrToIntMap2.end()) {
        cout << "Found key1 in container, key = " << myReturn1->first << ", value = " << myReturn1->second << endl;
    }

    // contains(), similar to find(), but it will return boolean status. Note this one is supported only from C++ 20 or above
    // STL: 1) Checks if there is an element with key equivalent to key in the container.
    // 2) Checks if there is an element with key that compares equivalent to the value x. This overload participates in overload resolution 
    // only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash is callable 
    // with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without constructing an 
    // instance of Key.



    // equal_range(), return a pair of iterators, first one is the first iterator of the key, the second one is the first iterator that is 
    // right after the key
    // STL: 1,2) Returns a range containing all elements with key key in the container. The range is defined by two iterators, the first 
    // pointing to the first element of the wanted range and the second pointing past the last element of the range.
    // 3,4) Returns a range containing all elements in the container with key equivalent to x. This overload participates in overload 
    // resolution only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash is 
    // callable with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without 
    // constructing an instance of Key.



    // bucket_count()/max_bucket_count()/bucket_size()/bucket(), same as unordered_set container



    // load_factor()/max_load_factor()/rehash()/reserve(), same as unorder_set container



    // hash_function()/key_eq(), same as unorder_set container



    // std::swap()/erase_if(), same as unorder_set container

    return 0;
}
