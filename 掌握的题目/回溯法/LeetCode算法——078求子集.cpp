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

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> item;
        result.push_back(item);
        generate(0, nums, item, result);
        return result;
    }

private:
    void generate(int i, vector<int>& nums, vector<int>& item,
                  vector<vector<int> >& result){
        if (i >= nums.size()){
            return;
        }
        item.push_back(nums[i]);
        result.push_back(item);
        generate(i + 1, nums, item, result);
        item.pop_back();
        generate(i + 1, nums, item, result);
    }
};

//位运算法
class Solution2 {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        int all_set = 1 << nums.size();
        for ( int i = 0; i < all_set; ++i){
            vector<int> item;
            for (int j = 0; j < nums.size(); ++j){
                if (i & (1 << j)){
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    cout << "递归结果："<< endl;
    Solution solve;
    vector<vector<int> > result = solve.subsets(nums);
    for (auto i : result){
        for (auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }

    cout << "位运算结果："<< endl;
    Solution2 solve2;
    vector<vector<int> > result2 = solve2.subsets(nums);
    for (auto i : result2){
        for (auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}
