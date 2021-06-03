/*
 * @lc app=leetcode.cn id=160 lang=c
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/* 方法一：思路：设两个链表从公共节点开始之后的链表长度为c，去除c之后各自链表长度为a和b,所以可以得出a+b+c = b+c+a，
    也就是说同时遍历两个链表，如果相等则返回，如果不相等则让每个链表指针都走完a+b+c的长度即可。*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    if (!headA || !headB)
    {
        return NULL;
    }
    struct ListNode *curA = headA;
    struct ListNode *curB = headB;
    while (curA != curB)
    {
        curA = curA == NULL ? headB : curA->next;//当a走完自己的指针还没
        curB = curB == NULL ? headA : curB->next;
    }
    return curA;
}
// @lc code=end
