/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
*/

#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> out;
        if (rowIndex < 0) return out;
        
        out.assign(rowIndex + 1, 0); // 初始数组中全是0
        for (int i = 0; i <= rowIndex; ++i) {
            if ( i == 0) {
                out[0] = 1;
                continue;
            }
            for (int j = rowIndex; j >= 1; --j) {
                out[j] = out[j] + out[j-1];
            }
        }
        return out;
    }
};