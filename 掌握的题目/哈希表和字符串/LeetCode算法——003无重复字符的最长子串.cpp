/*
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。

*/
#include <string>
#include <iostream>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int begin = 0;
        int result = 0; //存放最长子串的长度
        std::string word = "";
        int char_map[128] = {0}; //记录字母出现的次数
        for (int i = 0; i < s.size(); ++i){
            ++char_map[s[i]];
            if (char_map[s[i]] == 1){ //加完之后为1，说明该字母没出现过
                word += s[i];
                result = (result < word.length()) ? word.length() : result; //更新result的值
            } else {
                while (begin != i && char_map[s[begin]] >1){
                    --char_map[s[i]];
                    ++begin; //begin指针向前移动 
                }
                //更新word
                word = "";
                for (int j = begin; j <= i; ++j){
                    word += s[j];
                }
            }
        } 
        return result;
    }
};

int main(){
    std::string s = "abcabcbb";
    Solution solve;
    std::cout << solve.lengthOfLongestSubstring(s) << std::endl;
}