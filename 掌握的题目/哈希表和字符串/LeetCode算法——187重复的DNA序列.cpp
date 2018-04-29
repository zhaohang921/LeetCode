/*
所有DNA由一系列缩写为A，C，G和 T 的核苷酸组成，例如：“ACGAATTCCG”。
在研究DNA时，识别DNA中的重复序列有时非常有用。
编写一个函数来查找DNA分子中所有出现超多一次的10个字母长的序列（子串）。
例如，
给出 s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
返回:
["AAAAACCCCC", "CCCCCAAAAA"].
*/
#include <vector>
#include <string>
#include <map>
#include <iostream>
class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        std::map<std::string, int> word_map;
        std::vector<std::string> result;
        for (int i = 0; i < s.size(); ++i){
            std::string temp = s.substr(i, 10);
            if (word_map.find(temp) != word_map.end()){
                ++word_map[temp];
            } else {
                word_map[temp] = 1;
            }
        }
        for(auto it = word_map.begin(); it != word_map.end(); ++it){
            if (it->second > 1){
                result.push_back(it->first);
            }
        }
        return result;
    }
};

int main(){
    std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution solve;
    std::vector<std::string> result;
    result = solve.findRepeatedDnaSequences(s);
    for (auto i : result){
        std::cout << i << std::endl;
    }
    return 0;
}
