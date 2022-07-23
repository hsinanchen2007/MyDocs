/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

/*

https://leetcode.cn/problems/median-of-two-sorted-arrays/

4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

 

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2

示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5


提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
通过次数750,605提交次数1,809,785

*/

// @lc code=start
class Solution {
public:

    // 2022.7.10, very interesting question, it looks pretty easy but actually tricky
    // below answer can pass LC, but time O() will not meet the request, however, 
    // somehow it's not that slow compared with all below answers
    double findMedianSortedArrays5(vector<int>& nums1, vector<int>& nums2) {
        vector<int> allNums;
        int size1 = nums1.size(), size2 = nums2.size();

        for (int i = 0; i < nums1.size(); i++) allNums.push_back(nums1[i]);
        for (int j = 0; j < nums2.size(); j++) allNums.push_back(nums2[j]);

        sort(allNums.begin(), allNums.end());

        int left = allNums[(size1+size2-1)/2], right = allNums[(size1+size2)/2];

        return (left+right)/2.0;
    }

    // 2022.7.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/median-of-two-sorted-arrays.cpp
    double findMedianSortedArrays4(vector<int>& nums1, vector<int>& nums2) {
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1);
        } else {
            return (findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2) +
                    findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1)) / 2.0;
        }
    }

    int findKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B,
                                 int k) {
        const int m = A.size();
        const int n = B.size();

        // Make sure m is the smaller one.
        if (m > n) {
            return findKthInTwoSortedArrays(B, A, k);
        }

        int left = 0;
        int right = m - 1;
        // Find a partition of A and B
        // where min left s.t. A[left] >= B[k - 1 - left]. Thus A[left] is the (k+1)-th or above element.
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (0 <= k - 1 - mid && k - 1 - mid < n && A[mid] >= B[k - 1 - mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        int Ai_minus_1 = left - 1 >= 0 ? A[left - 1] : numeric_limits<int>::min();
        int Bj = k - 1 - left >= 0 ? B[k - 1 - left] : numeric_limits<int>::min();

        // kth element would be A[left - 1] or B[k - 1 - left].
        return max(Ai_minus_1, Bj);
    }

    // 2022.7.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/median-of-two-sorted-arrays.cpp
    double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int> *> arrays{&nums1, &nums2};
        int total = accumulate(cbegin(arrays), cend(arrays), 0,
                               [](const auto& x, const auto& y) {
                                   return x + size(*y);
                               });
        if (total % 2 == 1) {
            return findKthInSortedArrays(arrays, total / 2 + 1);
        } else {
            return (findKthInSortedArrays(arrays, total / 2) +
                    findKthInSortedArrays(arrays, total / 2 + 1)) / 2.0;
        }
    }

private:
    int findKthInSortedArrays(const vector<vector<int> *>& arrays, int k) {
        int left = numeric_limits<int>::max();
        int right = numeric_limits<int>::min();
        for (const auto array : arrays) {
            if (!empty(*array)) {
                left = min(left, array->front());
                right = max(right, array->back());
            }
        }
        // left xxxxxxxooooooo right, find first xo or oo
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (check(arrays, mid, k)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool check(const vector<vector<int> *>& arrays, int num, int target) {
        int res = 0;
        for (const auto array : arrays) {
            if (!array->empty()) {  // count the number of values which are less or equal to num
                res += distance(array->cbegin(),
                                upper_bound(array->cbegin(), array->cend(), num));
            }
        }
        return res >= target;
    }

    // 2022.7.11, from AcWing https://www.acwing.com/solution/content/50/
    // 作者：yxc
    // 链接：https://www.acwing.com/solution/content/50/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        算法1
        (递归) O(log(n+m))O(log(n+m))
        原问题难以直接递归求解，所以我们先考虑这样一个问题：

        在两个有序数组中，找出第k小数。

        如果该问题可以解决，那么第 (n+m)/2(n+m)/2 小数就是我们要求的中位数.

        先从简单情况入手，假设 m,n≥k/2m,n≥k/2，我们先从 nums1nums1 和 nums2nums2 中各取前 k/2k/2 个元素：

        如果 nums1[k/2−1]>nums2[k/2−1]nums1[k/2−1]>nums2[k/2−1]，则说明 nums1nums1 中取的元素过多，
        nums2nums2 中取的元素过少；因此 nums2nums2 中的前 k/2k/2 个元素一定都小于等于第 kk 小数，所以我们
        可以先取出这些数，将问题归约成在剩下的数中找第 k−⌊k/2⌋k−⌊k/2⌋ 小数.
        如果 nums1[k/2−1]≤nums2[k/2−1]nums1[k/2−1]≤nums2[k/2−1]，同理可说明 nums1nums1 中的前 k/2k/2 
        个元素一定都小于等于第 kk 小数，类似可将问题的规模减少一半.
        现在考虑边界情况，如果 m<k/2m<k/2，则我们从 nums1nums1 中取m个元素，从nums2nums2 中取 k/2k/2 个元素
        （由于 k=(n+m)/2k=(n+m)/2，因此 m,nm,n 不可能同时小于 k/2k/2.）：

        如果 nums1[m−1]>nums2[k/2−1]nums1[m−1]>nums2[k/2−1]，则 nums2nums2 中的前 k/2k/2 个元素一定都
        小于等于第 kk 小数，我们可以将问题归约成在剩下的数中找第 k−⌊k/2⌋k−⌊k/2⌋ 小数.
        如果 nums1[m−1]≤nums2[k/2−1]nums1[m−1]≤nums2[k/2−1]，则 nums1nums1 中的所有元素一定都小于等于第 
        kk 小数，因此第k小数是 nums2[k−m−1]nums2[k−m−1].
        时间复杂度分析：k=(m+n)/2k=(m+n)/2，且每次递归 kk 的规模都减少一半，因此时间复杂度是 O(log(m+n))O(log(m+n)).
    */
public:
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 0)
        {
            int left = findKthNumber(nums1, 0, nums2, 0, total / 2);
            int right = findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
            return (left + right) / 2.0;
        }
        else
        {
            return findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
        }
    }

    int findKthNumber(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
    {
        if (nums1.size() - i > nums2.size() - j) return findKthNumber(nums2, j, nums1, i, k);
        if (nums1.size() == i) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int si = min(i + k / 2, int(nums1.size())), sj = j + k / 2;
        if (nums1[si - 1] > nums2[sj - 1])
        {
            return findKthNumber(nums1, i, nums2, j + k / 2, k - k / 2);
        }
        else
        {
            return findKthNumber(nums1, si, nums2, j, k - (si - i));
        }
    }

    /*
        算法2
        （二分） O(log(min(m,n))O(log(min(m,n))
        该算法的处理细节非常繁琐，建议新手直接跳过。
        首先，让我们考虑只有一个有序数组的情况：

        如果我们将有序数组切分为等长的左右两部分，则 中位数 = (左半边的最大值 + 右半边的最小值) / 2.

        切分情况有两种，例如：

        数组长度是偶数，对于 [2 3 5 7], 我们在3和5之间切分：[2 3 / 5 7]，则 中位数 =(3+5)/2=(3+5)/2；
        数组长度是奇数，对于 [2 3 4 5 7]，我们在4的位置切分，且让4属于左右两边：[2 3 (4/4) 5 7]，则 
        中位数 =(4+4)/2=(4+4)/2.
        现在让我们来考虑两个有序数组的情况，类似于上述考虑方式：

        我们在两个数组中分别找到一个分割点（分割点可能在相邻数之间，也可能在数上），两个分割点左边元素的
        总个数等于右边元素的总个数，且左边元素的最大值 <= 右边元素的最小值，则该分割点即为所求。

        为了同时处理分割点在两数之间和在数上的情况，我们在数组中可能是分割点的位置添加虚拟元素 ‘@’，这样
        我们枚举数组 A′1A1′ 的所有元素，即可枚举 A1A1 所有可能的分割点：

        A1:[1,2,3,4,5]=>A′1:[@,1,@,2,@,3,@,4,@,5,@]A1:[1,2,3,4,5]=>A1′:[@,1,@,2,@,3,@,4,@,5,@]
        A2:[1,1,1,1]=>A′2:[@,1,@,1,@,1,@,1,@]A2:[1,1,1,1]=>A2′:[@,1,@,1,@,1,@,1,@]
        我们将数组 A1A1 的长度记为 N1N1，则 A′1A1′ 的长度为 2∗N1+12∗N1+1; A2A2 的长度记为 N2N2，则 
        A′2A2′ 的长度为 2∗N2+12∗N2+1. 总共有 2N1+2N2+22N1+2N2+2 个元素.

        假设数组 A′1A1′ 的分割点下标是 C1C1，数组 A′2A2′ 的分割点下标是 C2C2，则 C1C1 和 C2C2 之间具有
        如下等式关系：
        C1+C2=N1+N2

        证明：除了 C1C1 和 C2C2 以外，共有 2N1+2N22N1+2N2 个元素，要平均分配到左右两边，因此左边共有 
        N1+N2N1+N2 个元素. 数组下标从0开始，下标为 C1C1 的元素左边有 C1C1 个元素，下标为 C2C2 的元素左边
        有 C2C2 个元素，由此可得上述等式.

        为了方便表述，在 A′1A1′ 中，C1C1 左边（包括C1C1）的最大值记为 L1L1，C1C1 右边（包括C1C1）的最小值
        记为 R1R1；在 A′2A2′ 中，C2C2 左边（包括C2C2）的最大值记为 L2L2，C2C2 右边（包括C2C2）的最小值记为 
        R2R2；

        则如果我们选取的分割点满足
        L1<=R1&&L1<=R2&&L2<=R1&&L2<=R2
        L1<=R1&&L1<=R2&&L2<=R1&&L2<=R2

        则分割点即为所求. 由于 A1,A2A1,A2 都是有序的，因此 L1<=R1&&L2<=R2L1<=R1&&L2<=R2 一定满足；
        不满足的情况有两种：

        如果 L1>R2L1>R2，表示 A2A2中在分割点左侧的元素太少，此时我们需要将 C2C2 右移；
        如果 L2>R1L2>R1，表示 A2A2中在分割点左侧的元素太多，此时我们需要将 C2C2 左移；
        符合二分结构.

        另外，我们在实际操作中，不需要真的在原数组中插入 ‘@’，只需找出 L1,R1,L2,R2L1,R1,L2,R2 和 C1,C2C1,
        C2 的关系即可.
        
        我们可以列表找规律：

        C1C1	L1L1	R1R1
        0	INT_MIN	A1[0]
        1	A1[0]	A1[0]
        2	A1[0]	A1[1]
        3	A1[1]	A1[1]
        4	A1[1]	A1[2]
        由此我们可以发现:

        L1=A1[(C1−1)/2]L1=A1[(C1−1)/2]
        R1=A1[C1/2]R1=A1[C1/2]

        类似可得：
        L2=A2[(C2−1)/2]L2=A2[(C2−1)/2]
        R2=A2[C2/2]R2=A2[C2/2]
        最后，还有两点需要注意：

        我们只能二分长度较小的数组，因为长度较长的数组中的某些分割点可能不合法，会出现 C1>N1+N2C1>N1+N2 的情况；
        我们在数组边界设置两个哨兵，来处理 C1=0C1=0 或 C1=2N1C1=2N1 的情况：
        A1[−1]=INTMIN,A1[2N]=INTMAXA1[−1]=INTMIN,A1[2N]=INTMAX. 这样做并不会影响结果，但可以简化代码.
        时间复杂度：二分长度较短的数组，且每次二分的复杂度是 O(1)O(1)，所以总复杂度是 O(log(min(n,m)))O(log(min(n,m))).
    */
public:
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2) return findMedianSortedArrays(nums2, nums1);

        int lo = 0, hi = N2 * 2;
        while (lo <= hi) {
            int mid2 = (lo + hi) / 2;
            int mid1 = N1 + N2 - mid2;

            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
            double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
            double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];

            if (L1 > R2) lo = mid2 + 1;
            else if (L2 > R1) hi = mid2 - 1;
            else return (max(L1,L2) + min(R1, R2)) / 2;
        }
        return -1;
    }

    // 2022.7.11, from https://github.com/grandyang/leetcode/issues/4
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        int left1 = 0, right1 = nums1.size();
        int half = (nums1.size()+nums2.size()+1)/2; //left median or median
        int max_left=0, min_right=0;

        while (left1<= right1) {
            int mid1 = (left1+right1)/2;
            int mid2 = half-mid1;
            if (mid1 < nums1.size() && nums1[mid1] < nums2[mid2-1]) {
                left1 = mid1+1;
            } else if (mid1 > 0 && nums1[mid1-1] > nums2[mid2]) {
                right1 = mid1-1;
            } else {
                if (mid1 == 0) max_left = nums2[mid2-1];
                else if (mid2 == 0) max_left = nums1[mid1-1];
                else max_left = max(nums1[mid1-1], nums2[mid2-1]);

                if ((nums1.size()+ nums2.size()) & 1) return max_left;

                if (mid1 == nums1.size()) min_right = nums2[mid2];
                else if (mid2 == nums2.size()) min_right = nums1[mid1];
                else { min_right = min(nums1[mid1], nums2[mid2]);}
                
                return (static_cast<double>(min_right) + max_left)/2;
            }
        }
        assert(0);
        return -1;
    }

};
// @lc code=end

