/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 * 方法1：
 *  1、遍历链表，获得整个长度
 *  2、根据倒数获得正数位置。
 *  3、遍历链表，删除结点
 * 
 * 方法2：采用双指针
 * 1、初始化双指针和虚拟头结点
 * 2、快指针开始遍历，当快指针移动距离为N+1时，慢指针开始移动（快慢指针之间距离差N，当快指针到达结尾，慢指针正好到达目标结点的前一个)。
 * 3、进行删除。
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};
// 方法一，暴力遍历两次链表
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode *dymmicNode = malloc(sizeof(struct ListNode));
    dymmicNode->val = -1;
    dymmicNode->next = head;
    struct ListNode *cur = dymmicNode;
    int length = 0;
    while (cur->next)
    {
        ++length;
        cur = cur->next;
    }
    cur = dymmicNode;
    int index = length - n; //获得目标位置的前一个结点位置
    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
    }
    cur->next = cur->next->next;
    return dymmicNode->next;
}

struct ListNode *removeNthFromEnd2(struct ListNode *head, int n)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode *dymmicNode = malloc(sizeof(struct ListNode));
    dymmicNode->next = head;
    dymmicNode->val = -1;
    struct ListNode *quickNode = dymmicNode;
    struct ListNode *slowNode = dymmicNode;
    int index = 0;
    while (quickNode->next)
    {
        quickNode = quickNode->next;
        index++;
        if (index >= n + 1)
        {
            slowNode = slowNode->next;
        }
        slowNode->next = slowNode->next->next;
    }
    return dymmicNode->next;
}
// @lc code=end
