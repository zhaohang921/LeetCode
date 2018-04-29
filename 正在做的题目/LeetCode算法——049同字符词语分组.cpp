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
#include<string>
#include<map>
#include<vector>

class Solution1 {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::map<std::string,std::vector<std::string>> _map;
        for (int i = 0; i < strs.size(); ++i){
            std::string temp_str = strs[i];
            sort(temp_str.begin(),temp_str.end());
            if (_map.find(temp_str) == _map.end()){
                std::vector<std::string> item;
                _map[temp_str] = item;
            }
            _map[temp_str].push_back(strs[i]);
        }
        std::vector<std::vector<std::string>> result;
        for (auto it = _map.begin(); it != _map.end(); ++it){
            result.push_back(it->second);
        }
        return result;
    }
};


//哈希表以26个字母的字符数量为key，以字符串向量为value，存储各个字符数量相同的字符串
class Solution{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
        std::map<std::vector<int>, std::vector<std::string>> _map;
        for (int i = 0; i < strs.size(); ++i){
            std::vector<int> temp;
            change_to_vector(strs[i],temp);
            if (_map.find(temp) == _map.end()){
                std::vector<std::string> item;
                _map[temp] = item;
            }
            _map[temp].push_back(strs[i]);
        }
        std::vector<std::vector<std::string>> result;
        for (auto it = _map.begin(); it != _map.end(); ++it){
            result.push_back(it->second);
        }
        return result;
    }
private:
//将字符串str中的各个字符数量进行统计，存储至vec
    void change_to_vector(std::string& str, std::vector<int>& vec){
        for (int i = 0; i < 26; ++i){
            vec.push_back(0);
        }
        for (int i = 0; i < str.size(); ++i){
            ++vec[str[i] - 'a'];
        }
    }
};