/*
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。
开始坐标总是小于结束坐标。平面内最多存在104个气球。

一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，
若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，
则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。
我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

Example:
输入:
[[10,16], [2,8], [1,6], [7,12]]
输出:
2
解释:
对于该样例，我们可以在x = 6（射爆[2,8],[1,6]两个气球）和 x = 11（射爆另外两个气球）。
*/

/*
思路：贪心
射穿气球的同时，尽可能击穿其他更多的气球。
*/

#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(const pair<int,int> &a,const pair<int,int> &b){
        return a.first<b.first;
    }
    int findMinArrowShots(vector<pair<int, int> >& points) {
        if(points.size()==0) return 0;
        sort(points.begin(),points.end(),cmp);
        int shoot_num=1;
        int shoot_begin=points[0].first;
        int shoot_end=points[0].second;
        for(int i=1;i<points.size();++i){
            if(points[i].first<=shoot_end){
                shoot_begin=points[i].first;
                if(shoot_end>points[i].second){
                    shoot_end=points[i].second;
                }
            }
            else{
                ++shoot_num;
                shoot_begin=points[i].first;
                shoot_end=points[i].second;
            }
        }
        return shoot_num;
    }
};