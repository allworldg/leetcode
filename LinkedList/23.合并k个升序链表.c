/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个升序链表
 * 方法一：暴力合并，直接循环，两两合并即可。
 */

// @lc code=start
#include <stdio.h>
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
    while (cur1 != NULL)
    {
        cur->next = cur1;
        cur1 = cur1->next;
        cur = cur->next;
    }

    while (cur2 != NULL)
    {
        cur->next = cur2;
        cur2 = cur2->next;
        cur = cur->next;
    }
    return newHead->next;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    if (listsSize == 0)
    {
        return NULL;
    }
    if (listsSize == 1)
    {
        return lists[0];
    }
    struct ListNode *result = lists[0];
    for (int i = 1; i < listsSize; i++)
    {
        result = mergeTwoLists(result, lists[i]);
    }
    return result;
}

// @lc code=end
