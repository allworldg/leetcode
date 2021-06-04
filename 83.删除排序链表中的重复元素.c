/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * 简单介绍，因为链表是排序过的，所以只需要将相邻节点进行判断值是否相等即可
 * 注意相等的时候将下一个节点往前移动，同时将cur向后移动达到删除并且继续判断的操作。
 */

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode *pre = malloc(sizeof(struct ListNode));
    pre->val = -1;
    pre->next = head;
    struct ListNode *cur = head;
    while (cur)
    {
        if (pre->val == cur->val)
        {
            pre->next = cur->next;
            cur = cur->next;//不要忘记这一步，否则死循环。
        }
        else
        {
            cur = cur->next;
            pre = pre->next;
        }
    }
    return head;
}
// @lc code=end
