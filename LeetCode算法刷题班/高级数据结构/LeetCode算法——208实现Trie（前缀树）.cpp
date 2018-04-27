/*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个方法。

注意:
你可以假设所有的输入都是小写字母 a-z。
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
private:
    TrieNode *new_node(){
        TrieNode *node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
    std::vector<TrieNode *> _node_vec;
    TrieNode _root;
};



class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        _trie_tree.insert(word.c_str());
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return _trie_tree.search(word.c_str());
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return _trie_tree.startsWith(prefix.c_str());
    }

private:
    TrieTree _trie_tree;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main(){
    Trie trie;
    trie.insert("abcde");
    printf("%d\n", trie.search("abc"));
    printf("%d\n", trie.search("da"));
    printf("%d\n", trie.search("abcde"));
    printf("%d\n", trie.startsWith("abc"));
    printf("%d\n", trie.startsWith("a"));
    printf("%d\n", trie.startsWith("bac"));

    return 0;
}