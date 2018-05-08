/*
给定不同面额的硬币(coins)和一个总金额(amount)。
写一个函数来计算可以凑成总金额所需的最少的硬币个数。
如果没有任何一种硬币组合方式能组成总金额，返回-1。

示例 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

示例 2:
coins = [2], amount = 3
return -1.

注意:

你可以认为每种硬币的数量是无限的。
*/

/*
思路：
钞票面值：coins=[1,2,5,7,10];金额14
dp[i],代表金额i的最优解
数组dp中存储金额1至金额14的最优解

在计算dp[i]时，dp[0],dp[1],dp[2]...dp[i-1]都是已知的
而金额i可由：
金额i-1与coins[0]组合
金额i-2与coins[1]组合
金额i-5与coins[2]组合
金额i-7与coins[3]组合
金额i-10与coins[4]组合

*/
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        for(int i=0;i<=amount;++i){
            dp.push_back(-1);  //初始化数组，全是-1
        }
        dp[0]=0; //金额0的最优解是0
        for(int i=0;i<=amount;++i){ //循环每一个金额
            for(int j=0;j<coins.size();++j){ //循环每一个面值
                if(i-coins[j]>=0 && dp[i-coins[j]]!=-1){  //金额i要比面值大，并且i减去当前面值也有最优解
                    if(dp[i]==-1 || dp[i]>dp[i-coins[j]]+1){ 
                        dp[i]=dp[i-coins[j]]+1;
                    }
                }
            }
        }
        return dp[amount];
    }
};