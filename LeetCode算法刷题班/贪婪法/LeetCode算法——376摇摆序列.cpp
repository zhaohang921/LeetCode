/*
如果连续数之间的差异严格地交替在正与负之间，则称为摇摆序列。
第一个区别(如果存在的话)可能是正的，也可能是负的。一个少于两个元素的序列是一个摇摆序列。

例如，[1,7,4,9,2,5]是一个摇摆序列，因为差异(6，-3,5，-7,3)是正的和负的。
相反，[1,4,7,2,5]和[1,7,4,5,5]不是波动序列，第一个因为它的前两个差是正的，第二个因为它的最后一个差是零。

给你一个随机序列，求这个序列满足摇摆序列定义的最长子序列的长度
Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
*/

/*
思路： 贪心
当序列有一段连续的递增或递减时，为形成摇摆子序列，我们只需要保留这段连续的递增或递减的首尾元素，
这样更可能使得尾部的后一个元素成为摇摆子序列的下一个元素
*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
         if(nums.size()<2) return nums.size();//序列小于2时直接为摇摆序列
         static const int BEGIN=0;
         static const int UP=1;
         static const int DOWN=2;
         int STATE=BEGIN;
         int max_length=1;//摇摆序列最大长度至少为1
         for(int i=1;i<nums.size();++i){
             switch(STATE){
                 case BEGIN:
                    if(nums[i]>nums[i-1]){
                        STATE=UP;
                        ++max_length;
                    }
                    else if(nums[i-1]>nums[i]){
                        STATE=DOWN;
                        ++max_length;
                    }
                    break;
                case UP:
                    if(nums[i]<nums[i-1]){
                        STATE=DOWN;
                        ++max_length;
                    }
                    break;
                case DOWN:
                    if(nums[i]>nums[i-1]){
                        STATE=UP;
                        ++max_length;
                    }   
                    break;
             }
        }
        return max_length;
    }
};