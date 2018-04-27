/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。  
*/

/*

*/
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class Solution1 {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string,vector<string> > anagram;
        vector<vector<string> > result;
        for(int i=0;i<strs.size();++i){
            string str=strs[i];
            sort(str.begin(),str.end());
            if(anagram.find(str) == anagram.end()){ //str不在映射表中
                vector<string> item;   //设置一个空的字符串向量
                anagram[str]=item; //以排序后的strs[i]作为key
            }
            anagram[str].push_back(strs[i]);
        }
        map<string,vector<string> >::iterator it;
        for(it=anagram.begin();it!=anagram.end();++it){
            result.push_back((*it).second);
        }
        return result;
    }
};

//方法二：
//哈希表以26个字母的字符数量为key，以字符串向量为value，存储各个字符数量相同的字符串
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string> > anagram;
        vector<vector<string> > result;
        for(int i=0;i<strs.size();++i){
            vector<int> vec;
            change_to_vector(strs[i],vec);
            if(anagram.find(vec)==anagram.end()){
                vector<string> item;
                anagram[vec]=item;
            }
            anagram[vec].push_back(strs[i]);
        }
        map<vector<int>,vector<string> >::iterator it;
        for(it=anagram.begin();it!=anagram.end();++it){
            result.push_back((*it).second);
        }
        return result;
    }
private:
    //将字符串str中的各个字符数量进行统计，存储至vec
    void change_to_vector(string &str,vector<int> &vec){
        for(int i=0;i<26;++i){
            vec.push_back(0);
        }
        for(int i=0;i<str.length();++i){
            vec[str[i]-'a']++;
        }
    }
};