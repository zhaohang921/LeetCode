/*
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。 
*/

/*
思路：
1.设计一个记录字符数量的字符哈希：char_map
2.设置一个记录当前满足条件的最长子串变量word
3.设置两个指针（记作指针i和指针begin）指向字符串的第一个字符
4.设置最长满足条件的字串的长度result
5.指针向后逐个扫描字符串中的字符，在这个过程中，使用char_map记录字符数量
    如果word中没有出现过改字符，对word尾部添加字符并检查result是否需要更新
    否则，begin指针向前移动，更新char_map中的字符数量，直到字符s[i]的数量为1，
    更新word，将word赋值为begin和i之间的子串

在整个过程中，使用begin与i维护一个窗口，该窗口中的子串满足无重复的字符这个条件，窗口线性向前滑动，整体时间复杂度为O(n)
*/
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin=0;
        int result=0;
        string word="";
        int char_map[128]={0};
        for(int i=0;i<s.size();++i){
            char_map[s[i]]++;
            if(char_map[s[i]]==1){  //word中没有出现该字符
                word+=s[i];
                if(result<word.length()){
                    result=word.length();
                }
            }
            else{             //word中出现过该字符
                while(begin!=i && char_map[s[i]]>1){
                    char_map[s[begin]]--;
                    begin++;
                }
                word="";
                for(int j=begin;j<=i;++j){
                    word+=s[j];
                }
            }
        }
        return result;
    }
};   