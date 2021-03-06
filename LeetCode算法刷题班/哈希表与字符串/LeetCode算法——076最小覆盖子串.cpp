/*
给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
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
class Solution {
public:
    string minWindow(string s, string t) {
        const int MAX_ARRAY_LEN=128;
        int map_t[MAX_ARRAY_LEN]={0};
        int map_s[MAX_ARRAY_LEN]={0}; 
        for(int i=0;i<t.size();++i){
            map_t[t[i]]++;
        }
        vector<int> vec_t; //记录t字符串中有哪些字符
        for(int i=0;i<MAX_ARRAY_LEN;++i){
            if(map_t[i]>0){
                vec_t.push_back(i);
            }
        }   
        int window_begin=0; //最小窗口起始指针
        string result;    
        for(int i=0;i<s.length(); ++i){ //i代表了窗口的尾指针
            map_s[s[i]]++;
            while(window_begin<i){
                char begin_ch=s[window_begin];
                if(map_t[begin_ch]==0){ 
                    window_begin++;
                }
                else if (map_s[begin_ch] > map_t[begin_ch]){
                    map_s[begin_ch]--;
                    window_begin++;
                }
                else{
                    break;
                }
            }
            if(is_window_ok(map_s,map_t,vec_t)){
                int new_window_len = i - window_begin + 1;
                if ( result=="" || result.length()>new_window_len){
                    result=s.substr(window_begin, new_window_len);
                }
            }
        }
        return result;
    }

private:
    bool is_window_ok(int map_s[],int map_t[],vector<int> &vec_t){
        for(int i=0;i<vec_t.size();++i){
            if(map_s[vec_t[i]]<map_t[vec_t[i]]){
                return false; //如果s出现该字符的数量小于t中出现该字符的数量
            }
        }
        return true;
    }
};

