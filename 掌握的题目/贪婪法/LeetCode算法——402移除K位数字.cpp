/*
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
示例 2 :

输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 :

输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。

*/

/*
思路：
利用栈，把vector当作栈来用
从最高位开始每一位都要是当前能放的最小的数

*/

#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> S;//把vector当作栈
        for (int i = 0; i < num.size(); ++i){
            int number = num[i] - '0';//将字符型num转换成整数使用
            while (S.size() != 0 && number < S.back() && k > 0){ 
                //如果当前的数比栈顶的数小，就把栈顶的数丢掉
                S.pop_back();
                --k;
            }
            //如果当前数是0，那么就必须保证栈里有数字
            if (number != 0 || S.size() != 0){
                S.push_back(number);
            }
        }
        //末尾的数一直是非减的，并且还没有移除足够的位数
        while (S.size() != 0 && k > 0){
            S.pop_back();
            --k;
        }
        string result = "";
        for (int i = 0; i < S.size(); ++i){
            result.push_back('0' + S[i]);
            // result.append(1,'0'+S[i]);
        }
        if (result == ""){
            result = "0";
        }
        return result;

    }
};