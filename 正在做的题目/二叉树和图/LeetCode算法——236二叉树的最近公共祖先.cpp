/*
给定一棵二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义： “对于有根树T的两个结点u、v，最近公共祖先表示一个结点x，满足x是u、v的祖先且x的深度尽可能大。”（一个节点也可以是它自己的祖先）

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
例如，节点5和节点1的最近公共祖先是节点3；节点5和节点4的最近公共祖先是节点5，因为根据定义，一个节点可以是它自己的祖先。
*/

/*
思路：
求p节点路径，q节点路径，两路径上最后一个相同的节点
从根结点遍历至该节点，找到该节点后就结束搜索
将遍历过程中遇到的节点按顺序存储起来，这些节点就是路径节点
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> path;
        std::vector<TreeNode*> node_p_path;
        std::vector<TreeNode*> node_q_path;
        int finish=0;
        preOrder(root,p,path,node_p_path,finish);
        path.clear();
        finish=0;
        preOrder(root,q,path,node_q_path,finish);
        int path_len=0; //较短路径的长度
        if(node_p_path.size()<node_q_path.size()){
            path_len=node_p_path.size();
        }
        else{
            path_len=node_q_path.size();
        }
        TreeNode *result=0;
        for(int i=0;i<path_len;++i){
            if(node_p_path[i]==node_q_path[i]){
                result=node_p_path[i];
            }
        }
        return result;
    }
private:
    void preOrder(TreeNode *node, //正在遍历的节点
                TreeNode *search, //待搜索的节点
                std::vector<TreeNode*> &path, //遍历时的节点路径栈
                std::vector<TreeNode*> &result, //最终搜索到节点search的路径结果
                int &finish){ //记录是否找到节点search的变量，未找到是0
        if(!node || finish){
            return;
        }
        path.push_back(node);
        if(node==search){
            finish=1;
            result=path;
        }
        preOrder(node->left,search,path,result,finish);
        preOrder(node->right,search,path,result,finish);
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
    TreeNode *result=solve.lowestCommonAncestor(&a,&b,&f);
    std::cout<<result->val;
    return 0;
}