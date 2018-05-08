/*
你是一个专业的强盗，计划抢劫沿街的房屋。每间房都藏有一定的现金，
阻止你抢劫他们的唯一的制约因素就是相邻的房屋有保安系统连接，
如果两间相邻的房屋在同一晚上被闯入，它会自动联系警方。
给定一个代表每个房屋的金额的非负整数列表，确定你可以在没有提醒警方的情况下抢劫的最高金额。

示例一：
nums里面存放的是：5，2，6，3，1，7
抢劫结果应该是：5+6+7=18
*/

/*
思路：如果选第i个房间，则第i-1个房间一定没选，那么当前最优解就是前i-2个房间的最优解加上当前的第i个房间
     如果不选第i个房间，则当前最优解就是前i-1个房间的最优解

*/

#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();++i){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};