/*
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。
*/

/*
思路：贪心
什么时候跳跃最合适
在无法到达更远的地方时，在这之前应该跳到一个可以到达更远位置的位置
*/

#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int current_max_index=nums[0];//当前可到达的最远位置
        int pre_max_max_index=nums[0];//遍历各个位置的过程中，可到达的最远位置
        int jump_min=1;
        for(int i=1;i<nums.size();++i){
            if(current_max_index<i){
                ++jump_min;
                current_max_index=pre_max_max_index;
            }
            if(pre_max_max_index<nums[i]+i){
                pre_max_max_index=nums[i]+i;
            }
        }
        return jump_min;
    }
};