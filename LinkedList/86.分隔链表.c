/*
 * @lc app=leetcode.cn id=86 lang=c
 *
 * [86] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 1、新增两个虚拟头节点，分别连接大于x和小于x的结点
   2、遍历整个链表，将每个结点连接到两个虚拟结点上
   3、将大于x的链表连接到小于链表的尾部 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x)
{
    if(head==NULL){
        return NULL;
    }
    struct ListNode *moreList = malloc(sizeof(struct ListNode));
    struct ListNode *lessList = malloc(sizeof(struct ListNode));
    struct ListNode *moreCur = moreList;
    struct ListNode *lessCur = lessList;
    moreList->val = -1;
    moreList->val = -1;

    while(head!=NULL){
        if(head->val<=x){
            lessCur->next = head;
            lessCur = head;
        }else{
            moreCur->next = head;
            moreCur = head;
        }
        head = head->next;
    }
    lessCur->next = moreList->next;
    return lessList;
}
// @lc code=end
