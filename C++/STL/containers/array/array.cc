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
void printMyArray(string element) {
    cout << element << " ";
}

template<class T>
void test(T) {
    int a[std::tuple_size<T>::value]; // can be used at compile time
    std::cout << std::size_t(a) << '\n';
}
 
// main
int main() {
    // STL array container study
    array<string, 10> myArray = {"Welcome", "to", "Hsinan", "STL", "study", "class", "at", "year", "2022", "!"};
    array<string, 10> orgMyArray = myArray;

    // show given string first
    cout << "Input string in array is : ";
    for (auto item : myArray) {
        cout << item << " ";
    }
    cout << endl;

    // at(), get a specific element from array by giving index number
    // STL: Returns a reference to the element at specified location pos, with bounds checking.
    // If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
    string word = myArray.at(2);
    cout << "The STL array at(2) is " << word << endl;

    // at(), with out of bound check while by next operator[] way didn't have such check
    try {
        // size is 10, the index 100 is out of range here
        word = myArray.at(100);
    } catch (out_of_range const &exec) {
        // catch out of range error and show what happened in detail
        cout << "The STL array at() out of range check with index 100"<< endl;
        cout << exec.what() << endl;
    }

    // operator[], direct access element by array index way without out of range like at()
    // STL: Returns a reference to the element at specified location pos. No bounds checking is performed.
    word = myArray[0];
    cout << "The myArray[0] by using index 0 directly is : " << word << endl;

    // front(), get 1st element in array
    // STL: Returns a reference to the first element in the container.
    // Calling front on an empty container is undefined.
    word = myArray.front();
    cout << "The myArray front() returns: " << word << endl;

    // back(), get last element in array
    // STL: Returns a reference to the last element in the container. 
    // Calling back on an empty container causes undefined behavior.
    word = myArray.back();
    cout << "The myArray back() returns: " << word << endl;

    // data(), get array pointer, which is actually first element returned like array[0]
    // STL: Returns pointer to the underlying array serving as element storage. The pointer is such that range 
    // [data(); data() + size()) is always a valid range, even if the container is empty (data() is not 
    // dereferenceable in that case).
    word = *myArray.data();
    cout << "The myArray data() returns: " << word << endl;

    // iterators, by using "auto" to skip complicated declaration
    cout << "array iterator for each element: " << endl;
    for (auto it = myArray.begin(); it != myArray.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // iterators, by using complete declaration
    for (array<string, 10>::iterator it = myArray.begin(); it != myArray.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // iterators, by using complete declaration
    for_each(myArray.begin(), myArray.end(), printMyArray);
    cout << endl;
    // reverse iterators, it will do something reverse
    cout << "array reverse iterator for each element: " << endl;
    for_each(myArray.rbegin(), myArray.rend(), printMyArray);
    cout << endl;

    // empty(), see if the array now is empty or not
    // STL: Checks if the container has no elements, i.e. whether begin() == end().
    bool isEmpty = myArray.empty();
    cout << boolalpha;
    cout << "Is the arrary empty? " << isEmpty << endl;

    // will it become empty if I put all NULL into array?
    for (auto it = myArray.begin(); it != myArray.end(); it++) {
        *it = "";
    }    
    cout << "Is the arrary empty after assigning NULL into array? " << isEmpty << endl;

    // size(), return current size of array
    // STL: Returns the number of elements in the container, i.e. std::distance(begin(), end()).
    int arraySize = myArray.size();
    cout << "The arrary size is " << arraySize << endl;

    // max_size(), return max size of this array
    // STL: Returns the maximum number of elements the container is able to hold due to system or 
    // library implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
    int maxArraySize = myArray.max_size();
    cout << "The max arrary size is " << maxArraySize << endl;

    // fill(), instead of applying value one by one into all elements, this fill() will apply 
    // one value into all elements
    // STL: Assigns the given value value to all elements in the container.
    myArray.fill("TEST");
    for_each(myArray.begin(), myArray.end(), printMyArray);
    cout << endl;

    // swap(), swap the specific element with current one
    // STL: Exchanges the contents of the container with those of other. Does not cause iterators 
    // and references to associate with the other container.
    myArray[0] = "FIRST";
    myArray[9] = "LAST";
    cout << "Before swap " << myArray[0] << " " << myArray[9] << endl;
    myArray[0].swap(myArray[9]);
    cout << "After swap " << myArray[0] << " " << myArray[9] << endl;

    // std::get(), get specific element by index
    // STL: Extracts the Ith element element from the array. It must be an integer value in range [0, N). 
    // This is enforced at compile time as opposed to at() or operator[].
    myArray = orgMyArray;
    string theWord = std::get<0>(myArray);
    cout << "The specific word from std::get() is: " << theWord << endl;

    // std::swap(), swap whole array from one to another
    // STL: Specializes the std::swap algorithm for std::array. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
    // This overload participates in overload resolution only if N == 0 or std::is_swappable_v<T> is true. (since C++17)
    myArray.fill("TEST");
    array<string, 10> tmp = myArray;
    tmp.fill("TMP");
    cout << "Before swap " << tmp[0] << " " << myArray[0] << endl;
    std::swap(tmp, myArray);
    cout << "After swap " << tmp[0] << " " << myArray[0] << endl;

    // std::to_array(), create one array from existing one. Note that this is supported from C++ 20 only
    // STL: Creates a std::array from the one dimensional built-in array a. The elements of the std::array are copy-initialized 
    // from the corresponding element of a. Copying or moving multidimensional built-in array is not supported.
    // auto myNewArray = std::to_array("New string supported from C++ 20 or above version only");

    // std::tuple_size(std::array), get array size during compile time, without specifying the size from code
    // Note that below code run at my computer didn't return expected "3", but "140729639439684". Interesting, need to see why
    // STL: Provides access to the number of elements in an std::array as a compile-time constant expression.
    std::array<float, 3> arr;
    test(arr);

    // std::tuple_element<std::array>, get element type
    // Below code example is from https://en.cppreference.com/w/cpp/container/array/tuple_element
    // define array and get the type of the element at position 0
    std::array<int, 10> data {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    using T = std::tuple_element<0, decltype(data)>::type; // int
 
    std::cout << std::boolalpha;
    std::cout << std::is_same<T, int>::value << '\n';
 
    const auto const_data = data;
    using CT = std::tuple_element<0, decltype(const_data)>::type; // const int
 
    // the result of tuple_element depends on the cv-qualification of the tuple-like type
    std::cout << std::is_same<T, CT>::value << '\n';
    std::cout << std::is_same<CT, const int>::value << '\n';

    // STL: deduction guides for std::array
    // One deduction guide is provided for std::array to provide an equivalent of std::experimental::make_array 
    // for construction of std::array from a variadic parameter pack.
    // Below code example is from https://en.cppreference.com/w/cpp/container/array/deduction_guides
    // int const x = 10;
    // std::array a{1, 2, 3, 5, x}; // OK, creates std::array<int, 5>
    // assert(a.back() == x);
    //  std::array b{1, 2u}; // Error, all arguments must have same type
    //  std::array<short> c{3, 2, 1}; // Error, wrong number of template args
    // std::array c(std::to_array<short>({3, 2, 1})); // C++20 alternative, creates std::array<short, 3>

    return 0;
}
