/*
给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。

示例 1:

输入: [3, 2, 1]

输出: 1

解释: 第三大的数是 1.
示例 2:

输入: [1, 2]

输出: 2

解释: 第三大的数不存在, 所以返回最大的数 2 .
示例 3:

输入: [2, 2, 3, 1]

输出: 1

解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
存在两个值为2的数，它们都排第二。

*/

#include <vector>
#include <iostream>
using namespace std;


//用三个变量first, second, third来分别保存第一大，第二大，和第三大的数，
//然后我们遍历数组，如果遍历到的数字大于当前第一大的数first，那么三个变量各自错位赋值，
//如果当前数字大于second，小于first，那么就更新second和third，
//如果当前数字大于third，小于second，那就只更新third，
//注意这里有个坑，就是初始化要用长整型long的最小值，否则当数组中有INT_MIN存在时，程序就不知道该返回INT_MIN还是最大值first了
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        for (int num : nums){
            if (num > first){
                third = second;
                second = first;
                first = num;
            } else if (num > second && num < first){
                third = second;
                second = num;
            } else if (num > third && num < second){
                third = num;
            }
        }
        return (third == LONG_MIN || third == second) ? first : third;
    }
};