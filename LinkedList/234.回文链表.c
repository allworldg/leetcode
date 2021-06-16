/*
 * @lc app=leetcode.cn id=234 lang=c
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 
    方法一：创建数组，存放所有节点，然后通过数组两侧向中间靠拢进行判断
    时间复杂度o（n）遍历n个元素，空间复杂度o（n）存储n个结点。

    方法二：采用快慢指针，快指针速度是满指针两倍，当快指针走完，慢指针正好到中间，然后将后面一半的链表倒置，然后进行比较
    时间复杂度o(n)遍历n个元素，空间复杂度o(1),原地操作。
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
bool isPalindrome(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    int arr[500001];
    int index = 0;
    struct ListNode *cur = head;
    while (cur->next)
    {
        cur = cur->next;
        arr[index] = cur->val;
        index++;
    }
    int i = 0;
    int j = index - 1;
    int end = j / 2;
    while (i <= end)
    {
        if (arr[i] != arr[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *pre = NULL;
    while (head)
    {
        struct ListNode *next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

bool isPalindrome2(struct ListNode *head)
{
    if (head == NULL)
    {
        return false;
    }
    struct ListNode *quick = head;
    struct ListNode *slow = head;
    while (quick->next && quick->next->next)
    {
        quick = quick->next->next;
        slow = slow->next;
    }
    quick = reverse(slow->next);
    slow = head;
    while (quick != NULL)
    {
        if (slow->val != quick->val)
        {
            return false;
        }
        quick = quick->next;
        slow = slow->next;
    }
    return true;
}
// @lc code=end
