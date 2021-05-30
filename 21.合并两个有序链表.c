/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *newHead = malloc(sizeof(struct ListNode));
    newHead->next = NULL;
    struct ListNode *cur = newHead;
    struct ListNode *cur1 = l1;
    struct ListNode *cur2 = l2;

    while (cur1 != NULL && cur2 != NULL)
    {
        if (cur1->val < cur2->val)
        {
            cur->next = cur1;
            cur1 = cur1->next;
            cur = cur->next;
        }
        else
        {
            cur->next = cur2;
            cur2 = cur2->next;
            cur = cur->next;
        }
    }
        while (cur1!= NULL)
        {
            cur->next = cur1;
            cur1 = cur1->next;
            cur = cur->next;
        }

        while (cur2 != NULL){
            cur->next = cur2;
            cur2 = cur2->next;
            cur = cur->next;
        }
        return newHead->next;
    
}
// @lc code=end
