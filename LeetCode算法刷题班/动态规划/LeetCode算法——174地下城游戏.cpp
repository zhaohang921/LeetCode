/*
一些恶魔抓住了公主（P）并将她关在了地下城的右下角。
地下城是由 M x N 个房间组成的二维网格布局。
我们英勇的骑士（K）最初被安置在左上角的房间里，并且必须通过地下城对抗来拯救公主。
骑士具有以正整数表示的初始健康点。如果他的健康点在任何时候降至 0 或以下，他会立即死亡。
有些房间由恶魔守卫，因此骑士在进入这些房间时失去健康点（负整数）；其他房间要么是空的（0），要么包含增加骑士身体健康的魔法球（正整数）。
为了尽快到达公主，骑士决定只会每次向右或向下移动一步。

写一个函数来确定骑士的最低初始健康点数，以便他能够拯救公主。

例如，考虑到下面的地下城，如果骑士遵循最佳路径 RIGHT-> RIGHT -> DOWN -> DOWN，则骑士的初始健康必须至少为 7。

-2 (K)	 -3	    3
-5	     -10	1
10	     30	    -5 (P)
注意:
骑士的健康点没有上限。
任何房间都可能对骑士健康点造成威胁，也可能增加骑士的健康点，包括骑士进入的第一个房间和公主被监禁的右下角房间。
*/

/*
思路：
从右下方向左上方

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        if(dungeon.size()==0){
            return 0;
        }
        vector<vector<int> > dp(dungeon.size(),vector<int>(dungeon[0].size(),0));
        int row=dungeon.size();
        int column=dungeon[0].size();
        dp[row-1][column-1]=max(1,1-dungeon[row-1][column-1]);
        for(int i=column-2;i>=0;--i){
            dp[row-1][i]=max(1,dp[row-1][i+1]-dungeon[row-1][i]);
        }
        for(int i=row-2;i>=0;--i){
            dp[i][column-1]=max(1,dp[i+1][column-1]-dungeon[i][column-1]);
        }
        for(int i=row-2;i>=0;--i){
            for(int j=column-2;j>=0;--j){
                int dp_min=min(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=max(1,dp_min-dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};