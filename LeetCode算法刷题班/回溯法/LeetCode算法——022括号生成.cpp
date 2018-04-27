/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

/*
思路：
在搜索回溯过程中进行剪枝操作，
递归调用时，计算已选择元素的和sum,若sum大于target，不再进行更深的搜索
*/
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("",n,n,result);
        return result;
    }

private:
    void generate(string item,int left,int right,vector<string>& result){
        if(left==0 && right==0){
            result.push_back(item);
            return;
        }
        if(left>0){
            generate(item+"(",left-1,right,result);
        }
        if(left<right){
            generate(item+")",left,right-1,result);
        }
    }
};

int main(){
    // vector<int> nums;
    // nums.push_back(2);
    // nums.push_back(5);
    // nums.push_back(2);
    // nums.push_back(1);
    // nums.push_back(2);
    // vector<vector<int> > result;
    Solution solve;
    vector<string> result = solve.generateParenthesis(4);
    for(auto i : result){
        cout<<i<<endl;
    }
    return 0;
}