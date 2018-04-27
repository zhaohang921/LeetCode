/*
给定一棵二叉树，想象自己站在它的右侧，返回从顶部到底部看到的节点值。

例如：
给定以下二叉树，

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
你应该返回 [1, 3, 4]。
*/

/*
思路：
宽度搜索，
层次搜索二叉树每一层最后一个节点
将节点层数绑定为pair，
*/

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<algorithm>
#include<assert.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        queue<pair<TreeNode* ,int> > Q;
        if(root){
            Q.push(make_pair(root,0));
        }
        while(!Q.empty()){
            TreeNode *node=Q.front().first;
            int depth=Q.front().second;
            Q.pop();
            if(view.size()==depth){  //到了一个新的层数，将该层的第一个节点入队
                view.push_back(node->val);
            }
            else{               //更新这个节点的值，一直到这一层的最后一个节点
                view[depth]=node->val;
            }
            if(node->left){
                Q.push(make_pair(node->left,depth+1));
            }
            if(node->right){
                Q.push(make_pair(node->right,depth+1));
            }
        }
        return view;
    }
};