/*
 * @lc app=leetcode.cn id=203 lang=c
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 思路：1、创建哑结点，连接head
 *      2、从哑节点开始循环，如果下一个节点值符合条件就删除，指向再下一个节点
 *      3、如果不符合，则移动当前指针到下一个节点。
 */
#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode *dummyNode = malloc(sizeof(struct ListNode));
    dummyNode->val = 0;
    dummyNode->next = head;
    struct ListNode *cur = dummyNode;
    while (cur->next)
    {
        if (cur->next->val == val)
        {
            cur->next = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    return dummyNode->next;
}
// @lc code=end
