/*
给定一个m x n的矩阵，其中的值均为正整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。

说明:

m 和 n 都是小于110的整数。每一个单位的高度都大于0 且小于 20000。

示例：

给出如下 3x6 的高度图:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

返回 4。
*/

/*
带优先级的广度优先搜索
想象水流在最外层，慢慢上升
搜索队列使用优先级队列（堆），越低矮的点优先级越高（小根堆）

*/
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

struct Qitem{
    int x;
    int y;
    int h;
    Qitem(int _x, int _y, int _h) : x(_x), y(_y), h(_h){}
};
struct cmp{
    bool operator()(const Qitem &a, const Qitem &b){
        return a.h > b.h;
    }
};
class Solution {
public:
    int trapRainWater(vector<vector<int> >& heightMap) {
        std::priority_queue<Qitem, std::vector<Qitem>, cmp> Q;
        if (heightMap.size() < 3 || heightMap[0].size() < 3){
            return 0;
        }
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        std::vector<std::vector<int> > mark;
        for (int i = 0; i < rows; ++i){
            mark.push_back(std::vector<int> ());
            for (int j = 0; j < cols; ++j){
                mark[i].push_back(0);
            }
        }
        //把第一行和最后一行添加至优先级队列，并做标记
        for (int i = 0; i < rows; ++i){
            Q.push(Qitem(i, 0, heightMap[i][0]));
            mark[i][0] = 1;
            Q.push(Qitem(i, cols-1, heightMap[i][cols-1]));
            mark[i][cols-1] = 1;
        }
        //把第一列和最后一列添加至优先级队列，并做标记
        for (int i = 1; i < cols - 1; ++i){  //四个角上的已经添加到队列中了，不要重复添加
            Q.push(Qitem(0, i, heightMap[0][i]));
            mark[0][i] = 1;
            Q.push(Qitem(rows - 1, i, heightMap[rows - 1][i]));
            mark[rows - 1][i] = 1;
        }

        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        int result = 0;
        while(!Q.empty()){
            int x = Q.top().x;
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();
            for (int i = 0; i < 4; ++i){
                int newx = x + dx[i];
                int newy = y + dy[i];
                //超出边界
                if (newx < 0 || newx >= rows || newy < 0 || newy >= cols || mark[newx][newy]){
                    continue;
                }
                //当前点的高度高于拓展点
                if (h > heightMap[newx][newy]){
                    result += h - heightMap[newx][newy];
                    heightMap[newx][newy] = h;
                }
                Q.push(Qitem(newx, newy, heightMap[newx][newy]));
                mark[newx][newy] = 1;
            }
        }
        return result;
    }

};

int main(){
    // std::priority_queue<Qitem, std::vector<Qitem>, cmp> Q;
    // Q.push(Qitem(0, 0, 5));
    // Q.push(Qitem(1, 3, 2));
    // Q.push(Qitem(5, 2, 4));
    // Q.push(Qitem(0, 1, 8));
    // Q.push(Qitem(6, 7, 1));
    // while (!Q.empty()){
    //     int x = Q.top().x;
    //     int y = Q.top().y;
    //     int h = Q.top().h;
    //     printf("x = %d y = %d h = %d\n", x, y, h);
    //     Q.pop();
    // }


    int test[][10] = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };
    std::vector<std::vector<int> > heightMap;
    for (int i = 0; i < 3; ++i){
        heightMap.push_back(std::vector<int> ());
        for (int j = 0; j < 6; ++j){
            heightMap[i].push_back(test[i][j]);
        }
    }
    Solution solve;
    printf("%d\n",solve.trapRainWater(heightMap));
    


    return 0;
}