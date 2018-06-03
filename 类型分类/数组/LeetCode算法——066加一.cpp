/*
给定一个非负整数组成的非空数组，在该数的基础上加一，返回一个新的数组。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*/

#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i){
            if (digits[i] == 9){
                digits[i] = 0;
            } else {
                digits[i] += 1;
                return digits;
            }
        }
        if (digits.front() == 0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};