/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        vector<vector<int> > mark;
        vector<string> location;
        for (int i = 0; i < n; ++i){
            mark.push_back(vector<int> ());
            for (int j = 0; j < n; ++j){
                mark[i].push_back(0);
            }
            location.push_back("");
            location[i].append(n, '.');
        }
        generate(0, n, location, result, mark);
        return result;
    }

private:
    void generate(int k, int n, vector<string>& location,
                  vector<vector<string> >& result, vector<vector<int> >& mark){
        if (k == n){
            result.push_back(location);
            return;
        }
        for (int i = 0; i < n; ++i){
            if (mark[k][i] == 0){
                vector<vector<int> > tmp_mark = mark;
                location[k][i] = 'Q';
                put_down_the_queue(k, i, mark);
                generate(k + 1, n, location, result, mark);
                mark = tmp_mark;
                location[k][i] = '.';
            }
        }
    }

    void put_down_the_queue(int x, int y, vector<vector<int> >& mark){
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1}; //方向数组
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        mark[x][y] = 1;
        for (int i = 1; i < mark.size(); ++i){
            for (int j = 0; j < 8; ++j){ //8个方向
                int new_x = x + i * dx[j];
                int new_y = y + i * dy[j];
                if (new_x >= 0 && new_x < mark.size() && 
                    new_y >= 0 && new_y < mark.size()){
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }
};

int main(){
    vector<vector<string> > result;
    Solution solve;
    result=solve.solveNQueens(8);
    int d=1;
    for(auto i : result){
        cout<<"第"<<d<<":"<<endl;
        for(auto j : i){
            cout<<j<<endl;
        }
        ++d;
    }
    return 0;
}

