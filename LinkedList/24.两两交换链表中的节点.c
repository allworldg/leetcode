/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start

struct ListNode
{
    int val;
    struct ListNode *next;
};

#include <stdio.h>
#include <stdlib.h>

struct ListNode *swapPairs(struct ListNode *head)
{
    if(head==NULL){
        return NULL;
    }
    struct ListNode *dymmicNode = malloc(sizeof(struct ListNode));
    dymmicNode->next = head;
    struct ListNode *cur = dymmicNode;
    while(cur->next){
        struct ListNode *pre = cur;
        cur = cur->next;
        if(cur->next==NULL){
            break;//如果下一个没有，说明已经到尾部
        }
        struct ListNode *next = cur->next;
        cur -> next = next->next;
        next->next = cur;
        pre->next = next;
    }
    return dymmicNode->next;
}
// @lc code=end
