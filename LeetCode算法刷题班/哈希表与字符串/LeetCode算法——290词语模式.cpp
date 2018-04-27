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

/*

*/
#include<string>
#include<map>
class Solution {
public:
    bool wordPattern(std::string pattern, std::string str) {
        std::map<std::string,char> word_map;
        char used[128]={0};
        std::string word;
        int pos=0; //当前指向的pattern字符
        str.push_back(' '); //str尾部push一个空格，使得遇到空格拆分单词
        for(int i=0;i<str.length();++i){
            if(str[i]==' '){
                if(pos==pattern.length()){
                    return false;  //若分隔出一个单词，但已没有pattern字符对应
                }
                if(word_map.find(word)==word_map.end()){ //单词没出现在哈希映射中
                    if(used[pattern[pos]]){  //如果当前pattern字符已使用
                        return false;
                    }
                    word_map[word]=pattern[pos];
                    used[pattern[pos]]=1;
                }
                else{
                    if(word_map[word]!=pattern[pos]){ //若当前word已建立映射，无法与当前pattern对应
                        return false;
                    }
                }
                word="";
                pos++; //遇到一个单词pos+1
            }
            else{
                word+=str[i];
            }
        }
        if(pos!=pattern.length()){ //有多余的字符
            return false;
        }
        return true;
    }
};