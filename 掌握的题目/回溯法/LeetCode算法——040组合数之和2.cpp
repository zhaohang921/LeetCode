/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
*/

/*
思路：
在搜索回溯过程中进行剪枝操作，
递归调用时，计算已选择元素的和sum,若sum大于target，不再进行更深的搜索
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target){
        vector<vector<int> > result;
        vector<int> item;
        set<vector<int> > res_set;
        sort(candidates.begin(), candidates.end());
        generate(0, candidates, result, item, res_set, 0, target);
        return result;
    }

private:
    void generate(int i, vector<int>& nums,
                  vector<vector<int> >& result, vector<int>& item,
                  set<vector<int> >& res_set, int sum, int target){
        if (i > nums.size() || sum > target){
            return;
        }
        sum += nums[i];
        item.push_back(nums[i]);
        if (sum == target && res_set.find(item) == res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i + 1, nums, result, item, res_set, sum, target);
        sum -= nums[i];
        item.pop_back();
        generate(i + 1, nums, result, item, res_set, sum, target);
    }
};

int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    vector<vector<int> > result;
    Solution solve;
    result = solve.combinationSum2(nums,5);
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