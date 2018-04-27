/*
给定一个序列（至少含有 1 个数），从该序列中寻找一个连续的子序列，使得子序列的和最大。

例如，给定序列 [-2,1,-3,4,-1,2,1,-5,4]，
连续子序列 [4,-1,2,1] 的和最大，为 6。

*/

/*
思路：将求n个数组的最大子段和，转换为分别求出以第1个，第2个。。。第n个数字结尾的最大子段和，再找出这n个结果中最大的，即为结果


*/
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        int max_res=dp[0];
        for(int i=1;i<nums.size();++i){
            dp[i]=max(dp[i-1]+nums[i],nums[i]); // 如果dp[i-1]大于0，就带上，如果dp[i-1]小于0，就不带
            if(dp[i]>max_res){
                max_res=dp[i];
            }
        }
        return max_res;      
    }
};