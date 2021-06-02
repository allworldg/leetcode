/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 思路：反转两个链表，然后依次遍历相加，有进位时设置一个进位flag ，当最高位有flag时，新增一个结点*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    if (!l1 && !l2)
    {
        return NULL;
    }   
    struct ListNode *list = malloc(sizeof(struct ListNode));
    list->val = 0;
    list->next = NULL;
    struct ListNode *cur = list;
    int flag = 0;
    while (l1 && l2)
    {
        int result = l1->val + l2->val + flag;
        if (result >= 10)
        {
            flag = 1;
            result = result % 10;
        }
        else
        {
            flag = 0;
        }
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = result;
        cur->next = newNode;
        cur = cur->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1)
    {
        int result = l1->val + flag;
        if (result >= 10)
        {
            flag = 1;
            result = result % 10;
        }
        else
        {
            flag = 0;
        }
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = result;
        cur->next = newNode;
        cur = cur->next;
        l1 = l1->next;
    }

    while (l2)
    {
        int result = l2->val + flag;
        if (result >= 10)
        {
            flag = 1;
            result = result % 10;
        }
        else
        {
            flag = 0;
        }
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = result;
        cur->next = newNode;
        cur = cur->next;
        l2 = l2->next;
    }
    if (flag)
    {
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->next = cur->next;
        newNode->val = 1;
        cur->next = newNode;
    }
    return list->next;
}

// @lc code=end

// @lc code=end
