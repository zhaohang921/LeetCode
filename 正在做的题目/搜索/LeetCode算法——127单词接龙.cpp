/*
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。
*/

/*
图的宽度遍历
*/
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<utility>
#include<algorithm>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::map<std::string, std::vector<std::string> > graph;
        construct_graph(beginWord, wordList, graph);
        return BFS_graph(beginWord, endWord, graph);
    }

private:
    int BFS_graph(std::string &beginWord, std::string &endWord,
                  std::map<std::string, std::vector<std::string> > &graph){
        std::queue<std::pair<std::string, int> > Q;
        std::set<std::string> visit;
        Q.push(std::make_pair(beginWord, 1));  //起始点，起始步数为1
        visit.insert(beginWord);
        while (!Q.empty()){ //只要队列不空，就不断搜索
            std::string node = Q.front().first;
            int step = Q.front().second;
            Q.pop();
            if (node == endWord){  //找到终点，返回步数
                return step;
            }
            const std::vector<std::string> &neighbors = graph[node];
            for (int i = 0; i < neighbors.size(); ++i){
                if (visit.find(neighbors[i]) == visit.end()){
                    Q.push(std::make_pair(neighbors[i], step+1));
                    visit.insert(neighbors[i]); //
                }
            }
        }
        return 0;
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

    void construct_graph(std::string &beginWord, std::vector<std::string> &wordList,
                         std::map<std::string, std::vector<std::string> > &graph){
        wordList.push_back(beginWord);
        for (int i = 0; i < wordList.size(); ++i){
            graph[wordList[i]] = std::vector<std::string>();
        }
        for (int i = 0; i < wordList.size(); ++i){
            for (int j = i+1; j < wordList.size(); ++j){
                if (connect(wordList[i], wordList[j])){  //对任意两个单词，如果只相差一个字符，则将其相连
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
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
    int result=solve.ladderLength(beginWord, endWord, wordList);
    printf("result = %d\n", result);


    return 0;
}