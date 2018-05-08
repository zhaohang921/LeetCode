/*
班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。
如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。
如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。

示例 1:

输入: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2 
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。
示例 2:

输入: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。
注意：

N 在[1,200]的范围内。
对于所有学生，有M[i][i] = 1。
如果有M[i][j] = 1，则有M[j][i] = 1。
*/

#include<string>
#include<map>
#include<vector>
#include<queue>
#include<utility>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution1 {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> visit(M.size(), 0);
        int count = 0;
        for (int i = 0; i < M.size(); ++i){
            if (visit[i] == 0){
                DFS_graph(i, M, visit);
                ++count;
            }
        }
        return count;
    }

private:
    void DFS_graph(int u, vector<vector<int>>& graph, vector<int>& visit){
        visit[u] = 1;
        for (int i = 0; i < graph[u].size(); ++i){
            if (graph[u][i] == 1 && visit[u] == 0){
                DFS_graph(i, graph, visit);
            }
        }
    }
};

class DisjointSet{
public:
    DisjointSet(int n) : _count(n){
        for (int i = 0; i < n; ++i){
            _id.push_back(i);
            _size.push_back(1);
        }
    }
    int find(int p){
        while (p != _id[p]){
            _id[p] = _id[_id[p]]; //父节点指向父节点的父节点
            p = _id[p];
        }
        return p;
    }
    void union_(int p, int q){
        int i = find(p);
        int j = find(q);
        if (i == j){
            return;
        }
        //小的向大的合并
        if (_size[i] < _size[j]){
            _id[i] = j;
            _size[j] += _size[i];
        } else {
            _id[j] = i;
            _size[i] += _size[j];
        }
        --_count;
    }
    void print_set(){
        printf("元素: ");
        for (int i = 0; i < _id.size(); ++i){
            printf("%d ", i);
        }
        cout<<endl;
        cout<<"集合: ";
        for (int i = 0; i < _id.size(); ++i){
            printf("%d ", _id[i]);
        }
        cout<<endl;
    }
    int count(){
        return _count;
    }
private:
    std::vector<int> _id;
    std::vector<int> _size;
    int _count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        DisjointSet disjoint_set(M.size());
        for (int i = 0; i < M.size(); ++i){
            for (int j = i + 1; j < M.size(); ++j){
                if (M[i][j]){
                    disjoint_set.union_(i,j);
                }
            }
        }
        return disjoint_set.count();
    }
};