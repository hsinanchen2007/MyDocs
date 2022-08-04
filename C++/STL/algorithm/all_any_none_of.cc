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

https://en.cppreference.com/w/cpp/algorithm/all_any_none_of

1) Checks if unary predicate p returns true for all elements in the range [first, last).
3) Checks if unary predicate p returns true for at least one element in the range [first, last).
5) Checks if unary predicate p returns true for no elements in the range [first, last).
2,4,6) Same as (1,3,5), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

See also Notes below.

1-2) true if unary predicate returns true for all elements in the range, false otherwise. 
Returns true if the range is empty.
3-4) true if unary predicate returns true for at least one element in the range, false otherwise. 
Returns false if the range is empty.
5-6) true if unary predicate returns true for no elements in the range, false otherwise. 
Returns true if the range is empty.


algorithm 头文件中定义了 3 种算法，用来检查在算法应用到序列中的元素上时，什么时候使谓词返回 true。
这些算法的前两个参数是定义谓词应用范围的输入迭代器；第三个参数指定了谓词。检查元素是否能让谓词返回 true 似乎很简单，
但它却是十分有用的。

例如，可以检查所有学生是否通过了考试，或者检查所有学生是否都参加了课程，或者检查有没有眼睛发绿的 Person 对象，
甚至可以检查每个 Dog 对象是否度过了它自己的一天。谓词可以简单，也可以复杂，这取决于你。检查元素属性的三种算法是：
all_of() 算法会返回 true，前提是序列中的所有元素都可以使谓词返回 true。
any_of() 算法会返回 true，前提是序列中的任意一个元素都可以使谓词返回 true。
none_of() 算法会返回 true，前提是序列中没有元素可以使谓词返回 true。

想象它们是如何工作的并不难。下面的一些代码用来说明如何使用 none_of() 算法：
std::vector<int> ages {22, 19, 46, 75, 54, 19, 27, 66, 61, 33, 22, 19};
int min_age{18};
std::cout << "There are "<< (std::none_of(std::begin(ages), std::end(ages),[min_age](int age) 
{ return age < min_age; }) ? "no": "some") << " people under " << min_age << std::endl;
这个谓词是一个 lambda 表达式，用来将传入的 ages 容器中的元素和 min_age 的值作比较。用 none_of() 返回的布尔值
来选择包含在输出信息中的是“no”还是“some”。当 ages 中没有元素小于 min_age 时，none_of() 算法会返回 true。
在这种情况下，会选择“no”。当然，用 any_of() 也能产生同样的结果：
std::cout << "There are "<< (std::any_of(std::begin(ages), std::end(ages),[min_age] (int age) 
{ return age < min_age;}) ? "some":"no") <<" people under " << min_age << std::endl;
只有在有一个或多个元素小于 min_age 时，any_of() 算法才会返回 true。

这里没有元素小于 min_age，所以也会选择“no”。

下面是一段代码，用来展示用 all_of() 检查 ages 容器中的元素：
int good_age{100};
std::cout << (std::all_of(std::begin(ages), std::end(ages),[good_age] (int age) 
{ return age < good_age; }) ? "None": "Some") << " of the people are centenarians." << std::endl;
这个 lambda 表达式会将 ages 中的元素和 good_age 的值作比较，good_age 的值为 100。所有的元素都小于 100，
所以 all_of() 会返回 true，而且输出消息会正确报告没有记录的百岁老人。

count 和 count_if 可以告诉我们，在前两个参数指定的范围内，有多少满足指定的第三个参数条件的元素。count() 
会返回等同于第三个参数的元素的个数。count_if() 会返回可以使作为第三个参数的谓词返回 true 的元素个数。

下面是一些将这些算法应用到 ages 容器的示例：
std::vector<int> ages {22, 19, 46, 75, 54, 19, 27, 66, 61, 33, 22, 19};
int the_age{19};
std::cout << "There are "<< std::count(std::begin(ages),std::end(ages),the_age)<< " 
people aged "<< the_age << std::endl;
int max_age{60};
std::cout << "There are "<< std::count_if(std::begin(ages), std::end(ages),[max_age](int age) 
{ return age > max_age; }) << " people aged over " << max_age << std::endl;
在第一条输出语句中使用 count() 算法来确定 ages 中等于 the_age 的元素个数，第二条输出语句使用 count_if() 
来报告大于 max_age 的元素个数。

当我们想知道序列元素是否有某种特性或有多少满足标准时，本节中的所有算法都可以用来了解关于序列元素的基本特性的信息。
如果想要知道具体的一序列中哪个元素匹配可以使用前面章节介绍的 find() 算法。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    vector<int> myV = {1, 3, 5, 7, 9, 10};

    // by using all_of() to see if all values in the given vector are odd or not
    // note that all_of() returns true only if the condition applies to all return true
    bool isAllOdd = all_of(myV.begin(), myV.end(), [](int value) { return (value % 2 == 0); });
    if (isAllOdd) {
        cout << "All numbers are odd!" << endl;
    } else {
        cout << "Some numbers are even!" << endl;
    }

    // by using any_of() to see if any value in the given vector is even or not
    // note that any_of() returtns true as long as the condition matches to one value
    bool isAnyEven = any_of(myV.begin(), myV.end(), [](int value) { return (value % 2 == 0); });
    if (isAnyEven) {
        cout << "At least one number is even!" << endl;
    } else {
        cout << "All numbers are odd!" << endl;
    }

    // by using none_of() to see if any value is larger than 100 or not
    // note that none_of() returns true only if the condition applies to all values return false
    bool allLess = none_of(myV.begin(), myV.end(), [](int value) { return (value > 100); });
    if (allLess) {
        cout << "None of numbers is larger than 100!" << endl;
    } else {
        cout << "At least one number is larger than 100!" << endl;
    }

    // 2022.7.31
    // easier to remember is, whether "function" them is "condition"? Then use this to for return true/false 
    // from C++ 20, these functions will be under std::ranges, not under std::

    return 0;
    // Some numbers are even!
    // At least one number is even!
    // None of numbers is larger than 100!
}
