/*
Trie树一般指字典树
又称单词查找树，Trie树，是一种树形结构，是一种哈希树的变种。
典型应用是用于统计，排序和保存大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。
它的优点是：利用字符串的公共前缀来减少查询时间，最大限度地减少无谓的字符串比较，查询效率比哈希树高。


Trie 树是一种以信息换时间的数据结构，其查询的复杂度为O(n)

Trie 的单数组实现能够达到最佳的性能，但是其空间利用率极低，是典型的以空间换时间的实现

Trie 树的哈希实现可以很好的平衡性能需求和空间开销，同时能够实现词典的实时更新

Trie 树的双数组实现基本可以达到单数组实现的性能，同时能够大幅降低空间开销；但是其难以做到词典的实时更新

对双数组 Trie 进行 tail 改进可以明显改善词典的构建速度，同时进一步减少空间开销



*/
#include<iostream>
#include<string>
#include<vector>


// using namespace std;

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
//前序遍历每个节点
void preOrder_trie(TrieNode *node, int layer);
//获取全部单词，深度搜索
void get_all_word_from_trie(TrieNode *node, std::string &word, std::vector<std::string> &word_list);

int main() {
    TrieNode root;
    TrieNode n1;
    TrieNode n2;
    TrieNode n3;
    root.child['a' - 'a'] = &n1;
    root.child['b' - 'a'] = &n2;
    root.child['e' - 'a'] = &n3;
    n2.is_end = true;

    TrieNode n4;
    TrieNode n5;
    TrieNode n6;
    n1.child['b' - 'a'] = &n4;
    n2.child['c' - 'a'] = &n5;
    n3.child['f' - 'a'] = &n6;

    TrieNode n7;
    TrieNode n8;
    TrieNode n9;
    TrieNode n10;
    n4.child['c' - 'a'] = &n7;
    n4.child['d' - 'a'] = &n8;
    n5.child['d' - 'a'] = &n9;
    n6.child['g' - 'a'] = &n10;
    n7.is_end = true;
    n8.is_end = true;
    n9.is_end = true;
    n10.is_end = true;

    TrieNode n11;
    n7.child['d' - 'a'] = &n11;
    n11.is_end = true;

    // preOrder_trie(&root, 0);
    std::string word;
    std::vector<std::string> word_list;
    get_all_word_from_trie(&root, word, word_list);
    for (auto i : word_list){
        std::cout << i << std::endl;
    }
    return 0;
}

void preOrder_trie (TrieNode *node, int layer){
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i){
        if (node->child[i]){
            for (int j = 0; j < layer; ++j){
                printf("---");
            }
            printf("%c", i + 'a');
            if (node->child[i]->is_end){
                printf("(end)");
            }
            printf("\n");
            preOrder_trie(node->child[i], layer + 1);
        }
    }
}

void get_all_word_from_trie (TrieNode *node, std::string &word, std::vector<std::string> &word_list){
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i){
        if (node->child[i]){
            word.push_back(i + 'a'); //字符入栈
            if (node->child[i]->is_end){
                word_list.push_back(word);
            }
            get_all_word_from_trie(node->child[i], word, word_list);
            word.erase(word.length() - 1, 1);
        }
    }
} 