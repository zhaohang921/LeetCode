/*
给定一组不含重复元素的整数数组 nums，返回所有可能的子集。

说明：解集不能包含重复的子集。

例如，给定 nums = [1,2,3]，解集为：

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

/*
方法一：
递归

方法二：
位运算法
若一个集合有三个元素A，B，C
则3个元素有2^3=8种组成集合的方式，用0-7表示这些集合
*/
#include<vector>
using namespace std;

//方法一：递归
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> item;
        result.push_back(item);
        generate(0,nums,item,result);
        return result;
    }
private:
    void generate(int i,vector<int>& nums,vector<int>& item,vector<vector<int> >& result){
        if(i>=nums.size()){
            return;
        }
        item.push_back(nums[i]);
        result.push_back(item);
        generate(i+1,nums,item,result);
        item.pop_back();
        generate(i+1,nums,item,result);
    }
};

//方法二：位运算法
class Solution2 {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        int all_set=1<<nums.size();
        for(int i=0;i<all_set;++i){
            vector<int> item;
            for(int j=0;j<nums.size();++j){
                if(i & (1<<j)){
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
    }
};
