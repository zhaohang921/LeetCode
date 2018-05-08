/*
设计一个支持以下两个操作的数据结构：

void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 意味着它可以代表任何一个字母。

例如：

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
注意事项:

你可以假设所有单词都是由小写字母 a-z 组成的。

*/

/*

*/
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
#define TRIE_MAX_CHAR_NUM 26


struct TrieNode{
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode() : is_end(false) {
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i){
            child[i] = 0;
        }
    }
};

class TrieTree{
public:
    TrieTree(){}
    ~TrieTree(){
        for (int i = 0; i < _node_vec.size(); ++i){
            delete _node_vec[i];
        }
    }
    //将单词插入至trie树
    void insert (const char *word){
        TrieNode *ptr = &_root;
        while (*word){  //一个一个字符遍历
            int pos = *word - 'a';
            if (!ptr->child[pos]){
                ptr->child[pos] = new_node();
            }
            ptr = ptr->child[pos];
            ++word;  //下一个字符
        }
        ptr->is_end = true;
    }
    //单词是否在trie树中
    bool search (const char *word){
        TrieNode *ptr = &_root;
        while (*word){
            int pos = *word - 'a';
            if (!ptr->child[pos]){
                return false;
            }
            ptr = ptr->child[pos];
            ++word;
        }
        return ptr->is_end; //单词是不是结束了
    }
    bool startsWith (const char *prefix){
        TrieNode *ptr = &_root;
        while (*prefix){
            int pos = *prefix - 'a';
            if (!ptr->child[pos]){
                return false;
            }
            ptr = ptr->child[pos];
            ++prefix;
        }
        return true;
    }
    TrieNode* root(){
        return &_root;
    }
    bool search_trie(TrieNode *node, const char *word){
        if (*word == '\0'){
            return node->is_end;
        }
        if (*word == '.'){
            for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i){
                if (node->child[i] && search_trie(node->child[i], word + 1)){
                    return true;                   
                }
            }
        } else {
            int pos = *word - 'a';
            if (node->child[pos] && search_trie(node->child[pos], word + 1)){
                return true;
            }
        }
        return false;
    }
private:
    TrieNode *new_node(){
        TrieNode *node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
    std::vector<TrieNode *> _node_vec;
    TrieNode _root;
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        _trie_tree.insert(word.c_str());
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
    }
private:
    TrieTree _trie_tree;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */