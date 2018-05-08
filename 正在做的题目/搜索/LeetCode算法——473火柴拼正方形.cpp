/*
还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。
不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。

输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。

示例 1:

输入: [1,1,2,2,2]
输出: true

解释: 能拼成一个边长为2的正方形，每边两根火柴。
示例 2:

输入: [3,3,3,3,4]
输出: false

解释: 不能用所有火柴拼成一个正方形。
注意:

给定的火柴长度和在 0 到 10^9之间。
火柴数组的长度不超过15。

*/

/*
火柴总和对4取余为0
火柴按照从大到小排序
*/
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<iostream>
using namespace std;


//方法一：回溯法
class Solution1 {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4){
            return false;
        }
        int sum = 0;
        for (auto i : nums){
            sum += i;
        }
        if ((sum % 4) != 0){
            return false;
        }
        std::sort(nums.rbegin(), nums.rend());  //从大到小排序
        int bucket[4] = { 0 };
        return generate(0, nums, sum / 4, bucket);
    }
private:
    bool generate(int i, std::vector<int>& nums, int target, int bucket[]){
        if (i >= nums.size()){
            return bucket[0] == target && bucket[1] == target   
                && bucket[2] == target && bucket[3] == target;
        }
        for (int j = 0; j < 4; ++j){
            if ((bucket[j] + nums[i]) > target){
                continue;
            }
            bucket[j] += nums[i];
            if (generate(i+1, nums, target, bucket)){
                return true;
            }
            bucket[j] -= nums[i];
        }
        return false;
    }
};

//方法二：位运算
/*
使用位运算法，构造出所有和为target的子集，存储在向量ok_subset中，这些是候选的边组合
遍历所有的ok_subset，两两进行对比，如果两个进行 与运算 的结果为0，则说明这两个无交集，
这两个集合可以代表两个可以同时存在的满足条件的边

*/
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4){
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
        }
        if (sum % 4){
            return false;
        }
        int target = sum / 4;
        std::vector<int> ok_subset;  //所有满足条件的一个边代表的集合
        std::vector<int> ok_half;  //所有满足条件的两个边代表的集合
        int all = 1 << nums.size();
        for (int i = 0; i < all; ++i){
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j){
                if (i & (1 << j)){   //i中是否有第j这个元素，也就是把位的和为i的所有元素的值加起来
                    sum += nums[j];
                }
            }
            if (sum == target){
                ok_subset.push_back(i);
            }
        }
        for (int i = 0; i < ok_subset.size(); ++i){
            for (int j = i + 1; j < ok_subset.size(); ++j){
                if ((ok_subset[i] & ok_subset[j]) == 0){
                    ok_half.push_back(ok_subset[i] | ok_subset[j]);
                }
            }
        }
        for (int i = 0; i < ok_half.size(); ++i){
            for (int j = i + 1; j < ok_half.size(); ++j){
                if ((ok_half[i] & ok_half[j]) == 0){
                    return true;
                }
            }
        }
        return false;
    }

};


int main(){
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(2);
    Solution solve;
    std::cout << solve.makesquare(vec) << std::endl;


    return 0;
}