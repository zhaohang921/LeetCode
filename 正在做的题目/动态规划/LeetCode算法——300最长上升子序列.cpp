/*
给出一个无序的整形数组，找到最长上升子序列的长度。
例如，
给出 [10, 9, 2, 5, 3, 7, 101, 18]，
最长的上升子序列是 [2, 3, 7, 101]，因此它的长度是4。
因为可能会有超过一种的最长上升子序列的组合，因此你只需要输出对应的长度即可。

你的算法的时间复杂度应该在 O(n2) 之内。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
*/

/*
思路：
若第i个状态dp[i]代表以第i个元素结尾的最长上升子序列的长度
dp[i-1]代表以第i-1个元素结尾的最长上升子序列长度
nums[i]一定是dp[i]所对应的最长上升子序列中最大的元素

思路二：
设置一个栈stack,stack[i]代表长度为i+1的上升子序列最后一个元素的最小可能取值
即若要组成长度为i+2的上升子序列，需要一个大于stack[i]的元素
最终栈的大小就是最大上升子序列的长度
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(),0);
        dp[0]=1;
        int LIS=1;
        for(int i=1;i<dp.size();++i){
            dp[i]=1;
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            if(LIS<dp[i]){
                LIS=dp[i];
            }
        }
        return LIS;
    }
};

//实现优化n*logn
class Solution2 {
public:
    int binary_search(vector<int> nums,int target){
        int index=-1;
        int begin=0;
        int end=nums.size()-1;
        while(index==-1){
            int mid=(begin+end)/2;
            if(target==nums[mid]){
                index=mid;
            }
            else if(target<nums[mid]){
                if(mid==0 || target>nums[mid]-1){
                    index=mid;
                }
                end=mid-1;
            }
            else if(target>nums[mid]){
                if(mid==nums.size()-1 || target<nums[mid+1]){
                    index=mid+1;
                }
                begin=mid+1;
            }
        }
        return index;
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> stack;
        stack.push_back(nums[0]);
        for(int i=1;i<nums.size();++i){
            if(nums[i]>stack.back()){
                stack.push_back(nums[i]);
            }
            else{
                //二分法找nums[i]应该插入的位置
                int pos=binary_search(stack,nums[i]);
                stack[pos]=nums[i];
            }
        }
        return stack.size();
    }
};