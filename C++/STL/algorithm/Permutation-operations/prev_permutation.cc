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
#include <iterator>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/prev_permutation

Transforms the range [first, last) into the previous permutation from the set of all permutations 
that are lexicographically ordered with respect to operator< or comp. Returns true if such permutation 
exists, otherwise transforms the range into the last permutation (as if by std::sort(first, last); 
std::reverse(first, last);) and returns false.

Return value
true if the new permutation precedes the old in lexicographical order. false if the first permutation 
was reached and the range was reset to the last permutation.

*/

int main()
{
    std::string s="abc";
    std::sort(s.begin(), s.end(), std::greater<char>());
    do {
        std::cout << s << ' ';
    } while(std::prev_permutation(s.begin(), s.end()));
    std::cout << '\n';

    return 0;
    // cba cab bca bac acb abc
}
