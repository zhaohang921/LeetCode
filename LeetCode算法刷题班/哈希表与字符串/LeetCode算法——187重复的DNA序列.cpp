/*
所有DNA由一系列缩写为A，C，G和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究DNA时，识别DNA中的重复序列有时非常有用。

编写一个函数来查找DNA分子中所有出现超多一次的10个字母长的序列（子串）。

例如，

给出 s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

返回:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

/*
思路：

*/
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

//方法一：暴力枚举
class Solution1 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> word_map;
        vector<string> result;
        for(int i=0;i<s.size();++i){
            string word=s.substr(i,10);
            if(word_map.find(word)!=word_map.end()){
                word_map[word]++;
            }
            else{
                word_map[word]=1;
            }
        }
        // map<string,int>::iterator it;
        auto it=word_map.begin();
        for(;it!=word_map.end();++it){
            if(it->second>1){
                result.push_back(it->first);
            }
        }
        return result;
    }
};
// int g_hash_map[1048576]={0};
//方法二
class Solution2 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.length()<10){
            return result;
        }
        for(int i=0;i<1048576;++i){
            g_hash_map[i]=0;
        }
        int char_map[128]={0};
        char_map['A']=0;
        char_map['C']=1;
        char_map['G']=2;
        char_map['T']=3;
        int key=0;
        for(int i=9;i>=0;--i){       //key的最左边的一位是末尾，最右边的一位是首位
            key=(key<<2)+char_map[s[i]];
        }
        g_hash_map[key]=1;
        for(int i=10;i<s.length();++i){
            key=key>>2; //将key中最后一位移除
            key=key | (char_map[s[i]]<<18); //将新的char_map[s[i]]这一位添到key的第一位
            g_hash_map[key]++;
        }
        for(int i=0;i<1048576;++i){
            if(g_hash_map[i]>1){
                result.push_back(change_int_to_DNA(i));
            }
        }
        return result;
    }
private:
    string change_int_to_DNA(int DNA){
        static const char DNA_CHAR[]={'A','C','G','T'};
        string str;
        for(int i=0;i<10;++i){
            str+=DNA_CHAR[DNA & 3];
            DNA=DNA>>2;
        }
        return str;
    }

private:
    int g_hash_map[1048576]={0};
};