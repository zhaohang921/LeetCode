/*
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: []

解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
*/

/*
图的宽度遍历

多条路径

*/
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<utility>
#include<algorithm>
using namespace std;

struct Qitem{
    std::string node; //搜索节点
    int parent_pos;  //前驱节点在队列中的位置
    int step;   //到达当前节点的步数
    Qitem(std::string _node, int _parent_pos, int _step)
         : node(_node), parent_pos(_parent_pos), step(_step){}

};
class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        std::map<std::string, std::vector<std::string> > graph;
        construct_graph(beginWord, wordList, graph);
        std::vector<Qitem> Q;
        std::vector<int> end_word_pos; //endWord在搜索队列的位置
        BFS_graph(beginWord, endWord, graph, Q, end_word_pos);
        std::vector<std::vector<std::string> > result;
        for(int i = 0; i < end_word_pos.size(); ++i){
            int pos = end_word_pos[i];
            std::vector<std::string> path;
            while(pos != -1){       //从endWord到beginWord将路径上的节点值push进入path
                path.push_back(Q[pos].node);
                pos = Q[pos].parent_pos;
            }
            result.push_back(std::vector<std::string>());
            for(int j = path.size() - 1; j >= 0; --j){
                result[i].push_back(path[j]);
            }
        }
        return result;
    }

private:
    void BFS_graph(std::string &beginWord, std::string &endWord,
                   std::map<std::string, std::vector<std::string> > &graph,
                   std::vector<Qitem> &Q, //使用vector实现的队列，可保存所有信息
                   std::vector<int> &end_word_pos){  //终点endWord所在队列的位置下标
        std::map<std::string, int> visit; //<单词，步数>
        int min_step = 0; //到达endWord的最小步数
        Q.push_back(Qitem(beginWord, -1, 1)); //起始单词的前驱为-1
        visit[beginWord] = 1; //标记其起始单词步数为1
        int front = 0; //队列头指针front，指向vector表示的队列头
        while (front != Q.size()){  
            const std::string &node = Q[front].node;
            int step = Q[front].step;
            if (min_step != 0 && step > min_step){
                break;
            }
            if (node == endWord){
                min_step = step;
                end_word_pos.push_back(front);
            }
            const std::vector<std::string> &neighbors = graph[node];
            for (int i = 0; i < neighbors.size(); ++i){
                if (visit.find(neighbors[i]) == visit.end() ||
                        visit[neighbors[i]] == step + 1){
                    Q.push_back(Qitem(neighbors[i], front, step + 1));
                    visit[neighbors[i]] = step + 1; //标记到达邻接点neighbors[i]的最小步数
                }
            }
            ++front;
        }
    }
    void construct_graph(std::string &beginWord, std::vector<std::string> &wordList,
                         std::map<std::string, std::vector<std::string> > &graph){
        int has_begin_word = 0;
        for (int i = 0; i < wordList.size(); ++i){
            if (wordList[i] == beginWord){
                has_begin_word =1 ;
            }
            graph[wordList[i]] = std::vector<std::string>();
        }
        for (int i = 0; i < wordList.size(); ++i){
            for (int j = i + 1; j < wordList.size(); ++j){
                if (connect(wordList[i], wordList[j])){  //对任意两个单词，如果只相差一个字符，则将其相连
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
            if (has_begin_word == 0 && connect(beginWord, wordList[i])){
                graph[beginWord].push_back(wordList[i]);
            }
        }
    }
    bool connect(const std::string &word1, const std::string &word2){
        int cnt = 0; //记录word1和word2中不相等的字符的个数
        for (int i = 0; i < word1.length(); ++i){
            if (word1[i] != word2[i]){
                ++cnt;
            }
        }
        return cnt == 1;
    }

};




int main(){
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList;
    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");
    Solution solve;
    std::vector<std::vector<std::string> > result = solve.findLadders(beginWord, endWord, wordList);
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j){
            printf("[%s] ", result[i][j].c_str());
        }
        std::cout<<std::endl;
    }


    return 0;
}