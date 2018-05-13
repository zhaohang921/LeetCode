/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s == ""){
            return true;
        }
        vector<char> char_vec; //vector当作栈来用
        char_vec.push_back(s[0]);
        for (int i = 1; i < s.size(); ++i){
            switch (s[i]){
                case '(': 
                case '[': 
                case '{':
                    char_vec.push_back(s[i]);
                    break;
                case ')':
                    if (char_vec.back() == '('){
                        char_vec.pop_back();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (char_vec.back() == '['){
                        char_vec.pop_back();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (char_vec.back() == '{'){
                        char_vec.pop_back();
                    } else {
                        return false;
                    }
                    break;                 
                default:
                    break;
            }
        }
        if (char_vec.empty()){
            return true;
        } else {
            return false;
        }
        return char_vec.empty();
    }
};

class Solution2{
public:
    bool isValid(string s){
        vector<char> vec;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                vec.push_back(s[i]);
            } else {
                if (vec.empty()){
                    return false;
                }
                if ((s[i] == ')' && vec.back() != '(') || 
                    (s[i] == ']' && vec.back() != '[') || 
                    (s[i] == '}' && vec.back() != '{')){
                    return false;
                }
                vec.pop_back();
            }
        }
        return vec.empty();
    }
};

// 垃圾思路
// class Solution {
// public:
//     bool isValid(string s) {
//         if (s.empty()){
//             return true;
//         }
//         int strs[3] = {0};
//         for (int i = 0; i < s.size(); ++i){
//             switch (s[i]){
//                 case '(':
//                     ++strs[0];
//                     break;
//                 case '[':
//                     ++strs[1];
//                     break;
//                 case '{':
//                     ++strs[2];
//                     break;
//                 case ')':
//                     if (strs[0] >= 1){
//                         strs[0]--;
//                     } else {
//                         return false;
//                     }
//                     break;
//                 case ']':
//                     if (strs[1] >= 1){
//                         strs[1]--;
//                     } else {
//                         return false;
//                     }
//                     break;
//                 case '}':
//                     if (strs[2] >= 1){
//                         strs[2]--;
//                     } else {
//                         return false;
//                     }  
//                     break;                
//                 default:
//                     break;
//             }
//         }
//         return true;
//     }
// };