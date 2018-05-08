/*
现在你总共有 n 门课需要选，记为 0 到 n - 1。

一些课程在修之前需要先修另外的一些课程，比如要学习课程 0 你需要先学习课程 1 ，表示为: [0,1]
给定 n 门课以及他们的先决条件，判断是否可能完成所有课程？

例如：

2, [[1,0]]
总共有2门课程可供选择。选取课程 1之前，你需要完成课程 0。所以这是可能的。

2, [[1,0],[0,1]]
总共有 2 门课程可供选择。要参加课程 1，你需要先完成​课程 0，并且选取课程 0之前，你还应先完成课程 1。所以这是不可能的。
注意:

输入先决条件是由边缘列表表示的图形，而不是邻接矩阵。详细了解 图的表示法。
你可以假定输入先决条件中没有重复的边。
点击以显示更多。

提示:

这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能采取所有课程。
通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
拓扑排序也可以通过 BFS 完成。
*/

/*
思路：
n个课程，他们之间有m个以来关系，可以看成顶点个数为n，边个数为m的有向图
若有向图无环，则可以完成全部课程，否则不能
判断图是否有环
在深度优先搜索时，如果正在搜索某一顶点，又回到了该顶点，即证明图有环

*/

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<algorithm>
#include<assert.h>
using namespace std;

struct GraphNode{
    int label;
    vector<GraphNode*> neighbors;
    GraphNode(int x) : label(x){}
};

//方法一：深度搜索
class Solution1 {
public:
    //pair<1, 2>  课程1依赖课程2
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<GraphNode*> graph;
        vector<int> visit;   //节点访问状态，-1没有访问过，0表示正在访问，1表示已经访问完成
        for(int i=0;i<numCourses;++i){
            graph.push_back(new GraphNode(i));
            visit.push_back(-1);
        }
        for(int i=0;i<prerequisites.size();++i){
            GraphNode *begin=graph[prerequisites[i].second];
            GraphNode *end=graph[prerequisites[i].first];
            begin->neighbors.push_back(end); //课程2指向课程1
        }
        for(int i=0;i<graph.size();++i){
            if(visit[i]==-1 && !DFS_graph(graph[i],visit)){ //如果节点没访问过，进行DFS，如果DFS遇到环，返回无法完成
                return false;
            }
        }
        for(int i=0;i<numCourses;++i){
            delete graph[i];
        }
        return true;
    }
private:
    bool DFS_graph(GraphNode *node,vector<int> &visit){
        visit[node->label]=0;
        for(int i=0;i<node->neighbors.size();++i){
            if(visit[node->neighbors[i]->label]==-1){
                if(DFS_graph(node->neighbors[i],visit)==0){  //有环的情况一
                    return false;
                }
            }
            else if(visit[node->neighbors[i]->label]==0){   //有环的情况二
                return false;
            }
        }
        visit[node->label]=1;
        return true;
    }
};

/*
宽度搜索时，只将入度为0的点添加至队列。当完成一个顶点的搜索（从队列取出），它指向的所有顶点入度都减1，
若此时某顶点入度为0则添加至队列，若完成宽度搜索后，所有的点入度都为0，则图无环

*/
class Solution2{
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<GraphNode*> graph;
        vector<int> degree; //入度数组
        for(int i=0;i<numCourses;++i){
            degree.push_back(0);
            graph.push_back(new GraphNode(i));
        }
        for(int i=0;i<prerequisites.size();++i){
            GraphNode *begin=graph[prerequisites[i].second];
            GraphNode *end=graph[prerequisites[i].first];
            begin->neighbors.push_back(end);
            ++degree[prerequisites[i].first]; //课程1的入度++
        }
        queue<GraphNode*> Q;
        for(int i=0;i<numCourses;++i){
            if(degree[i]==0){
                Q.push(graph[i]);
            }
        }
        while(!Q.empty()){
            GraphNode *node=Q.front();
            Q.pop();
            for(int i=0;i<node->neighbors.size();++i){
                --degree[node->neighbors[i]->label];
                if(degree[node->neighbors[i]->label]==0){
                    Q.push(node->neighbors[i]);
                }
            }
        }
        for(int i=0;i<graph.size();++i){
            delete graph[i];
        }
        for(int i=0;i<degree.size();++i){
            if(degree[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    vector<pair<int,int> > prerequisites;
    prerequisites.push_back(make_pair(1,0));
    prerequisites.push_back(make_pair(2,0));
    prerequisites.push_back(make_pair(3,1));
    prerequisites.push_back(make_pair(3,2));
    Solution2 solve;
    cout<<solve.canFinish(4,prerequisites);

    return 0;
}