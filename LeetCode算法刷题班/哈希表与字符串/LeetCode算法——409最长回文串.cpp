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

/*
回文字符串：从前向后遍历和从后向前遍历都是相同的
利用字符哈希，统计字符串中所有的字符数量
*/
#include<string>

class Solution {
public:
    int longestPalindrome(std::string s) {
        int char_map[128]={0};
        int max_length=0;
        int flag=0;  //中心点
        for(int i=0;i<s.length();++i){
            char_map[s[i]]++;
        }
        for(int i=0;i<128;++i){
            if(char_map[i]%2==0){
                max_length+=char_map[i];
            }
            else{
                max_length+=char_map[i]-1;
                flag=1;
            }
        }
        return max_length+flag;
    }
};