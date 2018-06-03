/*
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
示例 2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
*/

#include <vector>
#include <iostream>
using namespace std;


// 用等差数列的求和公式求出0到n之间所有的数字之和，然后再遍历数组算出给定数字的累积和，然后做减法，差值就是丢失的那个数字
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0 ;
        int n = nums.size();
        for (auto a : nums){
            sum += a;
        }
        return 0.5 * n * (n + 1) - sum;
    }
};

//思路是既然0到n之间少了一个数，我们将这个少了一个数的数组合0到n之间完整的数组异或一下，
// 那么相同的数字都变为0了，剩下的就是少了的那个数字了

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i){
            result ^= (i + 1) ^ nums[i];
        }
        return result;
    }
};


// 还可以用二分查找法来做，我们首先要对数组排序，然后我们用二分查找法算出中间元素的下标，
// 然后用元素值和下标值之间做对比，如果元素值大于下标值，则说明缺失的数字在左边，
// 此时将right赋为mid，反之则将left赋为mid+1。

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size();
        while (left < right){
            int mid = left + (right - left) / 2;
            if (nums[mid] > mid){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};