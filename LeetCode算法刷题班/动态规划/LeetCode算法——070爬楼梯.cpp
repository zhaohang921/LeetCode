/*
你正在爬楼梯。需要 n 步你才能到达顶部。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方式可以爬到楼顶呢？

注意：给定 n 将是一个正整数。

示例1:
输入： 2
输出： 2
说明： 有两种方法可以爬到顶端。

1.  1 步 + 1 步
2.  2 步

示例2:
输入： 3
输出： 3
说明： 有三种方法可以爬到顶端。

1.  1 步 + 1 步 + 1 步
2.  1 步 + 2 步
3.  2 步 + 1 步

*/

/*
方法一：暴力搜索，回溯法，超时
思路二：到达第i阶的方法是到达第i-1和第i-2阶的方法之和

*/

//代码一
#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+3,0);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;++i){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
//代码二
class climbStairs {
public:
    int jumpFloor(int n) {
        if(n>=1)
        {
            int f = 0, g = 1;
            while(n--) {
            g += f; //g是上一步骤的g和上一步骤的f之和
            f = g - f;//f就是上一步骤的g
            }
            return g;
        }
        return 0;
    }
};

