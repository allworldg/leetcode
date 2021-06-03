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
            cur = cur->next;
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
