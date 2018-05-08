/*
给定一个可能包含重复整数数组 nums，返回所有可能的子集。

说明：解集不能包含重复的子集。

例如，给定 nums = [1,2,2]，解集为：

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

/*
方法一：
对原始数组进行排序，再使用set去重复
*/
#include<iostream>
#include<vector>
#include<set>

using namespace std;
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> item;
        result.push_back(item);
        set<vector<int> > res_set;
        sort(nums.begin(), nums.end());
        generate(0, nums, result, item, res_set);
        return result;
    }

private:
    void generate(int i, vector<int>& nums, vector<vector<int> >& result,
                  vector<int> item, set<vector<int> >& res_set){
        if (i >= nums.size()){
            return;
        }
        item.push_back(nums[i]);
        if (res_set.find(item) == res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i + 1, nums, result, item, res_set);
        item.pop_back();
        generate(i + 1, nums, result, item, res_set);
    }
};


int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    vector<vector<int> > result;
    Solution solve;
    result=solve.subsetsWithDup(nums);
    for(auto i : result){
        if(i.size()==0){
            cout<<"[ ]";
        }
        for(auto j : i){
            cout<<"["<<j<<"]";
        }
        cout<<endl;
    }
    return 0;
}