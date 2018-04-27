#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
// int main(){
//     int char_map[128]={0};
//     std::string str="abcdefgaaxxyyjjk";
//     for(int i=0;i<str.size();++i){
//         ++char_map[str[i]];
//     }
//     for(int i=0;i<128;++i){
//         if(char_map[i]>0){
//             printf("[%c][%d] : [%d]\n",i,i,char_map[i]);
//         }
//     }
//     return 0;
// }

/*
利用哈希函数，将关键字值（key）转换为整数再对表长取余，
哈希冲突，拉链法，将所有哈希函数结果相同的节点连接在同一个单链表中

*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};
int hash_func(int key,int table_len){
    return key%table_len;
}
void insert(ListNode *hash_table[],ListNode *node,int table_len){
    int hash_key=hash_func(node->val,table_len);
    node->next=hash_table[hash_key];  //使用头插法插入节点
    hash_table[hash_key]=node;
}
bool search(ListNode *hash_table[],int value,int table_len){
    int hash_key=hash_func(value,table_len);
    ListNode *head=hash_table[hash_key];
    while(head){
        if(head->val==value){
            return true;
        }
        head=head->next;
    }
    return false;
}

int main(){
    const int TABLE_LEN=11;
    ListNode *hash_table[TABLE_LEN]={0};
    std::vector<ListNode*> hash_node_vec;
    int test[8]={1,1,4,8,9,20,40,433};
    for(int i=0;i<8;++i){
        hash_node_vec.push_back(new ListNode(test[i]));
    }
    for(int i=0;i<hash_node_vec.size();++i){
        insert(hash_table,hash_node_vec[i],TABLE_LEN);
    }
    printf("Hash table:\n");
    for(int i=0;i<TABLE_LEN;++i){
        printf("[%d]:",i);
        ListNode *head=hash_table[i];
        while(head){
            printf("->%d",head->val);
            head=head->next;
        }
        printf("\n");
    }
    printf("\n");
    printf("Test search:\n");
    for(int i=0;i<10;++i){
        if(search(hash_table,i,TABLE_LEN)){
            printf("%d is in the hash table.\n",i);
        }
        else{
            printf("%d is not in the hash table.\n",i);
        }
    }
    for(int i=0;i<hash_node_vec.size();++i){
        delete hash_node_vec[i];
        hash_node_vec[i]=nullptr;
    }
    return 0;
}