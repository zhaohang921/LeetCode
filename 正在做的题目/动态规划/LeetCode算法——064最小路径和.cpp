/*
给定一个只含非负整数的 m x n 网格，找到一条从左上角到右下角的可以使数字之和最小的路径。

注意: 每次只能向下或者向右移动一步。

示例 1:

[[1,3,1],
 [1,5,1],
 [4,2,1]]
根据上面的数组，返回 7. 因为路径 1→3→1→1→1 总和最小。


*/

/*
思路：
与三角形最小路径和的题目非常类似

*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if(grid.empty()) return 0;
        int row=grid.size();
        int column=grid[0].size();
        vector<vector<int> > dp(row,vector<int>(column,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<column;++i){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
        for(int i=1;i<row;++i){
            dp[i][0]=grid[i][0]+dp[i-1][0];
            for(int j=1;j<column;++j){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[row-1][column-1];
    }
};