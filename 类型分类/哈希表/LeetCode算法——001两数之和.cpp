/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

思路：
一定能找到两个数的和等于目标数，并且答案唯一
建立map之后
*/
#include <vector>
#include <unordered_map>
#include <iostream>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        std::vector<int> result;
        if(nums.size() == 0){
            return result;
        }
        for (int i = 0; i < nums.size(); ++i){
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i){
            int t = target - nums[i];
            if (m.count(t) && m[t] != i){
                result.push_back(i);
                result.push_back(m[t]);
                break;
            }
        }
        return result;
    }
};

int main(){

    std::vector<int> nums(0);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    // for (int i = 0; i < nums.size(); ++i){
    //     std::cout << nums[i] << std::endl;
    // }
    int target = 9;
    Solution solve;
    std::vector<int> result = solve.twoSum(nums, target);
    std::cout << "result : " << std::endl;
    for (auto i : result){
        std::cout << i << ' ';
    }
    return 0;
}

class Solution2 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i){
            if (m.count(target - nums[i])){
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
