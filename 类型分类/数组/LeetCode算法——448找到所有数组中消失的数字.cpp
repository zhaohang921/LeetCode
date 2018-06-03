/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例:

输入:
[4,3,2,7,8,2,3,1]

输出:
[5,6]
*/

#include <vector>
#include <iostream>
using namespace std;


// 将nums[i]置换到其对应的位置nums[nums[i]-1]上去，
// 比如对于没有缺失项的正确的顺序应该是[1, 2, 3, 4, 5, 6, 7, 8]，
// 而我们现在却是[4,3,2,7,8,2,3,1]，我们需要把数字移动到正确的位置上去，
// 比如第一个4就应该和7先交换个位置，以此类推，最后得到的顺序应该是[1, 2, 3, 4, 3, 2, 7, 8]，
// 我们最后在对应位置检验，如果nums[i]和i+1不等，那么我们将i+1存入结果res中即可
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] != nums[nums[i] - 1]){  // 把nums[i]换到它该去的地方
                swap(nums[i], nums[nums[i] - 1]);
                --i; // 这一步是为了把换过来的数再换到它该去的地方
            }
        }
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] != i + 1){
                result.push_back(i + 1);
            }
        }
        return result;
    }
};