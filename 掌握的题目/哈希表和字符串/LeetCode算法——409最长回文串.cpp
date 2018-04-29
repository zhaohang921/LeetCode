/*
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
注意:
假设字符串的长度不会超过 1010。
示例 1:
输入:
"abccccdd"
输出:
7
解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

*/
#include <string>
#include <iostream>

class Solution {
public:
    int longestPalindrome(std::string s) {
        if (s.size() == 0){
            return 0;
        }
        int char_map[128] = {0}; //将数组中的每个数都赋值为0
        int max_length = 0;
        int flag = 0;
        for (int i = 0; i < s.size(); ++i){
            ++char_map[s[i]];
        }
        for (int i = 0; i < 128; ++i){
            if (char_map[i] % 2 == 0){
                max_length += char_map[i];
            } else {
                max_length += char_map[i] - 1;
                flag = 1;
            }
        }
        return max_length + flag;
    }
};

int main(){
    std::string s = "abcdefgabcdefgs";
    Solution solve;
    std::cout << solve.longestPalindrome(s);


    return 0;
}