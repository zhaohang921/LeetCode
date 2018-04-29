/*
给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循这种模式。

这里的 遵循 指完全匹配，例如在pattern里的每个字母和字符串 str 中的每个非空单词存在双向单映射关系。

例如：

pattern = "abba", str = "dog cat cat dog", 返回true 
pattern = "abba", str = "dog cat cat fish", 返回false.
pattern = "aaaa", str = "dog cat cat dog" , 返回false.
pattern = "abba", str = "dog dog dog dog" , 返回false.
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分开的小写单词。    
*/
#include <string>
#include <map>
#include <iostream>
class Solution {
public:
    bool wordPattern(std::string pattern, std::string str) {
        std::map<std::string, char> word_map;
        char used[128] = {0};
        std::string word;
        int pos = 0; //当前pattern中字符的位置
        str.push_back(' ');
        for (int i = 0; i < str.size(); ++i){
            if (str[i] == ' '){
                if (pos == pattern.length()){
                    return false;
                }
                if (word_map.find(word) == word_map.end()){ //单词没有出现在哈希映射中
                    if (used[pattern[pos]]){ //当前的pattern字符已经使用
                        return false;
                    }
                    word_map[word] = pattern[pos];
                    used[pattern[pos]] = 1;
                } else { //单词出现在哈希映射中
                    if (word_map[word] != pattern[pos]){
                        return false;
                    }
                }
                word = ""; //word单词清空
                ++pos;  //pattern中的pos向后移动一位
            } else {
                word += str[i];
            }
        }
        if (pos != pattern.length()){ //str中的字符都遍历完了，pattern中的字符还没有遍历结束，说明还有多余的pattern字符存在
            return false;
        }
        return true;
    }
};

int main(){
    std::string pattern = "abba";
    std::string str = "dog ha ha dog";
    std::string str1 = "dog ha ha ni";
    std::string str2 = "dog ha ha dog ha ah";
    Solution solve;
    std::cout << solve.wordPattern(pattern, str2);


    return 0;
}