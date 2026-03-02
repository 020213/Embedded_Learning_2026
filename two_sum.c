#include<studio.h>
#include<string.h>

// 完成Leetcode两数之和

// 构建哈希表
typedef struct HashTable{
    int key;
    int val;
    UT_hash_handle_hh;  //使用hash的必要条件
}HashTable;

HashTable* HashTables;  //创建哈希表的头节点

HashTable* find(int ikey){   //在哈希表里面寻找特定的数
    HashTable* tmp; //查找指针
    HASH_FIND_INT(hashTables,&ikey,tmp);    //hash函数里面包含的方法，在hash表中找到对应的值，返回它的地址，若没有则返回NULL
    return tmp;     //这里返回的是指针地址
}  

void Insert(int ikey, int ival){
    HashTable* it = find(ikey);     //这一步是先检查这个值是否已经在hash表里，有就不加，没有就加
    if(it == NULL){
        HashTable* tmp = (HashTable*)malloc(sizeof(HashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_INT(hashTables, key, tmp);
    }else{
        it->val = ival;
    }
}

int* twoSum(int* nums, int sumsSize, int target, int* returnSize){
    HashTables = NULL;
    for(int i = 0; i < sumsSize; i++){
        HashTable* it = find(nums[i]);
        if(it != NULL){
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        *returnSize = 0;
        return NULL;
    }
}