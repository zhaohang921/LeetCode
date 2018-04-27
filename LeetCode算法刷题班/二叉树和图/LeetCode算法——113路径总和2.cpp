/*
给定一个二叉树和一个目标和，找到所有从根节点到叶节点路径总和等于给定目标和的路径。

例如，
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

/*
思路：
从根结点深度遍历二叉树，先序遍历时，将该节点值存储至path栈中（vector实现），使用path_value累加节点值
当遍历至叶节点时，检查path_value值是否为sum，若为sum，则将path push进入result结果
在后序遍历时，将该节点值从path栈中弹出，path_value减去节点值
*/

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<assert.h>
// using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    std::vector<std::vector<int> > pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int> > result;
        std::vector<int> path;
        int path_value=0;
        preOrder(root,path_value,sum,path,result);
        return result;
    }
private:
    void preOrder(TreeNode *node, int &path_value, int sum, std::vector<int> &path, 
                std::vector<std::vector<int> > &result){
        if(!node){
            return;
        }
        path_value+=node->val;
        path.push_back(node->val); 
        if(path_value==sum && !node->left && !node->right){
            result.push_back(path);
        }
        preOrder(node->left,path_value,sum,path,result);
        preOrder(node->right,path_value,sum,path,result);
        path_value-=node->val;
        path.pop_back();
    }
};

int main(){
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode x(5);
    TreeNode y(1);
    a.left=&b;
    a.right=&c;
    b.left=&d;
    c.left=&e;
    c.right=&f;
    d.left=&g;
    d.right=&h;
    f.left=&x;
    f.right=&y;
    Solution solve;
    std::vector<std::vector<int> > result=solve.pathSum(&a,22);
    for(int i=0;i<result.size();++i){
        for(int j=0;j<result[i].size();++j){
            std::cout<<'['<<result[i][j]<<']';
        }
        std::cout<<std::endl;
    }
    return 0;
}