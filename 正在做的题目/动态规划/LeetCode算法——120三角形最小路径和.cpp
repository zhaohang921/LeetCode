/*
给出一个三角形（数据数组），找出从上往下的最小路径和。每一步只能移动到下一行中的相邻结点上。
比如，给你如下三角形：
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
则从上至下最小路径和为 11（即，2 + 3 + 5 + 1 = 11）

*/

/*
思路：
1.设置一个二维数组，最优值三角形dp[][]，并初始化数组元素为0
dp[i][j]代表了从底向上递推时，走到三角形第i行第j列的最优解
2.从三角形的底面向三角形上方进行动态规划
    动态规划边界条件：底面上的最优值即为数字三角形的最后一层
    利用i循环，从倒数第二层递推至第一层，对于每层的各列，进行动态规划递推
第i行第j列的最优解为dp[i][j]，可到达（i,j）的两个位置的最优解dp[i+1][j]、dp[i+1][j+1]
dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j]
最终的最优解是dp[0][0]
*/
#include<vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if(triangle.empty()) return 0;
        vector<vector<int> > dp;
        for(int i=0;i<triangle.size();++i){
            dp.push_back(vector<int> ());
            for(int j=0;j<triangle[i].size();++j){
                dp[i].push_back(0);
            }
        }
        for(int i=0;i<dp.size();++i){
            dp[dp.size()-1][i]=triangle[triangle.size()-1][i];
        }
        for(int i=dp.size()-2;i>=0;--i){
            for(int j=0;j<dp[i].size();++j){
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
