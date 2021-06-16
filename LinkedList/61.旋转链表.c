/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 思路：采用快慢指针获得需要反转的部分，然后将尾部结点连接到头结点，慢指针清空next变成新结尾即可 */
/* 实现：1、判断异常情况，当链表为空返回空值，当链表长度为1或者反转次数为0直接返回链表
        2、遍历链表获得长度，算出有效反转次数，此时还需判断如果有效次数为0则直接返回head
        3、设置双指针，使双指针之间始终间隔k（注意间隔为k，也就是慢指针到快指针的实际距离为k+1，例如1-10间隔为9
        4、将慢指针的next设置为null，成为新的末端，将快指针的next设置为head。 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (k == 0 || head->next == NULL)
    {
        return head;
    }

    int length = 0;
    struct ListNode *cur = head;
    while (cur)
    {
        cur = cur->next;
        ++length;
    }

    k = k % length;
    if(k==0){
        return head;
    }
    struct ListNode *slow = head;
    struct ListNode *quick = head;
    int index = 0;
    while (quick->next)
    {
        if (index >= length)
        {
            slow = slow->next;
        }
        quick = quick->next;
        ++index;
    }
    struct ListNode *newHead = slow->next;
    slow->next = NULL;
    quick->next = head;
    return newHead;
}
// @lc code=end
