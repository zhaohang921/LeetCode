/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows <= 0){
            return result;
        }
        result.assign(numRows, vector<int>(1));    // vector<int>(1) 的意思是每个vector里初始化一个元素空间
        for (int i = 0; i < numRows; ++i){  
            result[i][0] = 1;       // 每一行第一个数为1
            if (i == 0){
                continue;
            }
            for (int j = 1; j < i; ++j){
                result[i].push_back(result[i - 1][j] + result[i - 1][j - 1]);
            }
            result[i].push_back(1); // 每行最后一个为1
        }
        return result;
    }
};