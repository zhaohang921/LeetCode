/*
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

         1
        / \
       2   5
      / \   \
     3   4   6
将其展开为：

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

*/

/*
思路：
left=NULL,right=next
怎么就地转换???

*/

#include<iostream>
#include<vector>
#include<string>
#include<set>
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
 
//方法一：没有就地
class Solution1 {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> node_vec;
        preOrder(root,node_vec);
        for(int i=1;i<node_vec.size();++i){
            node_vec[i-1]->left=NULL;
            node_vec[i-1]->right=node_vec[i];
        }
    }
private:
    void preOrder(TreeNode *node,vector<TreeNode*> &node_vec){
        if(!node){
            return;
        }
        node_vec.push_back(node);
        preOrder(node->left,node_vec);
        preOrder(node->right,node_vec);
    }
};

//方法二：就地
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *last=nullptr;
        preOrder(root,last);
    }
private:
    void preOrder(TreeNode *node,TreeNode *&last){
        if(!node){
            return;
        }
        if(!node->left && !node->right){ //如果该节点是叶节点
            last=node; //该节点就是最后一个节点
            return;    //返回
        }
        TreeNode *left=node->left;  //备份左右指针
        TreeNode *right=node->right;
        TreeNode *left_last=nullptr;  //左右子树最后一个节点
        TreeNode *right_last=nullptr;
        if(left){                     //若有左子树，递归将左子树转换成单链表
            preOrder(left,left_last);
            node->left=nullptr;
            node->right=left;
            last=left_last;
        }
        if(right){
            preOrder(right,right_last);
            if(left_last){
                left_last->right=right; //把左右链表连起来
            }
            last=right_last;
        }
    }
};


int main(){
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);

    a.left=&b;
    a.right=&c;
    b.left=&d;
    b.right=&e;
    c.right=&f;
    Solution solve;
    solve.flatten(&a);
    TreeNode *head=&a;
    while(head){
        if(head->left){
            cout<<"error"<<endl;
        }
        cout<<"["<<head->val<<"]";
        head=head->right;
    }
    cout<<endl;
    return 0;
}